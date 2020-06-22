#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(Properties* props);

    void Draw();
    void Update(float dt);
    void Clean();
private:
    int m_Row, m_Frame, m_FrameCount;
    int m_AnimationSpeed;
};

#endif