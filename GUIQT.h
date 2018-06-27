#pragma once
#include <QObject>
#include <QtWidgets/QMainWindow>
#include "ui_GUIQT.h"
class GUIQT : public QMainWindow
{
	Q_OBJECT

public:
	GUIQT(QWidget *parent = Q_NULLPTR);

private:
	Ui::GUIQTClass ui;
private slots:
void on_timeout();
void catch_released();
};
