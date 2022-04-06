#include"common.h"
bool toTheLeft(Vec&p, Vec&q, Vec&s) {
	return (p.x*q.y - p.y*q.x
		+ q.x*s.y - q.y*s.x
		+ s.x*p.y - s.y*p.x)>0;
}
bool insideTriangle(Vec&a, Vec&b, Vec&c, Vec& s) {
	if (toTheLeft(a, b, s)
		&& toTheLeft(b, c, s)
		&& toTheLeft(c, a, s))// same side;
		return true;
	return false;

}