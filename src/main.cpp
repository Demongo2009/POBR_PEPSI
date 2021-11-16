#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include "SegmentDescriptor.h"
#include "ScalingAlgorithmType.h"
#include "Scalers/NearestNeighbour.h"
#include "Scalers/Bilinear.h"
#include "Scalers/IScaler.h"

void runPrescaling(cv::Mat& image, int algorithm);
void runFiltering(cv::Mat& image, int algorithm);
void runHighPassFiltering(cv::Mat& image);
void runSegmentation(cv::Mat& image);
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
	runHighPassFiltering(image);
	runSegmentation(image);
	runTraitDetection(image);
	std::vector<SegmentDescriptor> objects = runObjectRecognition(image);

	drawBoundingBox(ogImage, objects);

	cv::imshow("Picture", ogImage);
	cv::imwrite("resultbk.jpg", ogImage);
	cv::waitKey(-1);
    return 0;
}
void runPrescaling(cv::Mat& image, int algorithm) {

	IScaler scaler;
	switch (algorithm) {
		case ScalingAlgorithmType::NearestNeighbour:
			scaler = Scalers::NearestNeighbour();
			break;
		case ScalingAlgorithmType::Bilinear:
			scaler = Scalers::Bilinear();
			break;
		default:
			throw std::runtime_error("Wrong input!");

	}

	scaler.scale(image);
}
void runFiltering(cv::Mat& image, int algorithm) {

}
void runHighPassFiltering(cv::Mat& image) {

}
void runSegmentation(cv::Mat& image) {

}
void runTraitDetection(cv::Mat& image) {

}
std::vector<SegmentDescriptor> runObjectRecognition(cv::Mat& image) {

}
void drawBoundingBox(cv::Mat& ogImage, std::vector<SegmentDescriptor> objects) {

}