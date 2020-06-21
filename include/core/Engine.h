#ifndef ENGINE_H
#define ENGINE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// Singleton Instance for Engine


class Engine
{
public:
    static Engine *GetInstance() {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }
    bool Init();
    bool Clean();
    void Quit();

    void Events();
    void Update(float dt);
    void Render();

    inline bool IsRunning() {return m_IsRunning;}
    inline SDL_Renderer* GetRenderer() {return m_Renderer;}

private:
    Engine();
    bool m_IsRunning;

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    static Engine *s_Instance;
};

#endif