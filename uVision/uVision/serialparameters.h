#ifndef SERIALPARAMETERS_H
#define SERIALPARAMETERS_H

#include <QWidget>
#include "ui_serialparameters.h"

class serialparameters : public QWidget
{
	Q_OBJECT

public:
	serialparameters(QWidget *parent = 0);
	~serialparameters();

private:
	Ui::serialparameters ui;
};

#endif // SERIALPARAMETERS_H
