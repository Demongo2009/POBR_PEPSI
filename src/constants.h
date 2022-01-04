//
// Created by demongo on 28.11.2021.
//

#ifndef POBR_PEPSI_CONSTANTS_H
#define POBR_PEPSI_CONSTANTS_H

const int RESIZED_WIDTH = 800;

const int RESIZED_HEIGHT = 600;
const int SEGMENT_SIZE_THRESHOLD = 70;

const double RED_NORM2_MODEL = 0.00880989;
const double RED_NORM2_THRESHOLD = 0.1;
const double RED_NORM3_MODEL = 0.000302999;
const double RED_NORM3_THRESHOLD = 0.1;
const double RED_NORM4_MODEL = 1.33354e-05;
const double RED_NORM4_THRESHOLD = 0.1;
const double RED_NORM5_MODEL =  5.82871e-10;
const double RED_NORM5_THRESHOLD = 0.1;
const double RED_NORM6_MODEL = 1.19548e-06;
const double RED_NORM6_THRESHOLD = 0.1;
const double RED_WH_MODEL = 0.907895;
const double RED_WH_THRESHOLD = 0.8;


const double BLUE_NORM2_MODEL = 0.0704934;
const double BLUE_NORM2_THRESHOLD = 0.1;
const double BLUE_NORM3_MODEL =  0.0135358;
const double BLUE_NORM3_THRESHOLD = 0.1;
const double BLUE_NORM4_MODEL = 0.00230727;
const double BLUE_NORM4_THRESHOLD = 0.1;
const double BLUE_NORM5_MODEL = 1.70565e-06;
const double BLUE_NORM5_THRESHOLD = 0.1;
const double BLUE_NORM6_MODEL = 0.000346307;
const double BLUE_NORM6_THRESHOLD = 0.1;
const double BLUE_WH_MODEL = 0.791667;
const double BLUE_WH_THRESHOLD = 0.5;

const double WHITE_NORM2_MODEL = 0.0160034;
const double WHITE_NORM2_THRESHOLD = 0.3;
const double WHITE_NORM3_MODEL =  0.023927;
const double WHITE_NORM3_THRESHOLD = 0.3;
const double WHITE_NORM4_MODEL = 0.0161113;
const double WHITE_NORM4_THRESHOLD = 0.3;
const double WHITE_NORM5_MODEL = 0.000315054;
const double WHITE_NORM5_THRESHOLD = 0.3;
const double WHITE_NORM6_MODEL = 0.00193439;
const double WHITE_NORM6_THRESHOLD = 0.3;
const double WHITE_WH_MODEL = 0.913681;
const double WHITE_WH_THRESHOLD = 0.7;

const double RED_BLUE_WH_MODEL = 0.912434;
const double RED_BLUE_WH_THRESHOLD = 0.9;

const double HEIGHT_DISTANCE_MODEL = 0.539109;
const double DISTANCE_THRESHOLD = 30;

typedef enum ScalingAlgorithmType{NearestNeighbour, Bilinear}ScalingAlgorithmType;
typedef enum FilteringAlgorithmType{Median, Lowpass}FilteringAlgorithmType;


#endif //POBR_PEPSI_CONSTANTS_H
