#ifndef POINTS_H
#define POINTS_H
#include <iostream>

class Point {

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);

    public:
        Point() = default;

        Point(double coordinat_x, double coordinat_y) {
            y = coordinat_y;
            x = coordinat_x;
        }

        Point(const Point&) = default;

        bool operator==(const Point& right) const {
            return x == right.x && y == right.y;
        }

        void operator=(const Point& right) {
            x = right.x;
            y = right.y;
        }

        ~Point();

        double x{};
        double y{};
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

inline std::istream& operator>>(std::istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}

#endif