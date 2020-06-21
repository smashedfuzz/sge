#include "core/Engine.h"
//int argc, char** argv

int main ()
{
    Engine* engine = Engine::GetInstance();
    engine->Init();
    while (engine->IsRunning())
    {
        engine->Events();
        engine->Update(0.0);
        engine->Render();
    }
    engine->Clean();
    return 0;
}