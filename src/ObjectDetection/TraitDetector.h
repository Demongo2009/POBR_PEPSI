//
// Created by demongo on 31.12.2021.
//

#ifndef POBR_PEPSI_TRAITDETECTOR_H
#define POBR_PEPSI_TRAITDETECTOR_H


#include <vector>
#include <map>
#include "../enums.h"
#include "../Segmentators/SegmentDescriptor.h"

class TraitDetector {

public:
	void
	detectTraitsAndFilter(std::vector<SegmentDescriptor> &vector, std::map<Color, std::vector<SegmentDescriptor>>& map1);

	std::vector<double> getNorms(SegmentDescriptor descriptor);

	void detectTraits(std::vector<SegmentDescriptor> &segments, std::map<Color, std::vector<SegmentDescriptor>> &bins);
};


#endif //POBR_PEPSI_TRAITDETECTOR_H
