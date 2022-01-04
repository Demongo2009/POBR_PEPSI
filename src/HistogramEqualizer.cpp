//
// Created by demongo on 03.01.2022.
//

#include "HistogramEqualizer.h"

void HistogramEqualizer::equalize(cv::Mat &mat) {

	const std::array<int, 256> histogram = this->createHistogram(mat);
	int pixelCount = mat.rows * mat.cols;
	const std::array<int, 256> lut = this->createLookuptable(histogram, pixelCount);
	mat = this->applyLUT(mat, lut);
}


const std::array<int, 256> HistogramEqualizer::createHistogram(cv::Mat& image) const {
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


const std::array<int, 256> HistogramEqualizer::createLookuptable(const std::array<int, 256> histogram, const int pixelCount) const {
	std::array<int, 256> lookupTable;
	int probabilitySum = 0;
	std::transform(histogram.begin(), histogram.end(), lookupTable.begin(), [&probabilitySum, &pixelCount](int bucket) -> int {
		probabilitySum += bucket;
		return probabilitySum * 255 / pixelCount;
	});

	return lookupTable;
}

cv::Mat& HistogramEqualizer::applyLUT(cv::Mat& image, const std::array<int, 256> lut) const {
	int imageWidth = image.cols;
	int imageHeight = image.rows;

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			image.at<cv::Vec3b>(j,i)[2] = lut[image.at<cv::Vec3b>(j,i)[2]];
		}
	}
	return image;
}