#include "Vec2D.h"

const Vec2D
        null(0, 0),
        one(1, 1),
        up(0, -1),
        down(0, 1),
        right(1, 0),
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

float Vec2D::norm() {
    return std::sqrt((float) (x * x + y * y));
}

Vec2D Vec2D::getDir() {
    if (std::abs(x) > std::abs(y))
        return Vec2D(x, 0).sgn();
    else if (std::abs(x) < std::abs(y))
        return Vec2D(0, y).sgn();
    else
        return Vec2D(x, y).sgn();
}

Vec2D Vec2D::sgn() {
    return Vec2D(
            (x > 0 ? 1 : (x < 0 ? -1 : 0)),
            (y > 0 ? 1 : (y < 0 ? -1 : 0))
    );
}

std::mt19937 Vec2D::rng(std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());

Vec2D Vec2D::rand(Vec2D bx, Vec2D by) {
    std::uniform_int_distribution<std::mt19937::result_type> xdist(bx.x, bx.y), ydist(by.x, by.y);
    return Vec2D(xdist(Vec2D::rng), ydist(Vec2D::rng));
}
