//
// Created by demongo on 28.11.2021.
//

#ifndef POBR_PEPSI_LOWPASS_H
#define POBR_PEPSI_LOWPASS_H

#include "IFilter.h"

namespace Filters{
	class Lowpass: public IFilter{

	public:
		Lowpass(){};

		void filter(cv::Mat &mat) override;
	};
}



#endif //POBR_PEPSI_LOWPASS_H
