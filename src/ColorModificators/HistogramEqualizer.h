//
// Created by demongo on 03.01.2022.
//

#ifndef POBR_PEPSI_HISTOGRAMEQUALIZER_H
#define POBR_PEPSI_HISTOGRAMEQUALIZER_H


#include <opencv2/core/mat.hpp>

class HistogramEqualizer {
	std::array<int, 256> createLookuptable(std::array<int, 256> histogram, int pixelCount);

	void applyLUT(cv::Mat &image, std::array<int, 256> lut);

	static std::array<int, 256> createHistogram(cv::Mat &image) ;
public:
	void equalize(cv::Mat &mat);

};


#endif //POBR_PEPSI_HISTOGRAMEQUALIZER_H
