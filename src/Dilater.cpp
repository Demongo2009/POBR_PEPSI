//
// Created by demongo on 03.01.2022.
//

#include "Dilater.h"
#include "SegmentationProcessor.h"

void Dilater::dilate(cv::Mat &image) {
	int imageWidth = image.cols;
	int imageHeight = image.rows;
//	cv::Mat filtered(imageHeight, imageWidth, image.type());
	cv::Mat_<cv::Vec3b> filtered = image.clone();

	cv::Mat_<cv::Vec3b> filtered_(filtered);

	for(int i=0; i<imageWidth; i++) {
		for (int j=0; j < imageHeight; j++) {
			int pointx = i;
			int pointy = j;

			for(int x=0; x<3; x++){
				for(int y=0; y<3; y++){
					if(x==1 && y==1) {
						continue;
					}

					int neighbourX = pointx + x -1;
					int neighbourY = pointy + y -1;

					if(neighbourX < 0 || neighbourY < 0 || neighbourX >= imageWidth || neighbourY >= imageHeight){
						continue;
					}

					cv::Vec3b vec = image.at<cv::Vec3b>(neighbourY, neighbourX);

					if(SegmentationProcessor::checkWhite(vec)){
						filtered_[pointy][pointx] = cv::Vec3b((uchar)255,(uchar)255,(uchar)255);
					}
				}
			}
		}
	}
	image = filtered;
}
