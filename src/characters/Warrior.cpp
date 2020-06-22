#include "characters/Warrior.h"
#include "graphics/TextureManager.h"
#include "SDL2/SDL.h"

Warrior::Warrior(Properties* props) : Character(props)
{
    m_Row = 0;
    m_FrameCount = 6;
    m_AnimationSpeed = 80;
}

void Warrior::Draw()
{
    TextureManager::GetInstance()->DrawFrame(
        m_TextureID,
        m_Transform->position.X,
        m_Transform->position.Y,
        m_Width,
        m_Height,
        m_Row,
        m_Frame
    );
}

void Warrior::Update(float dt)
{
    if (dt > 324) printf("Hello");
    m_Frame = (SDL_GetTicks()/m_AnimationSpeed)%m_FrameCount;
}

void Warrior::Clean()
{
    TextureManager::GetInstance()->Clean();
}