#include "include/figure.h"
#include "include/triangle.h"
#include "include/octagon.h"
#include "include/square.h"

int main() {
    int n;
    std::cout << "Введите количество фигур: ";
    std::cin >> n;
    Figure* figures[n];
    for (int i = 0; i < n; ++i) {
        std::string task;
        std::cout << "Введите тип фигуры" << std::endl;
        std::cin >> task;
        if (task == "help" || task == "Help") {
            std::cout << "Ввeдите triangle для треугольника" << std::endl;
            std::cout << "Ввeдите square для квадрата" << std::endl;
            std::cout << "Ввeдите octagon для 8-миугольника" << std::endl;
            --i;
        }
        else if (task == "triangle") {
            figures[i] = new Triangle();
            std::cin >> *static_cast<Triangle*>(figures[i]);
        }
        else if (task == "octagon") {
            figures[i] = new Octagon();
            std::cin >> *static_cast<Octagon*>(figures[i]);
        }
        else if (task == "square") {
            figures[i] = new Square();
            std::cin >> *static_cast<Square*>(figures[i]);
        }
        else {
            std::cout << "Неизвестная команда попробуйте использовать help" << std::endl;
            --i;
        }
    }
    long double Area_union = 0; 
    for (int i = 0; i < n; i++) {
        std::cout << "Площадь " << i + 1 << " фигуры = " << figures[i]->Area();
        std::cout << ". Центр фигуры = " << figures[i]->Center() << std::endl;
        Area_union += figures[i]->Area();
    }
    std::cout << "Общая площадь фигур = " << Area_union;
}