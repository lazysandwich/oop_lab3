#include "square.h"

double max_x4(double a, double b, double c, double d) {
    double max_1 = std::max(a, b);
    double max_2 = std::max(c, d);
    return std::max(max_1, max_2);
}

double min_x4(double a, double b, double c, double d) {
    double min_1 = std::max(a, b);
    double min_2 = std::max(c, d);
    return std::max(min_1, min_2);
}

Square::Square(const Point& a, const Point& b, const Point& c, const Point& d)
    : point1(a), point2(b), point3(c), point4(d)
{
} 

bool Square::operator==(const Figure& right) const {
    const Square* square = dynamic_cast<const Square*>(&right);

    double max_x_left = max_x4(point1.x, point2.x, point3.x, point4.x);
    double min_x_left = min_x4(point1.x, point2.x, point3.x, point4.x);
    double max_x_right = max_x4(square->point1.y, square->point2.y, square->point3.y, square->point4.y);
    double min_x_right = min_x4(square->point1.y, square->point2.y, square->point3.y, square->point4.y);

    bool ans = (max_x_left == max_x_right) && (min_x_left == min_x_right);

    return ans;
}

Square& Square::operator=(const Figure& right) {
    const Square* square = dynamic_cast<const Square*>(&right);
    point1 = square->point1;
    point2 = square->point2;
    point3 = square->point3;
    point4 = square->point4;
    return *this;
}

Square::~Square() {
}