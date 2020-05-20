// Copyright (c) 2019-2020 The TensorCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLTNSRWIDGET_H
#define COINCONTROLTNSRWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlTNSRWidget;
}

class CoinControlTNSRWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlTNSRWidget(QWidget *parent = nullptr);
    ~CoinControlTNSRWidget();

private:
    Ui::CoinControlTNSRWidget *ui;
};

#endif // COINCONTROLTNSRWIDGET_H
