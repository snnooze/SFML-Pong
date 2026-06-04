#include "MyHelpers.hpp"

MyHelpers::MyHelpers() {

}

MyHelpers::~MyHelpers() = default;

sf::Vector2f MyHelpers::normalize(sf::Vector2f v) {

    float norme = std::sqrt(v.x*v.x + v.y*v.y);

    if (norme != 0) {

        v = v / norme;
    }

    return v;

}
