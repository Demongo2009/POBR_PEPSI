//
// Created by demongo on 31.12.2021.
//

#include "ObjectRecogniser.h"
#include "../constants.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <opencv2/core/mat.hpp>
#include <opencv2/opencv.hpp>

std::vector<SegmentDescriptor> ObjectRecogniser::recogniseObject(cv::Mat& image,
																 std::map<Color, std::vector<SegmentDescriptor>>& bins) {
	std::vector<SegmentDescriptor> objects;

	objects = findRedBluePart(bins);
	std::cout<< objects.size() << "\n";
	objects = findWhiteBackground(image, objects, bins);
	std::cout<< objects.size() << "\n";

	return objects;
}

std::vector<SegmentDescriptor> ObjectRecogniser::learnObject(std::map<Color, std::vector<SegmentDescriptor>>& bins) {
	std::vector<SegmentDescriptor> objects;

	std::pair<int,int> redCog = bins[Color::RED][0].getCOG();
	std::pair<int,int> blueCog = bins[Color::BLUE][0].getCOG();

	double distance = std::sqrt(std::pow(redCog.first - blueCog.first,2) +
								std::pow(redCog.second - blueCog.second,2));

	std::cout<< distance << "D\n";
	objects.push_back(bins[Color::RED][0].addPoints(bins[Color::BLUE][0]));


	std::pair<int,int> redBluePartCOG = objects[0].getCOG();
	std::vector<SegmentDescriptor> objectsWithBackgrounds;
	std::vector<SegmentDescriptor> backgrounds;
	for(const auto& whitePart: bins[Color::WHITE]){
		BoundingBox bb = whitePart.getBoundingBox();
		if(bb.isInside(redBluePartCOG))
			backgrounds.push_back(whitePart);
	}
	if(!backgrounds.empty()){
		std::sort(backgrounds.begin(), backgrounds.end(), [](auto& v1, auto& v2){
			return v1.getArea() > v2.getArea();
		});
		objectsWithBackgrounds.push_back(objects[0].addPoints(backgrounds.front()));
	}

	return objectsWithBackgrounds;
}

std::vector<SegmentDescriptor> ObjectRecogniser::findRedBluePart(std::map<Color, std::vector<SegmentDescriptor>>& bins) {
	std::vector<SegmentDescriptor> objects;

	for(auto redSegment: bins[Color::RED]){
		for(auto blueSegment: bins[Color::BLUE]){
			std::pair<int,int> redCog = redSegment.getCOG();
			std::pair<int,int> blueCog = blueSegment.getCOG();

			double distance = std::sqrt(std::pow(redCog.first - blueCog.first,2) +
					std::pow(redCog.second - blueCog.second,2));

			double maxHeight = std::max(redSegment.getBoundingBox().getHeight(), blueSegment.getBoundingBox().getHeight());
			SegmentDescriptor segmentDescriptor = redSegment.addPoints(blueSegment);
			std::cout << std::fabs(segmentDescriptor.getWidthHeightRatio() - RED_BLUE_WH_MODEL) << "\n";
			if(distance - DISTANCE_THRESHOLD < HEIGHT_DISTANCE_MODEL*maxHeight
				&& std::fabs(segmentDescriptor.getWidthHeightRatio() - RED_BLUE_WH_MODEL) < RED_BLUE_WH_THRESHOLD
				&& redCog.first < blueCog.first
				){
				objects.push_back(segmentDescriptor);
			}
		}
	}

	return objects;
}


