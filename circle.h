#include <ostream>

class Point {
	float x;
	float y;

public:
	Point() : x(0), y(0) {};
	Point(float x, float y) : x(x), y(y) {};

	bool operator==(const Point& other);

	float getX() const;
	float getY() const;
};


class Circle {
	Point centre;
	float radius;

public:
	Circle() : radius(0) {};
	Circle(Point c, float r) : centre(c), radius(r) {};
	Circle(float x, float y, float r) : centre(Point(x, y)), radius(r) {};

	bool operator==(const Circle& other);
	float getArea();
	friend std::ostream& operator<<(std::ostream& os, const Circle& circle);

};