#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <cmath>
#include "Points.h"

class Figure {
    public:
        Figure() = default;
        Figure(std::string descripton);

        virtual Point Center() const = 0;
        virtual double Area() const = 0;

        virtual bool operator==(const Figure& right) const = 0;

        virtual ~Figure();

        virtual Figure& operator=(const Figure&) = default;
        
    
    private:
        virtual void Print(std::ostream& os) const = 0;
        virtual void Read(std::istream& is) = 0;

    protected:
        std::string descripton;

    friend std::ostream& operator<<(std::ostream& os, const Figure& a) {
        a.Print(os);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Figure& a) {
        a.Read(is);
        return is;
    }
};

#endif