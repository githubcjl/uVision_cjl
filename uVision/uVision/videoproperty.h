#ifndef VIDEOPROPERTY_H
#define VIDEOPROPERTY_H

#include <QWidget>
#include "ui_videoproperty.h"

class videoproperty : public QWidget
{
	Q_OBJECT

public:
	videoproperty(QWidget *parent = 0);
	~videoproperty();

private:
	Ui::videoproperty ui;
};

#endif // VIDEOPROPERTY_H
