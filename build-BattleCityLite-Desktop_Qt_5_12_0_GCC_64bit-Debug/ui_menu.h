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
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(529, 398);
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 200));

        verticalLayout->addWidget(label);

        radioButton = new QRadioButton(Menu);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout->addWidget(radioButton, 0, Qt::AlignHCenter);

        radioButton_2 = new QRadioButton(Menu);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2, 0, Qt::AlignHCenter);

        radioButton_3 = new QRadioButton(Menu);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout->addWidget(radioButton_3, 0, Qt::AlignHCenter);

        label_4 = new QLabel(Menu);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(Menu);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Menu);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", nullptr));
        label->setText(QApplication::translate("Menu", "                                                       Here will be picture", nullptr));
        radioButton->setText(QApplication::translate("Menu", "Option1", nullptr));
        radioButton_2->setText(QApplication::translate("Menu", "Option2", nullptr));
        radioButton_3->setText(QApplication::translate("Menu", "SpecialOption3", nullptr));
        label_4->setText(QApplication::translate("Menu", "Here will be some \"logo\"", nullptr));
        label_2->setText(QApplication::translate("Menu", "Here will be some text", nullptr));
        label_3->setText(QApplication::translate("Menu", "Here also text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
