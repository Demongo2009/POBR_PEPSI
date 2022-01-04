//
// Created by demongo on 03.01.2022.
//

#include "HistogramEqualizer.h"

void HistogramEqualizer::equalize(cv::Mat &mat) {

	std::array<int, 256> histogram = createHistogram(mat);
	int pixelCount = mat.rows * mat.cols;
	std::array<int, 256> lut = createLookuptable(histogram, pixelCount);
	this->applyLUT(mat, lut);
}


std::array<int, 256> HistogramEqualizer::createHistogram(cv::Mat& image) {
	std::array<int, 256> histogram;
	for(auto& value: histogram){
		value = 0;
	}

	int imageWidth = image.cols;
	int imageHeight = image.rows;

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			const uchar value = image.at<cv::Vec3b>(j,i)[2];
			++histogram[value];
		}
	}

	return histogram;
}


std::array<int, 256> HistogramEqualizer::createLookuptable(std::array<int, 256> histogram, int pixelCount){
	std::array<int, 256> lookupTable;
	int probabilitySum = 0;
	std::transform(histogram.begin(), histogram.end(), lookupTable.begin(), [&probabilitySum, &pixelCount](int bucket) -> int {
		probabilitySum += bucket;
		return probabilitySum * 255 / pixelCount;
	});

	return lookupTable;
}

void HistogramEqualizer::applyLUT(cv::Mat& image, std::array<int, 256> lut){
	int imageWidth = image.cols;
	int imageHeight = image.rows;

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			image.at<cv::Vec3b>(j,i)[2] = lut[image.at<cv::Vec3b>(j,i)[2]];
		}
	}
	return;
}