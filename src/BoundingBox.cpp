//
// Created by demongo on 30.11.2021.
//

#include "BoundingBox.h"

int BoundingBox::getX1() const {
	return x1;
}

void BoundingBox::setX1(int x1) {
	BoundingBox::x1 = x1;
}

int BoundingBox::getY1() const {
	return y1;
}

void BoundingBox::setY1(int y1) {
	BoundingBox::y1 = y1;
}

int BoundingBox::getX2() const {
	return x2;
}

void BoundingBox::setX2(int x2) {
	BoundingBox::x2 = x2;
}

int BoundingBox::getY2() const {
	return y2;
}

void BoundingBox::setY2(int y2) {
	BoundingBox::y2 = y2;
}

BoundingBox::BoundingBox(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
