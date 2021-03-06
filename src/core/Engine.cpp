#include "core/Engine.h"
#include "graphics/TextureManager.h"
#include "characters/Warrior.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        SDL_Log("Fallo la inicializacion de SDL: %s", SDL_GetError());
        return false;
    }
    m_Window = SDL_CreateWindow(
        "Smashed Game Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0);
    if (m_Window == nullptr)
    {
        SDL_Log("Fallo la creacion de la ventana. %s", SDL_GetError());
        return false;
    }
    m_Renderer = SDL_CreateRenderer(
        m_Window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == nullptr)
    {
        SDL_Log("Fallo la creacion del renderizador. %s", SDL_GetError());
    }

    TextureManager::GetInstance()->Load("player", "assets/tilemap/tileset.png");
    player = new Warrior(new Properties("player", 250, 250, 0, 8, 8));
    
    return m_IsRunning = true;
}

/*
*
* Cleans all the memory used by the engine
*
*/
bool Engine::Clean()
{
    SDL_Log("Clearing memory ...");
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
    IMG_Quit();
    TextureManager::GetInstance()->Clean();
    SDL_Log("Memory Cleared !");
    return true;
}

void Engine::Quit()
{
    m_IsRunning = false;
}

void Engine::Events()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT) Quit();
    }
}

void Engine::Update(float dt)
{
    player->Update(dt);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(m_Renderer);
    player->Draw();
    SDL_RenderPresent(m_Renderer);
}

Engine::Engine()
{
}
