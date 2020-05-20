/********************************************************************************
** Form generated from reading UI file 'topbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPBAR_H
#define UI_TOPBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt/tensorcoin/expandablebutton.h"

QT_BEGIN_NAMESPACE

class Ui_TopBar
{
public:
    QVBoxLayout *verticalLayout_10;
    QWidget *containerTop;
    QVBoxLayout *verticalLayout_11;
    QWidget *top_container_2;
    QHBoxLayout *top_container;
    QWidget *widgetTopAmount;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelAmountTopTNSR;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QWidget *layoutSync;
    QVBoxLayout *verticalLayout_9;
    ExpandableButton *pushButtonSync;
    ExpandableButton *pushButtonMint;
    ExpandableButton *pushButtonStack;
    ExpandableButton *pushButtonConnection;
    ExpandableButton *pushButtonLock;
    ExpandableButton *pushButtonTheme;
    ExpandableButton *pushButtonFAQ;
    QWidget *bottom_container;
    QHBoxLayout *botton_container;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTitle1;
    QLabel *labelAmountTNSR;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTitle3;
    QLabel *labelPendingTNSR;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTitle4;
    QLabel *labelImmatureTNSR;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_2;
    QWidget *qrContainer;
    QVBoxLayout *containerQR;
    QPushButton *btnQr;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonQR;

    void setupUi(QWidget *TopBar)
    {
        if (TopBar->objectName().isEmpty())
            TopBar->setObjectName(QStringLiteral("TopBar"));
        TopBar->resize(734, 200);
        TopBar->setMinimumSize(QSize(0, 200));
        TopBar->setMaximumSize(QSize(16777215, 200));
        verticalLayout_10 = new QVBoxLayout(TopBar);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        containerTop = new QWidget(TopBar);
        containerTop->setObjectName(QStringLiteral("containerTop"));
        verticalLayout_11 = new QVBoxLayout(containerTop);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        top_container_2 = new QWidget(containerTop);
        top_container_2->setObjectName(QStringLiteral("top_container_2"));
        top_container_2->setMinimumSize(QSize(0, 65));
        top_container = new QHBoxLayout(top_container_2);
        top_container->setSpacing(0);
        top_container->setObjectName(QStringLiteral("top_container"));
        top_container->setContentsMargins(14, 0, 14, 0);
        widgetTopAmount = new QWidget(top_container_2);
        widgetTopAmount->setObjectName(QStringLiteral("widgetTopAmount"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTopAmount->sizePolicy().hasHeightForWidth());
        widgetTopAmount->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(widgetTopAmount);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelAmountTopTNSR = new QLabel(widgetTopAmount);
        labelAmountTopTNSR->setObjectName(QStringLiteral("labelAmountTopTNSR"));
        labelAmountTopTNSR->setMinimumSize(QSize(0, 36));
        labelAmountTopTNSR->setStyleSheet(QStringLiteral("padding:0px;margin:0px;"));

        horizontalLayout_5->addWidget(labelAmountTopTNSR, 0, Qt::AlignTop);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        label_16 = new QLabel(widgetTopAmount);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(1, 30));
        label_16->setMaximumSize(QSize(1, 30));
        label_16->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:0px;\n"
"border:none;"));

        horizontalLayout_5->addWidget(label_16, 0, Qt::AlignVCenter);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_12);


        top_container->addWidget(widgetTopAmount, 0, Qt::AlignVCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        top_container->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(12);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, -1);
        layoutSync = new QWidget(top_container_2);
        layoutSync->setObjectName(QStringLiteral("layoutSync"));
        layoutSync->setMinimumSize(QSize(0, 36));
        layoutSync->setMaximumSize(QSize(16777215, 36));
        verticalLayout_9 = new QVBoxLayout(layoutSync);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButtonSync = new ExpandableButton(layoutSync);
        pushButtonSync->setObjectName(QStringLiteral("pushButtonSync"));
        pushButtonSync->setMinimumSize(QSize(36, 36));
        pushButtonSync->setMaximumSize(QSize(16777215, 36));

        verticalLayout_9->addWidget(pushButtonSync);


        horizontalLayout_4->addWidget(layoutSync, 0, Qt::AlignRight);

        pushButtonMint = new ExpandableButton(top_container_2);
        pushButtonMint->setObjectName(QStringLiteral("pushButtonMint"));
        pushButtonMint->setMinimumSize(QSize(36, 36));

        horizontalLayout_4->addWidget(pushButtonMint);

        pushButtonStack = new ExpandableButton(top_container_2);
        pushButtonStack->setObjectName(QStringLiteral("pushButtonStack"));
        pushButtonStack->setMinimumSize(QSize(36, 36));

        horizontalLayout_4->addWidget(pushButtonStack);

        pushButtonConnection = new ExpandableButton(top_container_2);
        pushButtonConnection->setObjectName(QStringLiteral("pushButtonConnection"));
        pushButtonConnection->setMinimumSize(QSize(36, 36));

        horizontalLayout_4->addWidget(pushButtonConnection);

        pushButtonLock = new ExpandableButton(top_container_2);
        pushButtonLock->setObjectName(QStringLiteral("pushButtonLock"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonLock->sizePolicy().hasHeightForWidth());
        pushButtonLock->setSizePolicy(sizePolicy1);
        pushButtonLock->setMinimumSize(QSize(36, 0));

        horizontalLayout_4->addWidget(pushButtonLock);

        pushButtonTheme = new ExpandableButton(top_container_2);
        pushButtonTheme->setObjectName(QStringLiteral("pushButtonTheme"));
        pushButtonTheme->setMinimumSize(QSize(36, 36));
        pushButtonTheme->setMaximumSize(QSize(16777215, 36));

        horizontalLayout_4->addWidget(pushButtonTheme);

        pushButtonFAQ = new ExpandableButton(top_container_2);
        pushButtonFAQ->setObjectName(QStringLiteral("pushButtonFAQ"));
        pushButtonFAQ->setMinimumSize(QSize(36, 36));

        horizontalLayout_4->addWidget(pushButtonFAQ);


        top_container->addLayout(horizontalLayout_4);


        verticalLayout_11->addWidget(top_container_2);

        bottom_container = new QWidget(containerTop);
        bottom_container->setObjectName(QStringLiteral("bottom_container"));
        bottom_container->setMinimumSize(QSize(0, 135));
        botton_container = new QHBoxLayout(bottom_container);
        botton_container->setObjectName(QStringLiteral("botton_container"));
        botton_container->setContentsMargins(10, 0, 10, 10);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 9);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, -1, 30, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelTitle1 = new QLabel(bottom_container);
        labelTitle1->setObjectName(QStringLiteral("labelTitle1"));

        verticalLayout_2->addWidget(labelTitle1);

        labelAmountTNSR = new QLabel(bottom_container);
        labelAmountTNSR->setObjectName(QStringLiteral("labelAmountTNSR"));

        verticalLayout_2->addWidget(labelAmountTNSR);


        verticalLayout_7->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelTitle3 = new QLabel(bottom_container);
        labelTitle3->setObjectName(QStringLiteral("labelTitle3"));

        verticalLayout_3->addWidget(labelTitle3);

        labelPendingTNSR = new QLabel(bottom_container);
        labelPendingTNSR->setObjectName(QStringLiteral("labelPendingTNSR"));

        verticalLayout_3->addWidget(labelPendingTNSR);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelTitle4 = new QLabel(bottom_container);
        labelTitle4->setObjectName(QStringLiteral("labelTitle4"));

        verticalLayout_4->addWidget(labelTitle4);

        labelImmatureTNSR = new QLabel(bottom_container);
        labelImmatureTNSR->setObjectName(QStringLiteral("labelImmatureTNSR"));

        verticalLayout_4->addWidget(labelImmatureTNSR);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_7);

        label_9 = new QLabel(bottom_container);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(1, 100));
        label_9->setMaximumSize(QSize(1, 16777215));
        label_9->setStyleSheet(QLatin1String("background-color:white;\n"
"padding:0px;\n"
"border:none;"));

        horizontalLayout_3->addWidget(label_9);


        botton_container->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        botton_container->addItem(horizontalSpacer_2);

        qrContainer = new QWidget(bottom_container);
        qrContainer->setObjectName(QStringLiteral("qrContainer"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qrContainer->sizePolicy().hasHeightForWidth());
        qrContainer->setSizePolicy(sizePolicy2);
        qrContainer->setMinimumSize(QSize(90, 110));
        qrContainer->setMaximumSize(QSize(90, 110));
        containerQR = new QVBoxLayout(qrContainer);
        containerQR->setSpacing(0);
        containerQR->setObjectName(QStringLiteral("containerQR"));
        containerQR->setContentsMargins(5, 10, 5, 0);
        btnQr = new QPushButton(qrContainer);
        btnQr->setObjectName(QStringLiteral("btnQr"));
        btnQr->setMinimumSize(QSize(70, 70));
        btnQr->setMaximumSize(QSize(16777215, 70));
        btnQr->setIconSize(QSize(70, 70));

        containerQR->addWidget(btnQr);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        containerQR->addItem(verticalSpacer);

        pushButtonQR = new QPushButton(qrContainer);
        pushButtonQR->setObjectName(QStringLiteral("pushButtonQR"));
        pushButtonQR->setMinimumSize(QSize(36, 36));
        pushButtonQR->setMaximumSize(QSize(36, 36));

        containerQR->addWidget(pushButtonQR, 0, Qt::AlignHCenter|Qt::AlignBottom);


        botton_container->addWidget(qrContainer, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_11->addWidget(bottom_container);


        verticalLayout_10->addWidget(containerTop);


        retranslateUi(TopBar);

        QMetaObject::connectSlotsByName(TopBar);
    } // setupUi

    void retranslateUi(QWidget *TopBar)
    {
        TopBar->setWindowTitle(QApplication::translate("TopBar", "Form", Q_NULLPTR));
        labelAmountTopTNSR->setText(QApplication::translate("TopBar", "480.0685 TNSR", Q_NULLPTR));
        label_16->setText(QString());
        labelTitle1->setText(QApplication::translate("TopBar", "Available", Q_NULLPTR));
        labelAmountTNSR->setText(QApplication::translate("TopBar", "480.0685 TNSR", Q_NULLPTR));
        labelTitle3->setText(QApplication::translate("TopBar", "Pending", Q_NULLPTR));
        labelPendingTNSR->setText(QApplication::translate("TopBar", "6.943 TNSR", Q_NULLPTR));
        labelTitle4->setText(QApplication::translate("TopBar", "Immature", Q_NULLPTR));
        labelImmatureTNSR->setText(QApplication::translate("TopBar", "10 TNSR", Q_NULLPTR));
        label_9->setText(QString());
        btnQr->setText(QString());
        pushButtonQR->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TopBar: public Ui_TopBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPBAR_H
