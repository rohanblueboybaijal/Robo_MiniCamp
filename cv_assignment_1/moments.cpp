#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	//Your code goes here
	cv::Mat sample = cv::imread("template.png");
	cv::Mat test = cv::imread(argv[1]);
	cv::cvtColor(test,test,CV_BGR2GRAY);
	cv::threshold(test, test, 150, 255, CV_THRESH_BINARY_INV);

	//Calculating moments for a circle
	cv::Mat sample_thresh =  cv::Mat::zeros(sample.size(),CV_8UC1);
	cv::inRange(sample,cv::Scalar(200,0,0), cv::Scalar(255,10,10), sample_thresh);
	double d1 = cv::matchShapes(test, sample_thresh, CV_CONTOURS_MATCH_I2,0);

	//Calculating the moments for a square 
	sample_thresh = cv::Mat::zeros(sample.size(),CV_8UC1);
	cv::inRange(sample, cv::Scalar(0,0,200), cv::Scalar(20,20,255),sample_thresh);
	double d2 = cv::matchShapes(test, sample_thresh,CV_CONTOURS_MATCH_I2,0);

	if(d1<d2)
		std::cout<<"CIRCLE"<<std::endl;
	else
		std::cout<<"SQUARE"<<std::endl;

	return 0;
}