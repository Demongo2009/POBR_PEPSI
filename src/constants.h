//
// Created by demongo on 28.11.2021.
//

#ifndef POBR_PEPSI_CONSTANTS_H
#define POBR_PEPSI_CONSTANTS_H

const int RESIZED_WIDTH = 800;

const int RESIZED_HEIGHT = 600;
const int SEGMENT_SIZE_THRESHOLD = 200;

typedef enum ScalingAlgorithmType{NearestNeighbour, Bilinear}ScalingAlgorithmType;
typedef enum FilteringAlgorithmType{Median, Lowpass}FilteringAlgorithmType;


#endif //POBR_PEPSI_CONSTANTS_H
