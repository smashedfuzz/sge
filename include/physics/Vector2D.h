#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <string>
#include <iostream>

class Vector2D
{
public:
    float X,Y;
public:
    Vector2D(float x = 0, float y = 0): X(x), Y(y) {}
    // Addition
    inline Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(X + v2.X, Y + v2.Y);
    }
    // Substraction
    inline Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(X - v2.X, Y - v2.Y);
    }
    // Scalar Multiplication
    inline Vector2D operator*(const float& s) const {
        return Vector2D(X * s, Y * s);
    }
    void log(std::string mag = "")
    {
        std::cout << mag << "(X, Y) = (" << X << ", " << Y << ")" << std::endl;
    }
private:
    
};

#endif