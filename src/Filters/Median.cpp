//
// Created by demongo on 28.11.2021.
//

#include <opencv2/opencv.hpp>
#include "Median.h"

void Filters::Median::filter(cv::Mat &mat) {
	int windowWidth = 3;
	int windowHeight = 3;
	int imageWidth = mat.cols;
	int imageHeight = mat.rows;

	cv::Mat filtered(imageHeight, imageWidth, mat.type());
	cv::Mat_<cv::Vec3b> filtered_(filtered);

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			int x = i;
			int y = j;

			if (x < windowWidth/2 || y < windowHeight/2 ||
				x >= imageWidth-windowWidth/2 || y >= imageHeight-windowHeight/2) {
				filtered_[j][i] = mat.at<cv::Vec3b>(y,x);
				continue;
			}

			for(int k=0; k<3; k++){
				std::vector<uchar> temp;
				for(int i=0; i <windowWidth; i++){
					for(int j=0; j<windowHeight; j++){
						temp.push_back(mat.at<cv::Vec3b>(y-windowHeight/2+j,x-windowWidth/2+i)[k]);
					}
				}
				std::sort(temp.begin(), temp.end());

				filtered_[j][i][k] = temp[windowWidth*windowHeight / 2];
			}
		}
	}

//	filtered.forEach<cv::Vec3b>([&](cv::Vec3b& pixel, const int position[]){
//		int x = position[1];
//		int y = position[0];
//
//		if (x < windowWidth/2 || y < windowHeight/2 ||
//			x >= imageWidth-windowWidth/2 || y >= imageHeight-windowHeight/2) {
//			pixel = mat.at<cv::Vec3b>(y,x);
//			return;
//		}
//
//		for(int k=0; k<pixel.channels; k++){
//			std::vector<uchar> temp;
//			for(int i=0; i <windowWidth; i++){
//				for(int j=0; j<windowHeight; j++){
//					temp.push_back(mat.at<cv::Vec3b>(y-windowHeight/2+j,x-windowWidth/2+i)[k]);
//				}
//			}
//			std::sort(temp.begin(), temp.end());
//
//			pixel[k] = temp[windowWidth*windowHeight / 2];
//		}
//
//	});

	mat = filtered;
}
