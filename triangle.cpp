#include "triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : point1(a), point2(b), point3(c)
{
}

bool Triangle::operator==(const Figure& right) const {
    const Triangle* triangl = dynamic_cast<const Triangle*>(&right);
    bool ans = (point1 == triangl->point1) && (point2 == triangl->point2) && (point3 == triangl->point3);
    ans = ans || ((point1 == triangl->point1) && (point2 == triangl->point3) && (point3 == triangl->point2));
    ans = ans || ((point1 == triangl->point2) && (point2 == triangl->point1) && (point3 == triangl->point3));
    ans = ans || ((point1 == triangl->point2) && (point2 == triangl->point3) && (point3 == triangl->point1));
    ans = ans || ((point1 == triangl->point3) && (point2 == triangl->point1) && (point3 == triangl->point2));
    ans = ans || ((point1 == triangl->point3) && (point2 == triangl->point2) && (point3 == triangl->point1));
    return ans;
}

Triangle& Triangle::operator=(const Figure& right) {
    const Triangle* triangle = dynamic_cast<const Triangle*>(&right);
    point1 = triangle->point1;
    point2 = triangle->point2;
    point3 = triangle->point3;
    return *this;
}

Triangle::~Triangle() {

}