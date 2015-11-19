#ifndef IMAGESTITCHING_H
#define IMAGESTITCHING_H

#include <QWidget>
#include "ui_imagestitching.h"


class imagestitching : public QWidget
{
	Q_OBJECT

public:
	imagestitching(QWidget *parent = 0);
	~imagestitching();

private:
	Ui::imagestitching ui;
};

#endif // IMAGESTITCHING_H
