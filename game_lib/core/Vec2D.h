#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Stringable.h"

struct Vec2D : public Stringable {
    int x = 0, y = 0;

    Vec2D() = default;

    Vec2D(int x, int y) : x(x), y(y) {}

    friend bool operator==(Vec2D v1, Vec2D v2);

    friend bool operator!=(Vec2D v1, Vec2D v2);

    friend bool operator>(Vec2D v1, Vec2D v2);

    friend bool operator<(Vec2D v1, Vec2D v2);

    friend bool operator>=(Vec2D v1, Vec2D v2);

    friend bool operator<=(Vec2D v1, Vec2D v2);

    friend Vec2D operator-(Vec2D v);

    friend Vec2D operator+(Vec2D v1, Vec2D v2);

    friend Vec2D operator-(Vec2D v1, Vec2D v2);

    friend void operator+=(Vec2D &v1, Vec2D v2);

    friend void operator-=(Vec2D &v1, Vec2D v2);

    friend Vec2D operator/(Vec2D v, int c);

    friend Vec2D operator*(Vec2D v, int c);

    friend Vec2D operator*(int c, Vec2D v);

    friend std::ostream &operator<<(std::ostream &os, const Vec2D &v);

    std::string toString() const override;
};

extern const Vec2D null, one, up, down, right, left;


#endif //POINT_H
