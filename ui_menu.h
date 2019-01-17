/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *play_button;
    QPushButton *play_button2;
    QPushButton *exit_button;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *highscore_label;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(694, 436);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        Menu->setMinimumSize(QSize(0, 0));
        Menu->setMaximumSize(QSize(1366, 768));
        Menu->setAutoFillBackground(false);
        Menu->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(Menu);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/main_menu/battle-city-name.jpg")));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        play_button = new QPushButton(Menu);
        play_button->setObjectName(QString::fromUtf8("play_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(play_button->sizePolicy().hasHeightForWidth());
        play_button->setSizePolicy(sizePolicy1);
        play_button->setMinimumSize(QSize(300, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Press Start K"));
        font.setPointSize(15);
        play_button->setFont(font);
        play_button->setLayoutDirection(Qt::LeftToRight);
        play_button->setStyleSheet(QString::fromUtf8("border: none;"));

        verticalLayout->addWidget(play_button);

        play_button2 = new QPushButton(Menu);
        play_button2->setObjectName(QString::fromUtf8("play_button2"));
        play_button2->setMinimumSize(QSize(0, 30));
        play_button2->setFont(font);
        play_button2->setStyleSheet(QString::fromUtf8("border: none;"));

        verticalLayout->addWidget(play_button2);

        exit_button = new QPushButton(Menu);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        sizePolicy1.setHeightForWidth(exit_button->sizePolicy().hasHeightForWidth());
        exit_button->setSizePolicy(sizePolicy1);
        exit_button->setMinimumSize(QSize(0, 30));
        exit_button->setFont(font);
        exit_button->setStyleSheet(QString::fromUtf8("border: none;"));

        verticalLayout->addWidget(exit_button);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label_4 = new QLabel(Menu);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Press Start K"));
        font1.setPointSize(13);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        highscore_label = new QLabel(Menu);
        highscore_label->setObjectName(QString::fromUtf8("highscore_label"));
        highscore_label->setMaximumSize(QSize(16777215, 30));
        highscore_label->setFont(font1);
        highscore_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(highscore_label);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/main_menu/battle-city-logo.jpg")));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", nullptr));
        label_2->setText(QString());
        play_button->setText(QApplication::translate("Menu", "1 PLAYER", nullptr));
        play_button2->setText(QApplication::translate("Menu", "2 PLAYER", nullptr));
        exit_button->setText(QApplication::translate("Menu", "EXIT", nullptr));
        label_4->setText(QApplication::translate("Menu", "HELP: H", nullptr));
        highscore_label->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
