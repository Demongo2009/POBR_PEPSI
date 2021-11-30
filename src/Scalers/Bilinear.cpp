//
// Created by demongo on 16.11.2021.
//

#include "Bilinear.h"
#include "../constants.h"
#include <algorithm>
#include <iostream>

void Scalers::Bilinear::scale(cv::Mat &mat) {
	double widthRatio = mat.cols / (double)RESIZED_WIDTH;
	double heightRatio = mat.rows / (double)RESIZED_HEIGHT;

	cv::Mat resized(RESIZED_HEIGHT, RESIZED_WIDTH, mat.type());
	cv::Mat_<cv::Vec3b> resized_(resized);

	for(int i=0; i<RESIZED_WIDTH; i++){
		for(int j=0; j<RESIZED_HEIGHT; j++) {
			int x = i*widthRatio;
			int y = j*heightRatio;

			int x1 = std::min(x, mat.cols-1);
			int y1 = std::min(y, mat.rows-1);

			int x2 = std::min(x+1, mat.cols-1);
			int y2 = std::min(y+1, mat.rows-1);

			for(int k=0; k<3; k++){
				uchar color11 = mat.at<cv::Vec3b>(y1,x1)[k];
				uchar color21 = mat.at<cv::Vec3b>(y1,x2)[k];
				uchar color12 = mat.at<cv::Vec3b>(y2,x1)[k];
				uchar color22 = mat.at<cv::Vec3b>(y2,x2)[k];

				double interpolation1 = (x2-x)*color11 + (x-x1)*color21;
				double interpolation2 = (x2-x)*color12 + (x-x1)*color22;

				if (x1 == x2) {
					interpolation1 = color11;
					interpolation2 = color22;
				}

				uchar finalInterpolation = std::max(std::min(
						(int)((y2-y)*interpolation1 + (y-y1)*interpolation2), 255)
								,0);

				resized_[j][i][k] = finalInterpolation;
			}

		}
	}


//	resized.forEach<cv::Vec3b>([&](cv::Vec3b& pixel,const int position[]){
//		int i = position[1];
//		int j = position[0];
//
//		double x = i*widthRatio;
//		double y = j*heightRatio;
//
//		int x1 = fmin(floor(x), RESIZED_WIDTH-1);
//		int y1 = fmin(floor(y), RESIZED_HEIGHT-1);
//
//		int x2 = fmin(ceil(x), RESIZED_WIDTH-1);
//		int y2 = fmin(ceil(y), RESIZED_HEIGHT-1);
//
//		cv::Vec3b color11 = mat.at<cv::Vec3b>(y1,x1);
//		cv::Vec3b color21 = mat.at<cv::Vec3b>(y1,x2);
//		cv::Vec3b color12 = mat.at<cv::Vec3b>(y2,x1);
//		cv::Vec3b color22 = mat.at<cv::Vec3b>(y2,x2);
//
//		cv::Vec3b interpolation1 = (x2-x)*color11 + (x-x1)*color21;
//		cv::Vec3b interpolation2 = (x2-x)*color12 + (x-x1)*color22;
//
//		if (x1 == x2) {
//			interpolation1 = color11;
//			interpolation2 = color22;
//		}
//
//		cv::Vec3b finalInterpolation = (y2-y)*interpolation1 + (y-y1)*interpolation2;
//		pixel = finalInterpolation;
//	});

	mat = resized;
}
