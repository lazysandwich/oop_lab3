#ifndef SQUAR_H
#define SQUAR_H

#include "figure.h"
#include "octagon.h"

double max_x4(double a, double b, double c, double d);
double min_x4(double a, double b, double c, double d);

class Square : public Figure {

    public:
        Square() = default;
        Square(const Point& a, const Point& b, const Point& c, const Point& d);

        double Area() const override {
            double a = std::sqrt((point1.x - point2.x) * (point1.x - point2.x) +
                (point1.y - point2.y) * (point1.y - point2.y));
            double b = std::sqrt((point3.x - point2.x) * (point3.x - point2.x) +
                (point3.y - point2.y) * (point3.y - point2.y));
            a = std::min(a, b);
            double s = a * a;
            return s;
        }

        Point Center() const override {
            double x = (point1.x + point2.x + point3.x + point4.x) / 4;
            double y = (point1.y + point2.y + point3.y + point4.y) / 4;
            Point center(x, y);
            return center;
        }

        void Print(std::ostream& os) const override {
            os << "Квадрат" << point1 << " " << point2 << " " << point3 << " " << point4;
        }

        void Read(std::istream& is) override {
            is >> point1 >> point2 >> point3 >> point4;
        }

        bool operator==(const Figure& right) const override;

        Square& operator=(const Figure& right) override;

        ~Square();
        
    private:
        Point point1, point2, point3, point4;
};

#endif