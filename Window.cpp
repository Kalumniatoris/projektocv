#include "GUIQT.h"

#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>


#include<iostream>
#include<conio.h>
#include<windows.h>
#include <ctime>
#include <sstream>
#include <string>
#include <qtimer.h>
cv::VideoCapture cap2("C:\\Users\\dkwiatkowski2\\Downloads\\bike.avi");

class Window : public QMainWindow
{
	Q_OBJECT
		QTimer _timer;
	private slots:
	void on_timeout() {
		cv::Mat frame;
		cap2 >> frame;
		imshow("FF", frame);
	}

public:
	Window() :
		QMainWindow(), _timer(this) {
		cap2.open(0);

		connect(&_timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
		_timer.start(10);
	}

};