/********************************************************************************
** Form generated from reading UI file 'videoinput.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOINPUT_H
#define UI_VIDEOINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoInput
{
public:
    QLabel *videoLabel;
    QLabel *photoLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playBtn;
    QPushButton *photoBtn;
    QPushButton *stopBtn;

    void setupUi(QWidget *VideoInput)
    {
        if (VideoInput->objectName().isEmpty())
            VideoInput->setObjectName(QString::fromUtf8("VideoInput"));
        VideoInput->resize(966, 596);
        videoLabel = new QLabel(VideoInput);
        videoLabel->setObjectName(QString::fromUtf8("videoLabel"));
        videoLabel->setGeometry(QRect(40, 20, 471, 501));
        photoLabel = new QLabel(VideoInput);
        photoLabel->setObjectName(QString::fromUtf8("photoLabel"));
        photoLabel->setGeometry(QRect(560, 20, 391, 501));
        layoutWidget = new QWidget(VideoInput);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 540, 239, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        playBtn = new QPushButton(layoutWidget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));

        horizontalLayout->addWidget(playBtn);

        photoBtn = new QPushButton(layoutWidget);
        photoBtn->setObjectName(QString::fromUtf8("photoBtn"));

        horizontalLayout->addWidget(photoBtn);

        stopBtn = new QPushButton(layoutWidget);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));

        horizontalLayout->addWidget(stopBtn);


        retranslateUi(VideoInput);

        QMetaObject::connectSlotsByName(VideoInput);
    } // setupUi

    void retranslateUi(QWidget *VideoInput)
    {
        VideoInput->setWindowTitle(QApplication::translate("VideoInput", "VideoInput", 0, QApplication::UnicodeUTF8));
        videoLabel->setText(QApplication::translate("VideoInput", "videoData", 0, QApplication::UnicodeUTF8));
        photoLabel->setText(QApplication::translate("VideoInput", "photoData", 0, QApplication::UnicodeUTF8));
        playBtn->setText(QApplication::translate("VideoInput", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        photoBtn->setText(QApplication::translate("VideoInput", "\346\213\215\347\205\247", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("VideoInput", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoInput: public Ui_VideoInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOINPUT_H
