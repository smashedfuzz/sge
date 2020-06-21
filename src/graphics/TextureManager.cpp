#include "graphics/TextureManager.h"
#include "core/Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

TextureManager::TextureManager()
{
}

bool TextureManager::Load(std::string id, std::string filename)
{
    SDL_Surface *surface = IMG_Load(filename.c_str());
    if (surface == nullptr)
    {
        SDL_Log("No se pudo cargar la textura %s. %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    if (texture == nullptr)
    {
        SDL_Log("No se pudo crear la textura %s. %s", filename.c_str(), SDL_GetError());
        return false;
    }

    m_TextureMap[id] = texture;
    SDL_Log("Loaded texture %s!", filename.c_str());
    return true;
}

void TextureManager::Drop(std::string id)
{
    SDL_DestroyTexture(m_TextureMap[id]);
    m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
    SDL_Log("Clearing texture map...");
    std::map<std::string, SDL_Texture*>::iterator it;
    for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
        SDL_DestroyTexture(it->second);
    
    m_TextureMap.clear();
    SDL_Log("Texture map Cleared!");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect dstRect = {x, y, width, height};
    SDL_RenderCopyEx(
        Engine::GetInstance()->GetRenderer(),
        m_TextureMap[id],
        &srcRect,
        &dstRect,
        0,
        NULL,
        flip
    );
}
