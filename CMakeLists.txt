cmake_minimum_required(VERSION 3.20)
project(POBR_PEPSI)
#find_package( OpenCV REQUIRED )

#set(CMAKE_PREFIX_PATH ~/opencv/build)
#
#set(OpenCV_FOUND 1)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_LINKER_WRAPPER_FLAG  `pkg-config opencv --cflags --libs`)
SET(OpenCV_DIR /home/demongo/opencv/opencv/build/share/OpenCV/)
find_package(OpenCV REQUIRED)
#SET(OpenCV_INSTALL_PATH /home/demongo/opencv/opencv/build)

#SET(OpenCV_INCLUDE_DIRS "${OpenCV_INSTALL_PATH}/include/opencv;${OpenCV_INSTALL_PATH}/include")

#SET(OpenCV_LIB_DIR "${OpenCV_INSTALL_PATH}/lib")

#LINK_DIRECTORIES(${OpenCV_LIB_DIR})

#set(OpenCV_LIBS opencv_core opencv_imgproc opencv_calib3d opencv_video opencv_features2d opencv_ml opencv_highgui opencv_objdetect opencv_contrib opencv_legacy opencv_gpu)


#include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(POBR_PEPSI src/main.cpp src/SegmentDescriptor.cpp src/SegmentDescriptor.h src/Scalers/NearestNeighbour.cpp src/Scalers/NearestNeighbour.h src/Scalers/Bilinear.cpp src/Scalers/Bilinear.h src/Scalers/IScaler.h src/constants.h src/Filters/IFilter.h src/Filters/Median.cpp src/Filters/Median.h src/Filters/Lowpass.cpp src/Filters/Lowpass.h src/Filters/Highpass.cpp src/Filters/Highpass.h src/SegmentationProcessor.cpp src/SegmentationProcessor.h src/enums.h src/BoundingBox.cpp src/BoundingBox.h src/TraitDetector.cpp src/TraitDetector.h src/ObjectRecogniser.cpp src/ObjectRecogniser.h src/Dilater.cpp src/Dilater.h src/HistogramEqualizer.cpp src/HistogramEqualizer.h src/ColorReducer.cpp src/ColorReducer.h)
target_link_libraries(POBR_PEPSI ${OpenCV_LIBS})