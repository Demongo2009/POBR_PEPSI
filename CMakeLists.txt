cmake_minimum_required(VERSION 3.20)
project(POBR_PEPSI)
find_package( OpenCV REQUIRED )

set(CMAKE_PREFIX_PATH ~/opencv/build)
set(OpenCV_DIR ~/opencv/build)
set(OpenCV_FOUND 1)
set(CMAKE_CXX_STANDARD 17)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(POBR_PEPSI src/main.cpp src/SegmentDescriptor.cpp src/SegmentDescriptor.h src/ScalingAlgorithmType.h src/Scalers/NearestNeighbour.cpp src/Scalers/NearestNeighbour.h src/Scalers/Bilinear.cpp src/Scalers/Bilinear.h src/Scalers/IScaler.cpp src/Scalers/IScaler.h)
