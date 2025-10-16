#include "triangle.h"
#include "octagon.h"
#include "square.h"

int main() {
    Triangle a, b;
    std::cout << "Введите координаты 3-х вершин треугольника 1" << std::endl;
    std::cin >> a;
    std::cout << "Площадь треугольника 1 = " << a.Area() << std::endl;
    std::cout << "Центр треугольника 1: " << a.Center() << std::endl;
    std::cout << "Введите координаты 3-х вершин треугольника 2" << std::endl;
    std::cin >> b;
    std::cout << "Площадь треугольника 2 = " << b.Area() << std::endl;
    std::cout << "Центр треугольника 2: " << b.Center() << std::endl;
    std::cout << "1 и 2 треугольник " << (a == b ? "Равны" : "Неравны") << std::endl;

    Square c, d;
    std::cout << "Введите координаты 4-х вершин квадрата 1" << std::endl;
    std::cin >> c;
    std::cout << "Площадь квадрата 1 = " << c.Area() << std::endl;
    std::cout << "Центр квадрата 1: " << c.Center() << std::endl;
    std::cout << "Введите координаты 4-х вершин квадрата 2" << std::endl;
    std::cin >> d;
    std::cout << "Площадь квадрата 2 = " << d.Area() << std::endl;
    std::cout << "Центр квадрата 2: " << d.Center() << std::endl;
    std::cout << "1 и 2 квадрат " << (c == d ? "Равны" : "Неравны") << std::endl;

    Octagon e, f;
    std::cout << "Введите координаты 8-ми вершин 8-миугольника 1" << std::endl;
    std::cin >> e;
    std::cout << "Площадь 8-миугольника 1 = " << e.Area() << std::endl;
    std::cout << "Центр 8-миугольника 1: " << e.Center() << std::endl;
    std::cout << "Введите координаты 8-ми вершин 8-миугольника 2" << std::endl;
    std::cin >> f;
    std::cout << "Площадь 8-миугольника 2 = " << f.Area() << std::endl;
    std::cout << "Центр 8-миугольника 2: " << f.Center() << std::endl;
    std::cout << "1 и 2 треугольник " << (e == f ? "Равны" : "Неравны") << std::endl;
}