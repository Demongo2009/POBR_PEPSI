//
// Created by demongo on 16.11.2021.
//

#ifndef POBR_PEPSI_BILINEAR_H
#define POBR_PEPSI_BILINEAR_H

#include "IScaler.h"

namespace Scalers{
	class Bilinear: public IScaler {

	public:
		Bilinear(){};

		void scale(cv::Mat &mat) override;
	};
}



#endif //POBR_PEPSI_BILINEAR_H
