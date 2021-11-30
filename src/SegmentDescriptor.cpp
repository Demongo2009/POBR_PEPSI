//
// Created by demongo on 16.11.2021.
//

#include "SegmentDescriptor.h"
#include <cmath>

SegmentDescriptor::SegmentDescriptor(std::vector<std::pair<int, int>> segment, Color color) {
	this->area = segment.size();
	this->color = color;

	int minX;
	int minY;
	int maxX;
	int maxY;

	for(auto point: segment){
		int x = point.second;
		int y = point.first;

		minX = std::min(x,minX);
		minY = std::min(y,minY);
		maxX = std::max(x,maxX);
		maxY = std::max(x,maxY);
	}
	this->boundingBox = BoundingBox(minX, minY, maxX, maxX);

	this->widthHeightRatio = std::abs(boundingBox.getX1()-boundingBox.getX2()) /
			fmin(std::abs(boundingBox.getY1()-boundingBox.getY2()),1);
}

const BoundingBox &SegmentDescriptor::getBoundingBox() const {
	return boundingBox;
}

void SegmentDescriptor::setBoundingBox(const BoundingBox &boundingBox) {
	SegmentDescriptor::boundingBox = boundingBox;
}

int SegmentDescriptor::getArea() const {
	return area;
}

void SegmentDescriptor::setArea(int area) {
	SegmentDescriptor::area = area;
}

Color SegmentDescriptor::getColor() const {
	return color;
}

void SegmentDescriptor::setColor(Color color) {
	SegmentDescriptor::color = color;
}

double SegmentDescriptor::getWidthHeightRatio() const {
	return widthHeightRatio;
}

void SegmentDescriptor::setWidthHeightRatio(double widthHeightRatio) {
	SegmentDescriptor::widthHeightRatio = widthHeightRatio;
}
