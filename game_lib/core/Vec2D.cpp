#include "Vec2D.h"

const Vec2D
        null(0, 0),
        one(1, 1),
        up(0, -1),
        down(0, 1),
        rigth(1, 0),
        left(-1, 0);

bool operator==(Vec2D v1, Vec2D v2) {
    return v1.x == v2.x && v1.y == v2.y;
}

bool operator!=(Vec2D v1, Vec2D v2) {
    return !(v1 == v2);
}

bool operator>(Vec2D v1, Vec2D v2) {
    return v1.x > v2.x && v1.y > v2.y;
}

bool operator<(Vec2D v1, Vec2D v2) {
    return v1.x < v2.x && v1.y < v2.y;
}

bool operator>=(Vec2D v1, Vec2D v2) {
    return v1.x >= v2.x && v1.y >= v2.y;
}

bool operator<=(Vec2D v1, Vec2D v2) {
    return v1.x <= v2.x && v1.y <= v2.y;
}

Vec2D operator-(Vec2D v) {
    return Vec2D(-v.x, -v.y);
}

Vec2D operator+(Vec2D v1, Vec2D v2) {
    return Vec2D(v1.x + v2.x, v1.y + v2.y);
}

Vec2D operator-(Vec2D v1, Vec2D v2) {
    return Vec2D(v1.x - v2.x, v1.y - v2.y);
}

void operator+=(Vec2D &v1, Vec2D v2) {
    v1 = v1 + v2;
}

void operator-=(Vec2D &v1, Vec2D v2) {
    v1 = v1 - v2;
}

Vec2D operator/(Vec2D v, int c) {
    return Vec2D(v.x / c, v.y / c);
}

Vec2D operator*(Vec2D v, int c) {
    return Vec2D(v.x * c, v.y * c);
}

Vec2D operator*(int c, Vec2D v) {
    return v * c;
}

std::ostream &operator<<(std::ostream &os, const Vec2D &v) {
    os << v.toString();
    return os;
}

std::string Vec2D::toString() const {
    return "x: " + std::to_string(x) + " y: " + std::to_string(y);
}
