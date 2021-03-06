//
// Created by demongo on 30.11.2021.
//

#ifndef POBR_PEPSI_SEGMENTATIONPROCESSOR_H
#define POBR_PEPSI_SEGMENTATIONPROCESSOR_H


#include <opencv2/core/mat.hpp>
#include "SegmentDescriptor.h"
#include "../enums.h"


typedef std::vector<std::vector<State>> StateMat;
typedef std::vector<std::vector<Color>> ColorMat;
typedef std::vector<std::vector<std::pair<int, int>>> SegmentVector;

class SegmentationProcessor {
	void showSegments(SegmentVector vector1, cv::Mat& mat, ColorMat & colorMat);

	StateMat initializeStateMat(cv::Mat &mat);

	SegmentVector segmentation(ColorMat &mat,
							   StateMat &stateMat);

	SegmentVector filterSegments(
			SegmentVector segmentVector);

	std::vector<SegmentDescriptor> toDescriptors(SegmentVector segmentVector, ColorMat colorMat);

	ColorMat toColors(cv::Mat &mat);
public:
	std::vector<SegmentDescriptor> segmentImage(cv::Mat &mat);

	static bool checkRed(cv::Vec3b &vec);

	static bool checkBlue(cv::Vec3b &vec);

	static bool checkWhite(cv::Vec3b &vec);

};


#endif //POBR_PEPSI_SEGMENTATIONPROCESSOR_H
