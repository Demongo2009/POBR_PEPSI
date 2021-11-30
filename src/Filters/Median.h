//
// Created by demongo on 28.11.2021.
//

#ifndef POBR_PEPSI_MEDIAN_H
#define POBR_PEPSI_MEDIAN_H

#include "IFilter.h"

namespace Filters{
	class Median: public IFilter{
	public:
		Median(){};

		void filter(cv::Mat &mat) override;

	};
}



#endif //POBR_PEPSI_MEDIAN_H
