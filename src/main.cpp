#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "SegmentDescriptor.h"
#include "Scalers/NearestNeighbour.h"
#include "Scalers/Bilinear.h"
#include "Scalers/IScaler.h"
#include "constants.h"
#include "Filters/IFilter.h"
#include "Filters/Median.h"
#include "Filters/Lowpass.h"
#include "Filters/Highpass.h"
#include "SegmentationProcessor.h"

void runPrescaling(cv::Mat& image, int algorithm);
void runFiltering(cv::Mat& image, int algorithm);
void runHighpassFiltering(cv::Mat& image);
std::vector<SegmentDescriptor> runSegmentation(cv::Mat& image);
void runTraitDetection(cv::Mat& image);
std::vector<SegmentDescriptor> runObjectRecognition(cv::Mat& image);
void drawBoundingBox(cv::Mat& ogImage, std::vector<SegmentDescriptor> objects);

int main(int argc, char *argv[]) {
    std::cout << "ARGS: 1 path, 2 scaling, 3 filtering" << std::endl;

	cv::Mat image;
	image = cv::imread(argv[1], cv::IMREAD_COLOR);

	if(!image.data){
		std::cout << "Empty image" << std::endl;
		return -1;
	}

	runPrescaling(image, atoi(argv[2]));
	cv::Mat ogImage = image.clone();
	runFiltering(image, atoi(argv[3]));
	runHighpassFiltering(image);
	runSegmentation(image);
//	runTraitDetection(image);
//	std::vector<SegmentDescriptor> objects = runObjectRecognition(image);
//
//	drawBoundingBox(ogImage, objects);

	cv::imshow("Picture", image);
	cv::imshow("Picture1", ogImage);
	cv::imwrite("result.jpg", image);
//	cv::imwrite("result.jpg", ogImage);
	cv::waitKey(-1);
    return 0;
}
void runPrescaling(cv::Mat& image, int algorithm) {

	IScaler* scaler;
	switch (algorithm) {
		case ScalingAlgorithmType::NearestNeighbour:
			scaler = new Scalers::NearestNeighbour();
			break;
		case ScalingAlgorithmType::Bilinear:
			scaler = new Scalers::Bilinear();
			break;
		default:
			throw std::runtime_error("Wrong input!");
	}

	scaler->scale(image);
}
void runFiltering(cv::Mat& image, int algorithm) {

	IFilter* filter;
	switch (algorithm) {
		case FilteringAlgorithmType::Median:
			filter = new Filters::Median();
			break;
		case FilteringAlgorithmType::Lowpass:
			filter = new Filters::Lowpass();
			break;
		default:
			throw std::runtime_error("Wrong input!");
	}

	filter->filter(image);
}
void runHighpassFiltering(cv::Mat& image) {
	IFilter* filter;
	filter = new Filters::Highpass();
	filter->filter(image);
}
std::vector<SegmentDescriptor> runSegmentation(cv::Mat& image) {
	SegmentationProcessor processor;
	std::vector<SegmentDescriptor> descriptors = processor.segmentImage(image);
	return descriptors;
}
void runTraitDetection(cv::Mat& image) {

}
std::vector<SegmentDescriptor> runObjectRecognition(cv::Mat& image) {

}
void drawBoundingBox(cv::Mat& ogImage, std::vector<SegmentDescriptor> objects) {

}