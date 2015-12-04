#ifndef UVISION_H
#define UVISION_H

#include <QtGui/QMainWindow>
#include "ui_uvision.h"
#include "videoinput.h"
#include "videoproperty.h"
#include "serialparameters.h"
#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QProgressBar>
#include <QFutureWatcher>
#include <QScrollArea>
#include "imagestitching.h"
#include <vector>
#include "siftmatch.h"
#include "stdafx.h"
#include <IDevice.h>
//#include "Advance.h"
//#include "SetupDlg.h"

class QLabel;

class uVision : public QMainWindow
{
	Q_OBJECT

public:
	uVision(QWidget *parent = 0, Qt::WFlags flags = 0);
	~uVision();

private:
	Ui::uVisionClass ui;
private slots:
	void on_actPlayBtn_clicked();
	void on_actVideoParameter_clicked();
	void on_serialBtn_clicked();
	void on_actImageInstitch_clicked();
protected slots:
		void on_openFiles_clicked();
		void deleteThread();
		void showError(const QString filename);
		void addThumbnail(QImage);
		void addInstitchImages(QImage);
private:
	static void CALLBACK InitReceiveDataProc2(LPVOID pDevice, BYTE *pImageBuffer, DeviceFrameInfo *pFrInfo, LPVOID lParam);
private:
	void createThumbnail(const QString& filename);
	QWidget* previewwidget;
	VideoInput *vi;
	int waitseconds;
	QScrollArea *pArea;
	IDevice		*m_pDevice;
	//QProgressBar *progress;
	//QFutureWatcher<QImage> *imageWatcher;
};

#endif // UVISION_H
