// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2019 The PIVX developers
// Copyright (c) 2019-2020 The TensorCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>
#include <limits>


struct SeedSpec6 {
	uint8_t addr[16];
	uint16_t port;
};

#include "chainparamsseeds.h"

/**
* Main network
*/

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
	// It'll only connect to one or two seed nodes because once it connects,
	// it'll get a pile of addresses with newer timestamps.
	// Seed nodes are given a random 'last seen time' of between one and two
	// weeks ago.
	const int64_t nOneWeek = 7 * 24 * 60 * 60;
	for (unsigned int i = 0; i < count; i++) {
		struct in6_addr ip;
		memcpy(&ip, data[i].addr, sizeof(ip));
		CAddress addr(CService(ip, data[i].port));
		addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
		vSeedsOut.push_back(addr);
	}
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
boost::assign::map_list_of
(0, uint256("0x00000a505610347e04efaa857a6421b8abe3b5c814b0ae8a39b8e4fcfccc68f6"))
;
static const Checkpoints::CCheckpointData data = {
	&mapCheckpoints,
	1588860000, // * UNIX timestamp of last checkpoint block
	0,    // * total number of transactions between genesis and last checkpoint
				//   (the tx=... number in the SetBestChain debug.log lines)
	2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
boost::assign::map_list_of
(0, uint256("0x001"))
;
static const Checkpoints::CCheckpointData dataTestnet = {
	&mapCheckpointsTestnet,
	1588860000,
	0,
	250 };

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
	&mapCheckpointsRegtest,
	1588860000,
	0,
	100 };

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
	assert(this);

	static CBigNum bnDecModulus = 0;
	if (!bnDecModulus)
		bnDecModulus.SetDec(zerocoinModulus);
	static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

	return &ZCParamsDec;
}

bool CChainParams::HasStakeMinAgeOrDepth(const int contextHeight, const uint32_t contextTime,
	const int utxoFromBlockHeight, const uint32_t utxoFromBlockTime) const
{
	// before stake modifier V2, the age required was 60 * 60 (1 hour) / not required on regtest
	if (!IsStakeModifierV2(contextHeight))
		return (NetworkID() == CBaseChainParams::REGTEST || (utxoFromBlockTime + 3600 <= contextTime));

	// after stake modifier V2, we require the utxo to be nStakeMinDepth deep in the chain
	return (contextHeight - utxoFromBlockHeight >= nStakeMinDepth);
}

class CMainParams : public CChainParams
{
public:
	CMainParams()
	{
		networkID = CBaseChainParams::MAIN;
		strNetworkID = "main";

		pchMessageStart[0] = 0xa9;
		pchMessageStart[1] = 0x7d;
		pchMessageStart[2] = 0x15;
		pchMessageStart[3] = 0xef;
		vAlertPubKey = ParseHex("04301e54567de2f9ac39794d6c3fd625a3038525cdbfe731c2b4252b514ba7dda5fb62b2a24bb2542fe3126a86c24c794c17772003980a414219860f4118564d32");
		nDefaultPort = 17774;
		bnProofOfWorkLimit = ~uint256(0) >> 20; // TensorCoin starting difficulty is 1 / 2^12
		nMaxReorganizationDepth = 100;
		nEnforceBlockUpgradeMajority = 8100; // 75%
		nRejectBlockOutdatedMajority = 10260; // 95%
		nToCheckBlockUpgradeMajority = 10800; // Approximate expected amount of blocks in 7 days (1440*7.5)
		nMinerThreads = 0;
		nTargetSpacing = 1 * 60;        // 1 minute
		nMaturity = 61;
		nStakeMinDepth = 600;
		nFutureTimeDriftPoW = 7200;
		nFutureTimeDriftPoS = 180;
		nMasternodeCountDrift = 20;
		nMaxMoneyOut = 60000000 * COIN;

		/** Height or Time Based Activations **/
		nLastPOWBlock = 5760;
		nModifierUpdateBlock = 0;
		nZerocoinStartHeight = nLastPOWBlock + 60;
		nBlockZerocoinV2 = nLastPOWBlock + 60;
		nBlockDoubleAccumulated = 0;
		nBlockStakeModifierlV2 = std::numeric_limits<int>::max();
		// Public coin spend enforcement
		nPublicZCSpends = nLastPOWBlock + 100;

		const char* pszTimestamp = "TensorCoin2020";
		CMutableTransaction txNew;
		txNew.vin.resize(1);
		txNew.vout.resize(1);
		txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
		txNew.vout[0].nValue = 250 * COIN;
		txNew.vout[0].scriptPubKey = CScript() << ParseHex("04cfcd535c0b18b9dc4d3ad675c28fe69c3f7c54b314e2231becfda4743d4c78b3e02e876df96fbe8a581510a743aaf85cff2a824ff82b7eadbb00c04776d452de") << OP_CHECKSIG;
		genesis.vtx.push_back(txNew);
		genesis.hashPrevBlock = 0;
		genesis.hashMerkleRoot = genesis.BuildMerkleTree();
		genesis.nVersion = 1;
		genesis.nTime = 1588860000;
		genesis.nBits = 0x1e0ffff0;
		genesis.nNonce = 934012;

		hashGenesisBlock = genesis.GetHash();
		assert(hashGenesisBlock == uint256("0x00000a505610347e04efaa857a6421b8abe3b5c814b0ae8a39b8e4fcfccc68f6"));
		assert(genesis.hashMerkleRoot == uint256("0xc3e1280d51f67af9b84ad5ebed5c18f3f855e954eec1102b76d03a05cda4da1a"));

		vSeeds.push_back(CDNSSeedData("1", "161.35.74.34"));
		vSeeds.push_back(CDNSSeedData("2", "167.172.102.211"));
		vSeeds.push_back(CDNSSeedData("3", "161.35.31.8"));
		vSeeds.push_back(CDNSSeedData("4", "104.248.138.198"));

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65);
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
		base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
		base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
		// 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
		base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

		convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

		fMiningRequiresPeers = true;
		fAllowMinDifficultyBlocks = false;
		fDefaultConsistencyChecks = false;
		fRequireStandard = true;
		fMineBlocksOnDemand = false;
		fSkipProofOfWorkCheck = false;
		fTestnetToBeDeprecatedFieldRPC = false;
		fHeadersFirstSyncingActive = false;

		nPoolMaxTransactions = 3;
		nBudgetCycleBlocks = 43200; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30)
		strSporkKey = "04207174b1a86665e104be6fc58c87eacfed1009337de54a1af4fe9729a12b4a6909ffede54b813d7b9095d854fef6993f8111a46b0d7f4907e013b7ffc9ec7efe";
		strObfuscationPoolDummyAddress = "TAH1oBdS66oYtmaKYdKshjXfqBb5XwEhT9";
		nStartMasternodePayments = 1588860000;

											   /** Zerocoin */
		zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
			"4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
			"6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
			"7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
			"8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
			"31438167899885040445364023527381951378636564391212010397122822120720357";
		nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
		nMaxZerocoinPublicSpendsPerTransaction = 637; // Assume about 220 bytes each input
		nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
		nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
		nRequiredAccumulation = 1;
		nDefaultSecurityLevel = 100; //full security level for accumulators
		nZerocoinRequiredStakeDepth = 200; //The required confirmations for a ztnsr to be stakable

		nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
		nProposalEstablishmentTime = 60 * 60 * 24; // Proposals must be at least a day old to make it into a budget
	}

	const Checkpoints::CCheckpointData& Checkpoints() const
	{
		return data;
	}

};
static CMainParams mainParams;

/**
* Testnet (v3)
*/
class CTestNetParams : public CMainParams
{
public:
	CTestNetParams()
	{
		networkID = CBaseChainParams::TESTNET;
		strNetworkID = "test";
		pchMessageStart[0] = 0xa8;
		pchMessageStart[1] = 0x8d;
		pchMessageStart[2] = 0x16;
		pchMessageStart[3] = 0xee;
		vAlertPubKey = ParseHex("04301e54567de2f9ac39794d6c3fd625a3038525cdbfe731c2b4252b514ba7dda5fb62b2a24bb2542fe3126a86c24c794c17772003980a414219860f4118564d32");
		nDefaultPort = 27774;
		nEnforceBlockUpgradeMajority = 4320; // 75%
		nRejectBlockOutdatedMajority = 5472; // 95%
		nToCheckBlockUpgradeMajority = 5760; // 4 days
		nMinerThreads = 0;
		nTargetSpacing = 1 * 60;  // TensorCoin: 1 minute
		nLastPOWBlock = 200;
		nMaturity = 15;
		nStakeMinDepth = 100;
		nMasternodeCountDrift = 4;
		nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
		nMaxMoneyOut = 43199500 * COIN;
		nZerocoinStartHeight = 201576;
		nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
		nBlockStakeModifierlV2 = std::numeric_limits<int>::max();
		// Public coin spend enforcement
		nPublicZCSpends = 1106100;

		//! Modify the testnet genesis block so the timestamp is valid for a later start.
		genesis.nTime = 1585675200;
		genesis.nNonce = 2402015;

		//hashGenesisBlock = genesis.GetHash();
		//assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));

		vFixedSeeds.clear();
		vSeeds.clear();
		vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "tensorcoin-testnet.seed.fuzzbawls.pw"));
		vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "tensorcoin-testnet.seed2.fuzzbawls.pw"));
		vSeeds.push_back(CDNSSeedData("warrows.dev", "testnet.dnsseed.tensorcoin.warrows.dev"));

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet tensorcoin addresses start with 'x' or 'y'
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet tensorcoin script addresses start with '8' or '9'
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
																			 // Testnet tensorcoin BIP32 pubkeys start with 'DRKV'
		base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
		// Testnet tensorcoin BIP32 prvkeys start with 'DRKP'
		base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
		// Testnet tensorcoin BIP44 coin type is '1' (All coin's testnet default)
		base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

		convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

		fMiningRequiresPeers = true;
		fAllowMinDifficultyBlocks = true;
		fDefaultConsistencyChecks = false;
		fRequireStandard = true;
		fMineBlocksOnDemand = false;
		fTestnetToBeDeprecatedFieldRPC = true;

		nPoolMaxTransactions = 2;
		nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet
		strSporkKey = "04207174b1a86665e104be6fc58c87eacfed1009337de54a1af4fe9729a12b4a6909ffede54b813d7b9095d854fef6993f8111a46b0d7f4907e013b7ffc9ec7efe";
		strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
		nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
		nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
									   // here because we only have a 8 block finalization window on testnet

		nProposalEstablishmentTime = 60 * 5; // Proposals must be at least 5 mns old to make it into a test budget
	}
	const Checkpoints::CCheckpointData& Checkpoints() const
	{
		return dataTestnet;
	}
};
static CTestNetParams testNetParams;

