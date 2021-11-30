//
// Created by demongo on 30.11.2021.
//

#include <stack>
#include "SegmentationProcessor.h"
#include "SegmentDescriptor.h"
#include "constants.h"


std::vector<SegmentDescriptor> SegmentationProcessor::segmentImage(cv::Mat &mat) {
	StateMat states = initializeStateMat(mat);
	ColorMat matOfColors = toColors(mat);
	SegmentVector listOfSegments = segmentation(matOfColors, states);
	listOfSegments = filterSegments(listOfSegments);
	std::vector<SegmentDescriptor> descriptors = toDescriptors(listOfSegments, matOfColors);
	return descriptors;
}

StateMat SegmentationProcessor::initializeStateMat(cv::Mat &mat) {
	StateMat states;

	for(int i=0; i<mat.cols; i++){
		std::vector<State> s;
		for(int j=0; j<mat.rows; j++){
			s.push_back(UNVISITED);
		}
		states.push_back(s);
	}

	return states;
}

SegmentVector
SegmentationProcessor::segmentation(ColorMat &mat,
									StateMat stateMat) {
	SegmentVector segments;
	int matHeight=mat[0].size();
	for(int i=1; i<mat.size()-1; i++){
		for(int j=1; j<matHeight-1; j++){
			Color color = mat[j][i];
			State state = stateMat[j][i];

			if(color == OTHER){
				stateMat[j][i] = MISSED;
			}

			if(state == ADDED){
				continue;
			}

			Color seed = color;
			std::vector<std::pair<int, int>> segment;
			std::stack<std::pair<int, int>> pointsStack;
			pointsStack.push(std::make_pair(j,i));
			while(!pointsStack.empty()){
				std::pair<int, int> point = pointsStack.top();
				State pointState = stateMat[point.first][point.second];
				Color pointColor = mat[point.first][point.second];

				if(pointColor != seed || pointState == ADDED){
					pointsStack.pop();
					continue;
				}

				stateMat[point.first][point.second] = ADDED;
				segment.push_back(point);
				for(int x=0; x<3; x++){
					for(int y=0; y<3; y++){
						if(x==1 && y==1) {
							continue;
						}

						int neighbourX = point.second + x;
						int neighbourY = point.first + y;

						if(neighbourX < 0 || neighbourY < 0 || neighbourX >= mat.size() || neighbourY >= matHeight){
							continue;
						}

						pointsStack.push(std::make_pair(neighbourY, neighbourX));
					}
				}

				pointsStack.pop();
			}
			segments.push_back(segment);
		}
	}

	return segments;
}

SegmentVector
SegmentationProcessor::filterSegments(SegmentVector segmentVector) {
	SegmentVector result;
	for(auto segment: segmentVector){
		if(segment.size() > SEGMENT_SIZE_THRESHOLD){
			result.push_back(segment);
		}
	}

	return result;
}

std::vector<SegmentDescriptor>
SegmentationProcessor::toDescriptors(SegmentVector segmentVector, ColorMat colorMat) {
	std::vector<SegmentDescriptor> descriptors;
	for(auto segment: segmentVector){
		int exampleY = segment.front().first;
		int exampleX = segment.front().second;
		descriptors.push_back(SegmentDescriptor(segment, colorMat[exampleY][exampleX]));
	}

	return descriptors;
}

ColorMat SegmentationProcessor::toColors(cv::Mat &mat) {
	ColorMat colors;
	for(int i=0; i<mat.cols; i++) {
		std::vector<Color> column;
		for (int j = 0; j < mat.rows; j++) {
			if(checkRed(mat.at<cv::Vec3b>(j,i))){
				column.push_back(RED);
				continue;
			} else if (checkBlue(mat.at<cv::Vec3b>(j,i))){
				column.push_back(BLUE);
				continue;
			} else if (checkWhite(mat.at<cv::Vec3b>(j,i))){
				column.push_back(WHITE);
				continue;
			}
			column.push_back(OTHER);
		}
		colors.push_back(column);
	}

	return colors;
}

bool SegmentationProcessor::checkRed(cv::Vec3b &vec) {
	if(vec[0] < 100 && vec[1] < 100 && vec[2] < 255 && vec[2] > 200){
		return true;
	}
	return false;
}

bool SegmentationProcessor::checkBlue(cv::Vec3b &vec) {
	if(vec[0] < 255 && vec[0] > 200 && vec[1] < 100 && vec[2] < 100){
		return true;
	}
	return false;
}

bool SegmentationProcessor::checkWhite(cv::Vec3b &vec) {
	if(vec[0] > 200 && vec[1] > 200 && vec[2] > 200){
		return true;
	}
	return false;
}

