#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

double max_x4(double a, double b, double c, double d);
double min_x4(double a, double b, double c, double d);

class Octagon : public Figure {

    public:
        Octagon() = default;
        Octagon(const Point (&a)[8]);

        double Area() const override {
            double a = std::sqrt((point[1].x - point[0].x) * (point[1].x - point[0].x) + (point[1].y - point[0].y) * (point[1].y - point[0].y));
            double s = 2 * a * a * (1 + sqrt(2));
            return s;
        }

        Point Center() const override {
            double x = 0;
            double y = 0;
            for (int i = 0; i < 8; ++i) {
                x += point[i].x;
                y += point[i].y;
            }
            x /= 8;
            y /= 8;
            Point center(x, y);
            return center;
        }

        void Print(std::ostream& os) const override {
            os << "Квадрат";
            for (int i = 0; i < 8; ++i) {
                os << point[i];
                if (i != 7) {
                    os << " ";
                }
            }
        }

        void Read(std::istream& is) override {
            for (int i = 0; i < 8; ++i) {
                is >> point[i];
            }
        }

        ~Octagon();

        bool operator==(const Figure& right) const override;

        Octagon& operator=(const Figure& right) override;
        
    private:
        Point point[8];
};

#endif