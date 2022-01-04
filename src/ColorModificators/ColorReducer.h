//
// Created by demongo on 03.01.2022.
//

#ifndef POBR_PEPSI_COLORREDUCER_H
#define POBR_PEPSI_COLORREDUCER_H


#include <opencv2/core/mat.hpp>

class ColorReducer {
	static std::array<uchar, 256> createLookupTable();
public:
	void reduce(cv::Mat &mat);
};


#endif //POBR_PEPSI_COLORREDUCER_H
