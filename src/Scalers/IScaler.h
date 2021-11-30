//
// Created by demongo on 16.11.2021.
//

#ifndef POBR_PEPSI_ISCALER_H
#define POBR_PEPSI_ISCALER_H


#include <opencv2/core/mat.hpp>

class IScaler {

public:
	virtual ~IScaler() {};

	virtual void scale(cv::Mat &mat) = 0;
};


#endif //POBR_PEPSI_ISCALER_H
