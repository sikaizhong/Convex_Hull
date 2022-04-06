#ifndef VEC_
#define VEC_

class Vec {
public:
	double x;
	double y;
public:
	Vec(double x, double y) { this->x = x; this->y = y; }
	Vec() = default;
	double getX() { return x; }
	double getY() { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

};


#endif 