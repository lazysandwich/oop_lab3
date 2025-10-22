#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
    private:
        Point point1, point2, point3;

    public:
        Triangle() = default;
        Triangle(const Point& a, const Point& b, const Point& c);

        double Area() const override {
            double a = std::sqrt((point1.x - point2.x) * (point1.x - point2.x) +
                (point1.y - point2.y) * (point1.y - point2.y));
            double b = std::sqrt((point3.x - point2.x) * (point3.x - point2.x) +
                (point3.y - point2.y) * (point3.y - point2.y));
            double c = std::sqrt((point3.x - point1.x) * (point3.x - point1.x) +
                (point3.y - point1.y) * (point3.y - point1.y));
            double p = (a + b + c) / 2;
            double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
            return s;
        }

        Point Center() const override {
            double center_x = (point1.x + point2.x + point3.x) / 3;
            double center_y = (point1.y + point2.y + point3.y) / 3;
            Point center({center_x, center_y});
            return center;
        }

        void Print(std::ostream& os) const override {
            os << "Треугольник" << point1 << " " << point2 << " " << point3;
        }

        void Read(std::istream& is) override {
            is >> point1 >> point2 >> point3;
        }

        bool operator==(const Figure& right) const override;

        Triangle& operator=(const Figure& right) override;

        ~Triangle();
};

#endif