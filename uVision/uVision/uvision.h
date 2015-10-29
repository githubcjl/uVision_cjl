#ifndef UVISION_H
#define UVISION_H

#include <QtGui/QMainWindow>
#include "ui_uvision.h"
#include "videoinput.h"
#include "videoproperty.h"
#include "serialparameters.h"

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
};

#endif // UVISION_H
