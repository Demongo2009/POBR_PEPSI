//
// Created by demongo on 30.11.2021.
//

#ifndef POBR_PEPSI_BOUNDINGBOX_H
#define POBR_PEPSI_BOUNDINGBOX_H


class BoundingBox {
	int x1;
	int y1;
	int x2;
	int y2;
public:
	BoundingBox():x1(0),x2(0),y1(0),y2(0){};
	BoundingBox(int x1, int y1, int x2, int y2);

	int getX1() const;

	void setX1(int x1);

	int getY1() const;

	void setY1(int y1);

	int getX2() const;

	void setX2(int x2);

	int getY2() const;

	void setY2(int y2);

};


#endif //POBR_PEPSI_BOUNDINGBOX_H
