//
// Created by demongo on 03.01.2022.
//

#ifndef POBR_PEPSI_HISTOGRAMEQUALIZER_H
#define POBR_PEPSI_HISTOGRAMEQUALIZER_H


#include <opencv2/core/mat.hpp>

class HistogramEqualizer {

public:
	void equalize(cv::Mat &mat);

	const std::array<int, 256> createLookuptable(const std::array<int, 256> histogram, const int pixelCount) const;

	cv::Mat &applyLUT(cv::Mat &image, const std::array<int, 256> lut) const;

	const std::array<int, 256> createHistogram(cv::Mat &image) const;
};


#endif //POBR_PEPSI_HISTOGRAMEQUALIZER_H
