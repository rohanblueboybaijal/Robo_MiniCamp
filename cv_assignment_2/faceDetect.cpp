#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	//Your code goes here
	cv::CascadeClassifier face_cascade;
	cv::CascadeClassifier eyes_cascade;
	face_cascade.load("haarcascade_frontalface_default.xml");
	eyes_cascade.load("haarcascade_eye.xml");

	cv::Mat img = cv::imread(argv[1]);
	cv::Mat grey;
	cv::cvtColor(img, grey, CV_BGR2GRAY);
	cv::equalizeHist(grey, grey);

	std::vector<cv::Rect> faces;
	face_cascade.detectMultiScale(grey, faces, 1.3, 3, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30,30));

	if(faces.size()>0)
	{
		std::cout<<"YES\n";
		for(int i=0; i<faces.size(); i+=1)
		{
			cv::Mat face_roi = grey(faces[i]);
			std::vector<cv::Rect> eyes;
			eyes_cascade.detectMultiScale(face_roi, eyes, 1.1, 3, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30,30));
			for(int j=0; j<eyes.size(); j+=1)
			{
				cv::rectangle(img, cv::Point(faces[i].x+eyes[j].x, faces[i].y+eyes[j].y), cv::Point(faces[i].x+ eyes[j].x+eyes[j].width, faces[i].y +eyes[j].y+eyes[j].height), cv::Scalar(0,0,255), 2);
				std::cout<<"("<<(2*faces[i].x+ eyes[j].x + eyes[j].width)/2<<","<<(2*faces[i].y  + eyes[j].y+eyes[j].height)/2<<")\n";
			}
			cv::rectangle(img, cv::Point(faces[i].x, faces[i].y), cv::Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), cv::Scalar(255,0,0), 4);
		}
	}

	//cv::imshow("face", img);
	//cv::waitKey(0);
	//cv::destroyAllWindows();
	return 0;
}
