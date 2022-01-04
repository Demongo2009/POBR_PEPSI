//
// Created by demongo on 31.12.2021.
//

#ifndef POBR_PEPSI_OBJECTRECOGNISER_H
#define POBR_PEPSI_OBJECTRECOGNISER_H


#include <vector>
#include <map>
#include <opencv2/core/mat.hpp>
#include "enums.h"
#include "SegmentDescriptor.h"

class ObjectRecogniser {

public:
	std::vector<SegmentDescriptor> recogniseObject( cv::Mat& image, std::map<Color, std::vector<SegmentDescriptor>>& map1);

	std::vector<SegmentDescriptor> findRedBluePart( std::map<Color, std::vector<SegmentDescriptor>>& vector1);

	std::vector<SegmentDescriptor>
	findWhiteBackground( cv::Mat& image, std::vector<SegmentDescriptor> vector1, std::map<Color, std::vector<SegmentDescriptor>>& map);

	std::vector<SegmentDescriptor> learnObject(std::map<Color, std::vector<SegmentDescriptor>> &bins);
};


#endif //POBR_PEPSI_OBJECTRECOGNISER_H
