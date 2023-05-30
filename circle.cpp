#include "circle.h"


float Point::getX() const{
    return this->x;
}

float Point::getY() const{
    return this->y;
}

bool Point::operator==(const Point& other) {
	if (this->x == other.x and this->y == other.y) return true;
	else return false;
};

bool Circle::operator==(const Circle& other) {
	if (this->centre == other.centre and this->radius == other.radius) return true;
	else return false;
}


float Circle::getArea() {
	return 3.14 * radius * radius;
}


std::ostream& operator<<(std::ostream& os, const Circle& circle) {
    os << "Centre=(" << circle.centre.getX() << "; " << circle.centre.getY() << ") Radius=" << circle.radius;
    return os;
};

