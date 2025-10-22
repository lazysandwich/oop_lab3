#include "../include/octagon.h"
#include "../include/figure.h"

Octagon::Octagon(const Point (&a)[8])
{
    for (int i = 0; i < 8; ++i) {
        point[i] = a[i];
    }
}

Octagon::~Octagon() {
}

bool Octagon::operator==(const Figure& right) const {
    const Octagon* octagon = dynamic_cast<const Octagon*>(&right);
    int amount_of_considences = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (point[i] == octagon->point[j])
                amount_of_considences++;
        }
    }
    bool ans = amount_of_considences == 8;
    return ans;
}

Octagon& Octagon::operator=(const Figure& right) {
    const Octagon* octagon = dynamic_cast<const Octagon*>(&right);
    for (int i = 0; i < 8; ++i) {
        point[i] = octagon->point[i];
    }
    return *this;
}