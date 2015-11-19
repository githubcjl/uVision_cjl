/********************************************************************************
** Form generated from reading UI file 'imagestitching.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESTITCHING_H
#define UI_IMAGESTITCHING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imagestitching
{
public:

    void setupUi(QWidget *imagestitching)
    {
        if (imagestitching->objectName().isEmpty())
            imagestitching->setObjectName(QString::fromUtf8("imagestitching"));
        imagestitching->resize(638, 481);

        retranslateUi(imagestitching);

        QMetaObject::connectSlotsByName(imagestitching);
    } // setupUi

    void retranslateUi(QWidget *imagestitching)
    {
        imagestitching->setWindowTitle(QApplication::translate("imagestitching", "imagestitching", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class imagestitching: public Ui_imagestitching {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESTITCHING_H
