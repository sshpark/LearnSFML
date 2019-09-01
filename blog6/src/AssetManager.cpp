#include "AssetManager.hpp"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager() {
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename) {
    auto& texMap = sInstance->m_Textures;
    
    auto pairFound = texMap.find(filename);
    if (pairFound != texMap.end()) {
        return pairFound->second;
    }
    
    auto& texture = texMap[filename];
    texture.loadFromFile(filename);
    return texture;
}