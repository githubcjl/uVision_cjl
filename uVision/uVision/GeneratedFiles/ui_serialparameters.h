/********************************************************************************
** Form generated from reading UI file 'serialparameters.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPARAMETERS_H
#define UI_SERIALPARAMETERS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serialparameters
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *serialparameters)
    {
        if (serialparameters->objectName().isEmpty())
            serialparameters->setObjectName(QString::fromUtf8("serialparameters"));
        serialparameters->resize(243, 233);
        comboBox = new QComboBox(serialparameters);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(80, 30, 69, 22));
        comboBox_2 = new QComboBox(serialparameters);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 70, 69, 22));
        comboBox_3 = new QComboBox(serialparameters);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(80, 110, 69, 22));
        comboBox_4 = new QComboBox(serialparameters);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(80, 150, 69, 22));
        comboBox_5 = new QComboBox(serialparameters);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(80, 190, 69, 22));
        label = new QLabel(serialparameters);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 54, 12));
        label_2 = new QLabel(serialparameters);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 54, 12));
        label_3 = new QLabel(serialparameters);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 54, 12));
        label_4 = new QLabel(serialparameters);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 160, 54, 12));
        label_5 = new QLabel(serialparameters);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 200, 54, 12));
        pushButton = new QPushButton(serialparameters);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 30, 61, 23));
        pushButton_2 = new QPushButton(serialparameters);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 60, 61, 23));

        retranslateUi(serialparameters);

        QMetaObject::connectSlotsByName(serialparameters);
    } // setupUi

    void retranslateUi(QWidget *serialparameters)
    {
        serialparameters->setWindowTitle(QApplication::translate("serialparameters", "serialparameters", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("serialparameters", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "14400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "9600", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("serialparameters", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "EVEN", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("serialparameters", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "6", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("serialparameters", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "2", 0, QApplication::UnicodeUTF8)
        );
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("serialparameters", "COM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("serialparameters", "COM8", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("serialparameters", "\346\263\242\347\211\271\347\216\207\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("serialparameters", "\346\240\241\351\252\214\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("serialparameters", "\346\225\260\346\215\256\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("serialparameters", "\345\201\234\346\255\242\344\275\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("serialparameters", "\344\270\262\345\217\243\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("serialparameters", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("serialparameters", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class serialparameters: public Ui_serialparameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPARAMETERS_H
