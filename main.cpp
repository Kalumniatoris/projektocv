#include "GUIQT.h"
#include <QtWidgets/QApplication>

#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

#include <qtimer.h>

#include<iostream>
#include<conio.h>
#include<windows.h>
#include <ctime>
#include <sstream>
#include <string>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	
	GUIQT w;
	w.show();
	return a.exec();
}
