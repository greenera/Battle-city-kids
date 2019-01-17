/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *horizontalStatus;
    QSpacerItem *horizontalSpacer;
    QLabel *label_24;
    QLabel *timeLabel;
    QGraphicsView *activegame;
    QWidget *status;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *small_tank_15;
    QLabel *small_tank_6;
    QLabel *small_tank_9;
    QLabel *small_tank_18;
    QLabel *small_tank_10;
    QLabel *small_tank_12;
    QLabel *small_tank_5;
    QLabel *small_tank_16;
    QLabel *small_tank_20;
    QLabel *small_tank_8;
    QLabel *small_tank_2;
    QLabel *small_tank_19;
    QLabel *small_tank_7;
    QLabel *small_tank_3;
    QLabel *small_tank_11;
    QLabel *small_tank_1;
    QLabel *small_tank_17;
    QLabel *small_tank_4;
    QLabel *small_tank_14;
    QLabel *small_tank_13;
    QLabel *livesInfo;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QString::fromUtf8("GameWidget"));
        GameWidget->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameWidget->sizePolicy().hasHeightForWidth());
        GameWidget->setSizePolicy(sizePolicy);
        GameWidget->setMinimumSize(QSize(1024, 768));
        GameWidget->setMaximumSize(QSize(1366, 768));
        horizontalLayout = new QHBoxLayout(GameWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 35);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(GameWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(652, 0));
        widget->setMaximumSize(QSize(652, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalStatus = new QLabel(widget);
        horizontalStatus->setObjectName(QString::fromUtf8("horizontalStatus"));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start K"));
        font.setPointSize(16);
        horizontalStatus->setFont(font);

        horizontalLayout_2->addWidget(horizontalStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_24 = new QLabel(widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Press Start K"));
        label_24->setFont(font1);

        horizontalLayout_2->addWidget(label_24, 0, Qt::AlignRight);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setFont(font1);

        horizontalLayout_2->addWidget(timeLabel, 0, Qt::AlignRight);


        verticalLayout->addWidget(widget);

        activegame = new QGraphicsView(GameWidget);
        activegame->setObjectName(QString::fromUtf8("activegame"));
        sizePolicy.setHeightForWidth(activegame->sizePolicy().hasHeightForWidth());
        activegame->setSizePolicy(sizePolicy);
        activegame->setMinimumSize(QSize(652, 652));
        activegame->setMaximumSize(QSize(652, 652));
        activegame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        activegame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        activegame->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(activegame);


        horizontalLayout->addLayout(verticalLayout);

        status = new QWidget(GameWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setMinimumSize(QSize(100, 0));
        status->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setPointSize(10);
        status->setFont(font2);
        verticalLayout_2 = new QVBoxLayout(status);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_2 = new QWidget(status);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        small_tank_15 = new QLabel(widget_2);
        small_tank_15->setObjectName(QString::fromUtf8("small_tank_15"));
        small_tank_15->setMinimumSize(QSize(20, 20));
        small_tank_15->setMaximumSize(QSize(20, 20));
        small_tank_15->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_15->setScaledContents(true);

        gridLayout->addWidget(small_tank_15, 7, 0, 1, 1);

        small_tank_6 = new QLabel(widget_2);
        small_tank_6->setObjectName(QString::fromUtf8("small_tank_6"));
        small_tank_6->setMinimumSize(QSize(20, 20));
        small_tank_6->setMaximumSize(QSize(20, 20));
        small_tank_6->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_6->setScaledContents(true);

        gridLayout->addWidget(small_tank_6, 2, 1, 1, 1);

        small_tank_9 = new QLabel(widget_2);
        small_tank_9->setObjectName(QString::fromUtf8("small_tank_9"));
        small_tank_9->setMinimumSize(QSize(20, 20));
        small_tank_9->setMaximumSize(QSize(20, 20));
        small_tank_9->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_9->setScaledContents(true);

        gridLayout->addWidget(small_tank_9, 4, 0, 1, 1);

        small_tank_18 = new QLabel(widget_2);
        small_tank_18->setObjectName(QString::fromUtf8("small_tank_18"));
        small_tank_18->setMinimumSize(QSize(20, 20));
        small_tank_18->setMaximumSize(QSize(20, 20));
        small_tank_18->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_18->setScaledContents(true);

        gridLayout->addWidget(small_tank_18, 9, 1, 1, 1);

        small_tank_10 = new QLabel(widget_2);
        small_tank_10->setObjectName(QString::fromUtf8("small_tank_10"));
        small_tank_10->setMinimumSize(QSize(20, 20));
        small_tank_10->setMaximumSize(QSize(20, 20));
        small_tank_10->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_10->setScaledContents(true);

        gridLayout->addWidget(small_tank_10, 4, 1, 1, 1);

        small_tank_12 = new QLabel(widget_2);
        small_tank_12->setObjectName(QString::fromUtf8("small_tank_12"));
        small_tank_12->setMinimumSize(QSize(20, 20));
        small_tank_12->setMaximumSize(QSize(20, 20));
        small_tank_12->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_12->setScaledContents(true);

        gridLayout->addWidget(small_tank_12, 5, 1, 1, 1);

        small_tank_5 = new QLabel(widget_2);
        small_tank_5->setObjectName(QString::fromUtf8("small_tank_5"));
        small_tank_5->setMinimumSize(QSize(20, 20));
        small_tank_5->setMaximumSize(QSize(20, 20));
        small_tank_5->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_5->setScaledContents(true);

        gridLayout->addWidget(small_tank_5, 2, 0, 1, 1);

        small_tank_16 = new QLabel(widget_2);
        small_tank_16->setObjectName(QString::fromUtf8("small_tank_16"));
        small_tank_16->setMinimumSize(QSize(20, 20));
        small_tank_16->setMaximumSize(QSize(20, 20));
        small_tank_16->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_16->setScaledContents(true);

        gridLayout->addWidget(small_tank_16, 7, 1, 1, 1);

        small_tank_20 = new QLabel(widget_2);
        small_tank_20->setObjectName(QString::fromUtf8("small_tank_20"));
        small_tank_20->setMinimumSize(QSize(20, 20));
        small_tank_20->setMaximumSize(QSize(20, 20));
        small_tank_20->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_20->setScaledContents(true);

        gridLayout->addWidget(small_tank_20, 10, 1, 1, 1);

        small_tank_8 = new QLabel(widget_2);
        small_tank_8->setObjectName(QString::fromUtf8("small_tank_8"));
        small_tank_8->setMinimumSize(QSize(20, 20));
        small_tank_8->setMaximumSize(QSize(20, 20));
        small_tank_8->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_8->setScaledContents(true);

        gridLayout->addWidget(small_tank_8, 3, 1, 1, 1);

        small_tank_2 = new QLabel(widget_2);
        small_tank_2->setObjectName(QString::fromUtf8("small_tank_2"));
        small_tank_2->setMinimumSize(QSize(20, 20));
        small_tank_2->setMaximumSize(QSize(20, 20));
        small_tank_2->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_2->setScaledContents(true);

        gridLayout->addWidget(small_tank_2, 0, 1, 1, 1);

        small_tank_19 = new QLabel(widget_2);
        small_tank_19->setObjectName(QString::fromUtf8("small_tank_19"));
        small_tank_19->setMinimumSize(QSize(20, 20));
        small_tank_19->setMaximumSize(QSize(20, 20));
        small_tank_19->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_19->setScaledContents(true);

        gridLayout->addWidget(small_tank_19, 10, 0, 1, 1);

        small_tank_7 = new QLabel(widget_2);
        small_tank_7->setObjectName(QString::fromUtf8("small_tank_7"));
        small_tank_7->setMinimumSize(QSize(20, 20));
        small_tank_7->setMaximumSize(QSize(20, 20));
        small_tank_7->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_7->setScaledContents(true);

        gridLayout->addWidget(small_tank_7, 3, 0, 1, 1);

        small_tank_3 = new QLabel(widget_2);
        small_tank_3->setObjectName(QString::fromUtf8("small_tank_3"));
        small_tank_3->setMinimumSize(QSize(20, 20));
        small_tank_3->setMaximumSize(QSize(20, 20));
        small_tank_3->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_3->setScaledContents(true);

        gridLayout->addWidget(small_tank_3, 1, 0, 1, 1);

        small_tank_11 = new QLabel(widget_2);
        small_tank_11->setObjectName(QString::fromUtf8("small_tank_11"));
        small_tank_11->setMinimumSize(QSize(20, 20));
        small_tank_11->setMaximumSize(QSize(20, 20));
        small_tank_11->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_11->setScaledContents(true);

        gridLayout->addWidget(small_tank_11, 5, 0, 1, 1);

        small_tank_1 = new QLabel(widget_2);
        small_tank_1->setObjectName(QString::fromUtf8("small_tank_1"));
        small_tank_1->setMinimumSize(QSize(20, 20));
        small_tank_1->setMaximumSize(QSize(20, 20));
        small_tank_1->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_1->setScaledContents(true);

        gridLayout->addWidget(small_tank_1, 0, 0, 1, 1);

        small_tank_17 = new QLabel(widget_2);
        small_tank_17->setObjectName(QString::fromUtf8("small_tank_17"));
        small_tank_17->setMinimumSize(QSize(20, 20));
        small_tank_17->setMaximumSize(QSize(20, 20));
        small_tank_17->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_17->setScaledContents(true);

        gridLayout->addWidget(small_tank_17, 9, 0, 1, 1);

        small_tank_4 = new QLabel(widget_2);
        small_tank_4->setObjectName(QString::fromUtf8("small_tank_4"));
        small_tank_4->setMinimumSize(QSize(20, 20));
        small_tank_4->setMaximumSize(QSize(20, 20));
        small_tank_4->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_4->setScaledContents(true);

        gridLayout->addWidget(small_tank_4, 1, 1, 1, 1);

        small_tank_14 = new QLabel(widget_2);
        small_tank_14->setObjectName(QString::fromUtf8("small_tank_14"));
        small_tank_14->setMinimumSize(QSize(20, 20));
        small_tank_14->setMaximumSize(QSize(20, 20));
        small_tank_14->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_14->setScaledContents(true);

        gridLayout->addWidget(small_tank_14, 6, 1, 1, 1);

        small_tank_13 = new QLabel(widget_2);
        small_tank_13->setObjectName(QString::fromUtf8("small_tank_13"));
        small_tank_13->setMinimumSize(QSize(20, 20));
        small_tank_13->setMaximumSize(QSize(20, 20));
        small_tank_13->setPixmap(QPixmap(QString::fromUtf8("../resources/levels/small_npc.jpg")));
        small_tank_13->setScaledContents(true);

        gridLayout->addWidget(small_tank_13, 6, 0, 1, 1);


        verticalLayout_2->addWidget(widget_2);

        livesInfo = new QLabel(status);
        livesInfo->setObjectName(QString::fromUtf8("livesInfo"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Press Start K"));
        font3.setPointSize(10);
        livesInfo->setFont(font3);
        livesInfo->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(livesInfo);

        label_3 = new QLabel(status);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(110, 0));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3, 0, Qt::AlignBottom);


        horizontalLayout->addWidget(status);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "Form", nullptr));
        horizontalStatus->setText(QString());
        label_24->setText(QApplication::translate("GameWidget", "Time:", nullptr));
        timeLabel->setText(QApplication::translate("GameWidget", " 00:00", nullptr));
        small_tank_15->setText(QString());
        small_tank_6->setText(QString());
        small_tank_9->setText(QString());
        small_tank_18->setText(QString());
        small_tank_10->setText(QString());
        small_tank_12->setText(QString());
        small_tank_5->setText(QString());
        small_tank_16->setText(QString());
        small_tank_20->setText(QString());
        small_tank_8->setText(QString());
        small_tank_2->setText(QString());
        small_tank_19->setText(QString());
        small_tank_7->setText(QString());
        small_tank_3->setText(QString());
        small_tank_11->setText(QString());
        small_tank_1->setText(QString());
        small_tank_17->setText(QString());
        small_tank_4->setText(QString());
        small_tank_14->setText(QString());
        small_tank_13->setText(QString());
        livesInfo->setText(QApplication::translate("GameWidget", "here \n"
"should\n"
"be some\n"
"info", nullptr));
        label_3->setText(QApplication::translate("GameWidget", "Help:H", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
