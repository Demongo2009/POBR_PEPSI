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
#include "TraitDetector.h"
#include "ObjectRecogniser.h"
#include "Dilater.h"
#include "HistogramEqualizer.h"
#include "ColorReducer.h"

void runPrescaling(cv::Mat& image, int algorithm);
void runFiltering(cv::Mat& image, int algorithm);
void runHighpassFiltering(cv::Mat& image);
std::vector<SegmentDescriptor> runSegmentation(cv::Mat& image);
std::map<Color, std::vector<SegmentDescriptor>> runTraitDetection(std::vector<SegmentDescriptor>& image);
std::vector<SegmentDescriptor> runObjectRecognition(cv::Mat& ogImage, std::map<Color, std::vector<SegmentDescriptor>> bins);
void drawBoundingBox(cv::Mat& ogImage, std::vector<SegmentDescriptor> objects);
void drawSegmentBoundary(cv::Mat& image, BoundingBox bb);

void runDilation(cv::Mat& mat);

void runHistogramEqualizer(cv::Mat &mat);

void runColorReduction(cv::Mat &mat);

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
	cv::imshow("og", ogImage);
//	runColorReduction(image);
//	runFiltering(image, atoi(argv[3]));
		runDilation(image);

	runHighpassFiltering(image);
	runDilation(image);

//	runHighpassFiltering(image);
//	runHistogramEqualizer(image);

	cv::imshow("filtered", image);
	std::vector<SegmentDescriptor> segments = runSegmentation(image);
	std::map<Color, std::vector<SegmentDescriptor>> bins = runTraitDetection(segments);
	cv::Mat test = ogImage.clone();
	std::vector<SegmentDescriptor> objects = runObjectRecognition(test, bins);
//
	drawBoundingBox(ogImage, objects);

	cv::imshow("result", ogImage);
	cv::imwrite("result.jpg", ogImage);
	cv::waitKey(-1);
    return 0;
}

void runColorReduction(cv::Mat &mat) {
	ColorReducer colorReducer = ColorReducer();
	colorReducer.reduce(mat);
}

void runHistogramEqualizer(cv::Mat &mat) {
	HistogramEqualizer histogramEqualizer = HistogramEqualizer();
	histogramEqualizer.equalize(mat);
}

void runDilation(cv::Mat& mat) {
	Dilater dilater = Dilater();
	dilater.dilate(mat);
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
std::map<Color, std::vector<SegmentDescriptor>> runTraitDetection(std::vector<SegmentDescriptor>& segments) {
	TraitDetector detector;
	std::map<Color, std::vector<SegmentDescriptor>> bins = {
			{Color::RED, {} },
			{Color::BLUE, {} },
			{Color::WHITE, {} },
	};
	detector.detectTraitsAndFilter(segments, bins);
	return bins;
}
std::vector<SegmentDescriptor> runObjectRecognition(cv::Mat& ogImage, std::map<Color, std::vector<SegmentDescriptor>> bins) {
	ObjectRecogniser recogniser;
	std::vector<SegmentDescriptor> objects = recogniser.recogniseObject(ogImage, bins);
	return objects;
}
void drawBoundingBox(cv::Mat& ogImage, std::vector<SegmentDescriptor> objects) {
	for(auto object: objects){
		BoundingBox bb = object.getBoundingBox();

		drawSegmentBoundary(ogImage, bb);
	};

}

void drawSegmentBoundary(cv::Mat& image, BoundingBox bb){
	const cv::Vec3b line = {0, 0, 255};

	for(auto i = bb.getX1(); i < bb.getX1() + bb.getWidth(); ++i){
		if(i-1 < 0 || i+1>image.rows || bb.getY1()-1 < 0 || bb.getY1()+1 > image.cols){
			continue;
		}
		image.at<cv::Vec3b>(i, bb.getY1()) = line;
		image.at<cv::Vec3b>(i+1, bb.getY1() ) = line;
		image.at<cv::Vec3b>(i-1, bb.getY1() ) = line;
		image.at<cv::Vec3b>(i, bb.getY1()+1) = line;
		image.at<cv::Vec3b>( i+1, bb.getY1()+1) = line;
		image.at<cv::Vec3b>(i-1, bb.getY1()+1) = line;
		image.at<cv::Vec3b>(i, bb.getY1()-1 ) = line;
		image.at<cv::Vec3b>(i+1, bb.getY1()-1) = line;
		image.at<cv::Vec3b>(i-1 , bb.getY1()-1) = line;
	}

	for(auto i = bb.getY1(); i < bb.getY1() + bb.getHeight(); ++i){
		if(i-1 < 0 || i+1>image.cols || bb.getX1()-1 < 0 || bb.getX1()+1 > image.rows){
			continue;
		}
		image.at<cv::Vec3b>(bb.getX1()+1, i) = line;
		image.at<cv::Vec3b>(bb.getX1()-1, i) = line;
		image.at<cv::Vec3b>(bb.getX1(), i) = line;
		image.at<cv::Vec3b>(bb.getX1()+1, i+1) = line;
		image.at<cv::Vec3b>(bb.getX1()-1, i+1) = line;
		image.at<cv::Vec3b>(bb.getX1(), i+1) = line;
		image.at<cv::Vec3b>(bb.getX1()+1, i-1) = line;
		image.at<cv::Vec3b>(bb.getX1()-1, i-1 ) = line;
		image.at<cv::Vec3b>(bb.getX1(), i-1) = line;
	}

	for(auto i = bb.getX1(); i < bb.getX1() + bb.getWidth(); ++i){
		if(i-1 < 0 || i+1>image.rows || bb.getY1()-1 < 0 || bb.getY1()+ bb.getHeight()+1 > image.cols){
			continue;
		}
		image.at<cv::Vec3b>( i, bb.getY1() + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i+1, bb.getY1() + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i-1, bb.getY1() + bb.getHeight()) = line;
		image.at<cv::Vec3b>( i, bb.getY1() +1  + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i+1, bb.getY1() +1  + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i-1, bb.getY1() +1 + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i, bb.getY1() -1 + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i+1, bb.getY1() -1 + bb.getHeight()) = line;
		image.at<cv::Vec3b>(i-1, bb.getY1() -1 + bb.getHeight()) = line;
	}

	for(auto i = bb.getY1(); i < bb.getY1() + bb.getHeight(); ++i){
		if(i-1 < 0 || i+1>image.cols || bb.getX1()-1 < 0 || bb.getX1()+ bb.getWidth() + 1 > image.rows){
			continue;
		}
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i + 1) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i + 1) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i + 1) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i - 1) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i - 1) = line;
		image.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i - 1) = line;
	}
	return;
}
