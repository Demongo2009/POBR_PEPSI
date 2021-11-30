//
// Created by demongo on 28.11.2021.
//

#ifndef POBR_PEPSI_IFILTER_H
#define POBR_PEPSI_IFILTER_H

#include <opencv2/core/mat.hpp>

class IFilter {

public:
	virtual ~IFilter() {};

	virtual void filter(cv::Mat &mat) = 0;
};

#endif //POBR_PEPSI_IFILTER_H
