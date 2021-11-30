//
// Created by demongo on 30.11.2021.
//

#ifndef POBR_PEPSI_HIGHPASS_H
#define POBR_PEPSI_HIGHPASS_H

#include "IFilter.h"

namespace Filters {
	class Highpass: public IFilter{
	public:
		Highpass(){};

		void filter(cv::Mat &mat) override;
	};
}


#endif //POBR_PEPSI_HIGHPASS_H
