//
// Created by demongo on 30.11.2021.
//

#include "Highpass.h"

void Filters::Highpass::filter(cv::Mat &mat) {
	int kernelWidth = 3;
	int kernelHeight = 3;
	cv::Mat kernel = (cv::Mat_<double>(kernelHeight,kernelWidth) <<
		    -0.5, -0.5, -0.5,
			-0.5, 5, -0.5,
			-0.5, -0.5, -0.5);
	int imageWidth = mat.cols;
	int imageHeight = mat.rows;

	cv::Mat filtered = mat.clone();
	cv::Mat_<cv::Vec3b> filtered_(filtered);

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			int x = i;
			int y = j;

			if (x < kernelWidth/2 || y < kernelHeight/2 ||
				x >= imageWidth-kernelWidth/2 || y >= imageHeight-kernelHeight/2) {
				cv::Vec3b vec = mat.at<cv::Vec3b>(y,x);
				for(int k=0; k<3; k++) {
					filtered_[j][i][k] = (uchar)(std::max(std::min((int)vec[k],255),0));
				}
				continue;
			}

			for(int k=0; k<3; k++){
				double temp = 0;
				for(int l=0; l <kernelWidth; l++){
					for(int m=0; m<kernelHeight; m++){
						temp += kernel.at<double>(m,l) *
										  mat.at<cv::Vec3b>(y-kernelHeight/2+m,x-kernelWidth/2+l)[k];
					}
				}

				filtered_[j][i][k] = (uchar)(std::max(std::min((int)temp,255),0));
			}

		}
	}
	mat = filtered;
}
