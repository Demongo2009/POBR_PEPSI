//
// Created by demongo on 03.01.2022.
//

#include "ColorReducer.h"

void ColorReducer::reduce(cv::Mat &mat) {
	const std::array<uchar, 256> lookupTable = createLookupTable();

	int imageWidth = mat.cols;
	int imageHeight = mat.rows;

	for(int i=0; i<imageWidth; i++) {
		for (int j = 0; j < imageHeight; j++) {
			mat.at<cv::Vec3b>(j,i)[0] = lookupTable[mat.at<cv::Vec3b>(j,i)[0]];
			mat.at<cv::Vec3b>(j,i)[1] = lookupTable[mat.at<cv::Vec3b>(j,i)[1]];
			mat.at<cv::Vec3b>(j,i)[2] = lookupTable[mat.at<cv::Vec3b>(j,i)[2]];
		}
	}
}

std::array<uchar, 256> ColorReducer::createLookupTable(){
	std::array<uchar, 256> table;
	for(int i = 0; i < 256; ++i){
		table[i] = (uchar)(10 * (i / 10));
	}
	return table;
}
