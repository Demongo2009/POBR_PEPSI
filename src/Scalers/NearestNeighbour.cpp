//
// Created by demongo on 16.11.2021.
//

#include "NearestNeighbour.h"
#include "../constants.h"
#include <algorithm>

void Scalers::NearestNeighbour::scale(cv::Mat &mat) {
	double widthRatio = mat.cols / (double)RESIZED_WIDTH;
	double heightRatio = mat.rows / (double)RESIZED_HEIGHT;

	cv::Mat resized(RESIZED_HEIGHT, RESIZED_WIDTH, mat.type());
	cv::Mat_<cv::Vec3b> resized_(resized);

	for(int i=0; i<RESIZED_WIDTH; i++){
		for(int j=0; j<RESIZED_HEIGHT; j++){

			int x = std::min((int)round(i*widthRatio), mat.cols-1);
			int y = std::min((int)round(j*heightRatio), mat.rows-1);

			resized_[j][i] = mat.at<cv::Vec3b>(y,x);
		}
	}
//	resized.forEach<cv::Vec3b>([&](cv::Vec3b& pixel,const int position[]) -> void{
//		int i = position[1];
//		int j = position[0];
//
//		int x = fmin(round(i*widthRatio), RESIZED_WIDTH-1);
//		int y = fmin(round(j*heightRatio), RESIZED_HEIGHT-1);
//
//		pixel = mat.at<cv::Vec3b>(y,x);
//
////		int x1;
////		int y1;
////		if (x + 1 >= mat.cols){
////			x1 = x;
////		} else {
////			x1 = x + 1;
////		}
////
////		if (y + 1 >= mat.rows){
////			y1 = y;
////		} else {
////			y1 = y + 1;
////		}
//	});
	mat = resized;
}
