// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2019-2020 The TensorCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZTNSRCONTROLDIALOG_H
#define ZTNSRCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "ztnsr/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZTNSRControlDialog;
}

class CZTNSRControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZTNSRControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZTNSRControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZTNSRControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZTNSRControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZTNSRControlDialog(QWidget *parent);
    ~ZTNSRControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZTNSRControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZTNSRControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZTNSRCONTROLDIALOG_H
