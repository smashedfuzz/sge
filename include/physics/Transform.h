#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector2D.h"
#include <iostream>

class Transform
{
public:
    Vector2D position;
    float rotation;
public:
    Transform(Vector2D p = Vector2D(0,0),float r = 0) {position = p; rotation = r;}
    Transform(float x = 0, float y = 0,float r = 0) {position = Vector2D(x, y); rotation = r;}
    inline void Translate(Vector2D v) {position = position + v;}
    inline void Rotate(float r) {rotation += r;}
    void log()
    {
        std::cout << "Transform (X,Y) (R) = (" << position.X << ", " << position.Y << ") (" << rotation << ")" << std::endl;
    }
private:

};

#endif