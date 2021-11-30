//
// Created by demongo on 16.11.2021.
//

#ifndef POBR_PEPSI_SEGMENTDESCRIPTOR_H
#define POBR_PEPSI_SEGMENTDESCRIPTOR_H


#include <vector>
#include "enums.h"
#include "BoundingBox.h"

class SegmentDescriptor {
	BoundingBox boundingBox;
	int area;
	Color color;
	double widthHeightRatio;

public:
	SegmentDescriptor(std::vector<std::pair<int, int>> segment, Color color);

	const BoundingBox &getBoundingBox() const;

	void setBoundingBox(const BoundingBox &boundingBox);

	int getArea() const;

	void setArea(int area);

	Color getColor() const;

	void setColor(Color color);

	double getWidthHeightRatio() const;

	void setWidthHeightRatio(double widthHeightRatio);
};


#endif //POBR_PEPSI_SEGMENTDESCRIPTOR_H