/**
* Regression test
*/
class CRegTestParams : public CTestNetParams
{
public:
	CRegTestParams()
	{
		networkID = CBaseChainParams::REGTEST;
		strNetworkID = "regtest";
		pchMessageStart[0] = 0xa6;
		pchMessageStart[1] = 0x6e;
		pchMessageStart[2] = 0x14;
		pchMessageStart[3] = 0xed;
		nDefaultPort = 37774;
		nEnforceBlockUpgradeMajority = 750;
		nRejectBlockOutdatedMajority = 950;
		nToCheckBlockUpgradeMajority = 1000;
		nMinerThreads = 1;
		nTargetSpacing = 1 * 60;        // TensorCoin: 1 minutes
		bnProofOfWorkLimit = ~uint256(0) >> 1;
		nLastPOWBlock = 250;
		nMaturity = 100;
		nStakeMinDepth = 0;
		nMasternodeCountDrift = 4;
		nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
		nMaxMoneyOut = 43199500 * COIN;
		nZerocoinStartHeight = 300;
		nBlockZerocoinV2 = 300;
		nBlockStakeModifierlV2 = std::numeric_limits<int>::max(); // max integer value (never switch on regtest)
																  // Public coin spend enforcement
		nPublicZCSpends = 350;


		//! Modify the regtest genesis block so the timestamp is valid for a later start.
		genesis.nTime = 1585675200;
		genesis.nNonce = 2402015;

		//hashGenesisBlock = genesis.GetHash();
		//assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));
		//assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));

		vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
		vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

		fMiningRequiresPeers = false;
		fAllowMinDifficultyBlocks = true;
		fDefaultConsistencyChecks = true;
		fRequireStandard = false;
		fMineBlocksOnDemand = true;
		fSkipProofOfWorkCheck = true;
		fTestnetToBeDeprecatedFieldRPC = false;

		/* Spork Key for RegTest:
		WIF private key: 932HEevBSujW2ud7RfB1YF91AFygbBRQj3de3LyaCRqNzKKgWXi
		private key hex: bd4960dcbd9e7f2223f24e7164ecb6f1fe96fc3a416f5d3a830ba5720c84b8ca
		Address: yCvUVd72w7xpimf981m114FSFbmAmne7j9
		*/
		strSporkKey = "04207174b1a86665e104be6fc58c87eacfed1009337de54a1af4fe9729a12b4a6909ffede54b813d7b9095d854fef6993f8111a46b0d7f4907e013b7ffc9ec7efe";
	}
	const Checkpoints::CCheckpointData& Checkpoints() const
	{
		return dataRegtest;
	}
};
static CRegTestParams regTestParams;

/**
* Unit test
*/
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
	CUnitTestParams()
	{
		networkID = CBaseChainParams::UNITTEST;
		strNetworkID = "unittest";
		nDefaultPort = 47774;
		vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
		vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

		fMiningRequiresPeers = false;
		fDefaultConsistencyChecks = true;
		fAllowMinDifficultyBlocks = false;
		fMineBlocksOnDemand = true;
	}

	const Checkpoints::CCheckpointData& Checkpoints() const
	{
		// UnitTest share the same checkpoints as MAIN
		return data;
	}

	//! Published setters to allow changing values in unit test cases
	virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
	virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
	virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
	virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
	virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
	virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;

static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
	assert(pCurrentParams);
	assert(pCurrentParams == &unitTestParams);
	return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
	assert(pCurrentParams);
	return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
	switch (network) {
	case CBaseChainParams::MAIN:
		return mainParams;
	case CBaseChainParams::TESTNET:
		return testNetParams;
	case CBaseChainParams::REGTEST:
		return regTestParams;
	case CBaseChainParams::UNITTEST:
		return unitTestParams;
	default:
		assert(false && "Unimplemented network");
		return mainParams;
	}
}

void SelectParams(CBaseChainParams::Network network)
{
	SelectBaseParams(network);
	pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
	CBaseChainParams::Network network = NetworkIdFromCommandLine();
	if (network == CBaseChainParams::MAX_NETWORK_TYPES)
		return false;

	SelectParams(network);
	return true;
}
