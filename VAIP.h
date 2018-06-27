#pragma once

#include <QWidget>
#include <QtWidgets/qmainwindow.h>
#include "ui_VAIP.h"

class VAIP : public QWidget
{
	Q_OBJECT

public:
	VAIP(QWidget *parent = Q_NULLPTR);
	~VAIP();

private:
	Ui::VAIP ui;
};
