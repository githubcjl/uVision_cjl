#include "uvision.h"
#include "ui_uvision.h"
#include "thumbnailthread.h"
#include <QDebug>
#include <QLabel>
#include <QPalette>
#include <QLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QMessageBox>



uVision::uVision(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{

	ui.setupUi(this);
	setWindowTitle("uVision_v1.0");

	IDevice::DeviceInitialSDK(NULL, FALSE);

	

	waitseconds = 1;
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::gray);//设置窗口背景色
	//setFixedSize(600,400);
	//setWindowTitle("www.cuteqt.com");
	pArea = new QScrollArea(this);
	previewwidget = new QWidget(pArea);	
	//previewwidget->setFixedSize(600,350);
	previewwidget->setPalette(pal);
	previewwidget->setAutoFillBackground(true);//自动填充窗口背景
	previewwidget->setGeometry(300,50,480,460);//设置窗口位置及背景色

	pArea->setWidget(previewwidget);
	pArea->setGeometry(320,60,450,440);

	vi = new VideoInput;

	UionOpenDeviceParam param;
	param.devIndex = 0;
	DeviceStatus devStatus = IDevice::OpenDevice(param, &m_pDevice);
	if(SUCCEEDED(devStatus)){
		//devStatus = m_pDevice->DeviceInitEx(uVision::InitReceiveDataProc2, this, NULL, TRUE);
		devStatus = m_pDevice->DeviceInit(vi->winId(), FALSE, TRUE);
		if(SUCCEEDED(devStatus))
			m_pDevice->DeviceCreateSettingPage(NULL);
	}

	//progress = new QProgressBar(this);
	//progress->setGeometry(310,515,200,25);
	//imageWatcher = new QFutureWatcher<QImage>(this);
	//connect(imageWatcher,SIGNAL(progressRangeChanged(int,int)),progress,SLOT(setRange(int,int)));
	//connect(imageWatcher,SIGNAL(progressValueChanged(int)),progress,SLOT(setValue(int)));
	//QPushButton* btn = new QPushButton("Open pictures..", this);
	//btn->setGeometry(450, 360, 130, 35);
	
	connect(ui.actOpenImage, SIGNAL(triggered()), this, SLOT(on_openFiles_clicked()));
	QGridLayout* layout = new QGridLayout(previewwidget);

	connect(ui.actPlay,SIGNAL(triggered()),this,SLOT(on_actPlayBtn_clicked()));
	connect(ui.actParameter,SIGNAL(triggered()),this,SLOT(on_actVideoParameter_clicked()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(on_serialBtn_clicked()));
	connect(ui.actInstitch,SIGNAL(triggered()),this,SLOT(on_actImageInstitch_clicked()));
}

uVision::~uVision()
{
	if(m_pDevice != NULL){
		m_pDevice->Stop();
		m_pDevice->CloseDevice();
		m_pDevice->DeviceUnInit();
		m_pDevice->Release();
		m_pDevice = NULL;
	}
	IDevice::DeviceUnInitialSDK();
}

void uVision::on_actPlayBtn_clicked()
{
	if(m_pDevice != NULL) m_pDevice->Start();
	vi->show();
}

void uVision::on_actVideoParameter_clicked()
{
	//videoproperty *vp = new videoproperty;
	//vp->show();

	if(m_pDevice != NULL){

		m_pDevice->DeviceShowSettingPage(TRUE);

	}

	//CAdvanceApp *advanceapp = new CAdvanceApp;
	//advanceapp->InitInstance();
	//CSetupDlg *setupDlg = new CSetupDlg;
	
}

void uVision::on_serialBtn_clicked()
{
	serialparameters *serial = new serialparameters;
	
	serial->show();
}

void uVision::on_actImageInstitch_clicked()
{
	//imagestitching *imagestitch = new imagestitching;
	//imagestitch->show();

	SiftMatch *s = new SiftMatch;
	s->show();
}

void uVision::on_openFiles_clicked()
{
	waitseconds = 1;//reset
	QStringList list = QFileDialog::getOpenFileNames(this, "Open one or more pictures", "", "*.jpg *.png *.bmp");
	if( list.count() == 0)
	{
		return;
	}
	//open files one by one, and create thread to create thumbnail for each file
	QStringList::Iterator it = list.begin();
	while(it != list.end()) 
	{
		createThumbnail(*it);
		++it;
	}
}

void uVision::createThumbnail(const QString& filename)
{
	//qDebug() << filename;
	QThread* thread = new thumbnailthread(filename, 10 - waitseconds);
	waitseconds ++;
	connect(thread,SIGNAL(thumbnailFinishedInstitch(QImage)),this,SLOT(addInstitchImages(QImage)));
	connect(thread, SIGNAL(thumbnailFinished(QImage)), this, SLOT(addThumbnail(QImage)));
	connect(thread, SIGNAL(thumbnailFailed(const QString)), this, SLOT(showError(const QString)));
	connect(thread, SIGNAL(finished()), this, SLOT(deleteThread()));
	thread->start();
}

void uVision::addInstitchImages(QImage bigpm)
{

}

void uVision::deleteThread()
{
	QObject* obj = sender();
	thumbnailthread * th = qobject_cast<thumbnailthread*>(obj);
	qDebug() << "delete thread..." << th->waitseconds();
	obj->deleteLater();
}

void uVision::addThumbnail(QImage smallpm)
{
	static int i = 0;
	static int j = 0;
	//qWarning() << "thumbnail create successfully..." << j << i ;
	//qWarning() << "Small PM:"<<smallpm << smallpm.size();
	QLabel* label = new QLabel;
	label->setPixmap(QPixmap::fromImage(smallpm));
	QGridLayout* gl = qobject_cast<QGridLayout*>(previewwidget->layout());
	gl->addWidget(label, j, i);
	label->show();
	qWarning() << "Label:" <<label << label->isVisible();
	i++;
	if( i > previewwidget->width() / smallpm.width()) 
	{
		i = 0;
		j ++;
	}
}

void uVision::showError(const QString filename)
{
	QMessageBox::information(this, "Error!", filename+" is not a valid picture file.");
}


void CALLBACK uVision::InitReceiveDataProc2(LPVOID pDevice, BYTE *pImageBuffer, DeviceFrameInfo *pFrInfo, LPVOID lParam)
{
	BYTE *pRGB24Buff = NULL;
	if((pRGB24Buff = ((IDevice *)pDevice)->DeviceISP(pImageBuffer, pFrInfo)) != NULL){
		//((CAdvanceDlg *)lParam)->ReceiveDataProc(pRGB24Buff, pFrInfo->uiWidth, pFrInfo->uiHeight);

	}


}