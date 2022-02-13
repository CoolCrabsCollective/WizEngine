//
// Created by Alexander Winter on 2022-02-11.
//

#include "WIZ/asset/TextureAsset.h"

#include <utility>
#include <stdexcept>

wiz::TextureAsset::TextureAsset(std::string path)
    : SinglePathAsset(std::move(path)) {}

void* wiz::TextureAsset::load() const {
    auto* texture = new sf::Texture();

#ifdef OS_SWITCH
	if(!texture->loadFromFile("romfs:/" + path))
#else
	if(!texture->loadFromFile("res/" + path))
#endif
        throw std::runtime_error("Failed to load texture " + path);

    return texture;
}