std::vector<SegmentDescriptor> ObjectRecogniser::findWhiteBackground(cv::Mat& image, std::vector<SegmentDescriptor> objects,
																	  std::map<Color, std::vector<SegmentDescriptor>>& bins) {
	std::vector<SegmentDescriptor> objectsWithBackgrounds;
	cv::Mat filtered = image.clone();
	for(auto redBluePart: objects){
		std::pair<int,int> redBluePartCOG = redBluePart.getCOG();
		filtered = drawSegmentBoundary(filtered, redBluePart.getBoundingBox(), cv::Vec3b(0,255,0));
		std::vector<SegmentDescriptor> backgrounds;
		for(const auto& whitePart: bins[Color::WHITE]){
			BoundingBox bb = whitePart.getBoundingBox();
			filtered = drawSegmentBoundary(filtered, bb, cv::Vec3b(255,0,0));
			if(bb.isInside(redBluePartCOG))
				backgrounds.push_back(whitePart);
		}
		if(!backgrounds.empty()){
			std::sort(backgrounds.begin(), backgrounds.end(), [](auto& v1, auto& v2){
				return v1.getArea() < v2.getArea();
			});
			objectsWithBackgrounds.push_back(redBluePart.addPoints(backgrounds.front()));
		}
	}

	return objectsWithBackgrounds;
}


cv::Mat ObjectRecogniser::drawSegmentBoundary(cv::Mat& image, BoundingBox bb, cv::Vec3b line){
	cv::Mat filtered= image.clone();
	cv::Mat_<cv::Vec3b> filtered_(filtered);

	for(auto i = bb.getX1(); i < bb.getX1() + bb.getWidth(); ++i){
		if(i-1 < 0 || i+1>image.rows || bb.getY1()-1 < 0 || bb.getY1()+1 > image.cols){
			continue;
		}
		for(int k=0; k<3; k++){
			filtered.at<cv::Vec3b>(i, bb.getY1())[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i+1, bb.getY1() )[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i-1, bb.getY1() )[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i, bb.getY1()+1)[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>( i+1, bb.getY1()+1)[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i-1, bb.getY1()+1)[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i, bb.getY1()-1 )[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i+1, bb.getY1()-1)[k] = (uchar)line[k];
			filtered.at<cv::Vec3b>(i-1 , bb.getY1()-1)[k] = (uchar)line[k];
		}

	}

	for(auto i = bb.getY1(); i < bb.getY1() + bb.getHeight(); ++i){
		if(i-1 < 0 || i+1>image.cols || bb.getX1()-1 < 0 || bb.getX1()+1 > image.rows){
			continue;
		}
		for(int k=0; k<3; k++) {
			filtered.at<cv::Vec3b>(bb.getX1() + 1, i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() - 1, i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1(), i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + 1, i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() - 1, i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1(), i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + 1, i - 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() - 1, i - 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1(), i - 1)[k] = (uchar) line[k];
		}
	}

	for(auto i = bb.getX1(); i < bb.getX1() + bb.getWidth(); ++i){
		if(i-1 < 0 || i+1>image.rows || bb.getY1()-1 < 0 || bb.getY1()+ bb.getHeight()+1 > image.cols){
			continue;
		}
		for(int k=0; k<3; k++) {
			filtered.at<cv::Vec3b>(i, bb.getY1() + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i + 1, bb.getY1() + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i - 1, bb.getY1() + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i, bb.getY1() + 1 + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i + 1, bb.getY1() + 1 + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i - 1, bb.getY1() + 1 + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i, bb.getY1() - 1 + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i + 1, bb.getY1() - 1 + bb.getHeight())[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(i - 1, bb.getY1() - 1 + bb.getHeight())[k] = (uchar) line[k];
		}
	}

	for(auto i = bb.getY1(); i < bb.getY1() + bb.getHeight(); ++i){
		if(i-1 < 0 || i+1>image.cols || bb.getX1()-1 < 0 || bb.getX1()+ bb.getWidth() + 1 > image.rows){
			continue;
		}
		for(int k=0; k<3; k++) {
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i + 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() + 1, i - 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth() - 1, i - 1)[k] = (uchar) line[k];
			filtered.at<cv::Vec3b>(bb.getX1() + bb.getWidth(), i - 1)[k] = (uchar) line[k];
		}
	}

	cv::imshow("OR", filtered);
	return filtered;
}


