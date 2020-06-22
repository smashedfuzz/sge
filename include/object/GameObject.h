#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include "IObject.h"
#include <SDL2/SDL.h>
#include "physics/Transform.h"

struct Properties
{
public:
    Properties(std::string textureID, float x, float y, float r, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE)
    {
        X = x;
        Y = y;
        R = r;
        Flip = flip;
        Width = width;
        Height = height;
        TextureID = textureID;
    }

public:
    float X, Y, R;
    int Width, Height;
    std::string TextureID;
    SDL_RendererFlip Flip;
};

class GameObject : public IObject
{
public:
    GameObject(Properties* props) : m_TextureID(props->TextureID), m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip)
    {
        m_Transform = new Transform(props->X, props->Y, props->R);
    }

    virtual void Draw() = 0;
    virtual void Clean() = 0;
    virtual void Update(float dt) = 0;

protected:
    std::string m_TextureID;
    Transform* m_Transform;
    int m_Width, m_Height;
    SDL_RendererFlip m_Flip;
};

#endif