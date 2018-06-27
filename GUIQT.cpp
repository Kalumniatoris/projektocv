#include "GUIQT.h"
#include <QObject>
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
//
using namespace cv;
using namespace std;

int blurS=0;
Mat catched;
Mat dife;
void GUIQT::on_timeout() {
	//blurS = 1;
	cv::Mat frame;
	cap2 >> frame;
	cvtColor(frame, frame, COLOR_BGR2Lab);
	QSlider *slider = ui.blurSlider;
	Mat blured;
	blurS = slider->value();
	ostringstream s;
	s.clear();
	s << "Blur: " << blurS;
	QString q= QString::fromStdString(s.str());
	//rotate()
	//transform(frame, frame, frame);
	ui.label->setText(q);
	blur(frame,blured, Size(blurS+1, blurS+1),Point(-1,-1),4);
	//cv::Mat dife;
	//cvtColor(frame, frame, COLOR_Lab2BGR);
	frame = blured - frame;
	absdiff(frame, blured, dife);
	imshow("fr", blured);

	QDoubleSpinBox *maxThresholdSpin = ui.doubleSpinBox;
	QDoubleSpinBox *minThresholdSpin = ui.doubleSpinBox_2;

	maxThresholdSpin->setMinimum(minThresholdSpin->value());
	minThresholdSpin->setMaximum(maxThresholdSpin->value());
	//cvtColor(dife, dife, COLOR_Lab2BGR);
	
	//threshold(dife, dife,minThresholdSpin->value()*256,256, THRESH_TOZERO_INV);
	threshold(dife, dife, minThresholdSpin->value() * 256, 256, THRESH_BINARY_INV);
	
	cvtColor(dife, dife, COLOR_Lab2BGR);
	cvtColor(dife, dife, COLOR_BGR2GRAY);
	
	//cvtColor(dife, dife, CV_Lab2BGR);

	imshow("dife", dife);
}

void GUIQT::catch_released() {
	
	Mat my = dife.clone();
	cap2 >> catched;
	imshow("catched", catched);
	imwrite(".\\imgs\\catched.jpg", catched);
	system("prototype\\Run.bat");
	//waitKey(100);
	
	Mat their = imread(".\\sal\\catched_GC.png");
	imshow("their", their);
	imshow("my", my);
}


GUIQT::GUIQT(QWidget *parent)
	: QMainWindow(parent)

{
	//Window win;
	//win.show();
	ui.setupUi(this);
	QTimer *timer = new QTimer(this);
	cap2.open(0);
	cv::Mat frame;
	cap2 >> frame;
	ui.blurSlider->setMaximum(frame.cols);
	blurS = ui.blurSlider->value();
	ui.label->setText(blurS+"1111");
	connect(ui.catchButton, SIGNAL(released()), this, SLOT(catch_released()));
	connect(timer, SIGNAL(timeout()), this,SLOT(on_timeout()));
	timer->setInterval(10);
	timer->start();

}
