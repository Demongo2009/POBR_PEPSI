//
// Created by demongo on 16.11.2021.
//

#ifndef POBR_PEPSI_NEARESTNEIGHBOUR_H
#define POBR_PEPSI_NEARESTNEIGHBOUR_H

#include "IScaler.h"

namespace Scalers{
	class NearestNeighbour: public IScaler {

	public:
		NearestNeighbour(){}

		virtual void scale(cv::Mat &mat) override;
	};
}



#endif //POBR_PEPSI_NEARESTNEIGHBOUR_H
