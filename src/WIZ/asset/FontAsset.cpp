//
// Created by Alexander Winter on 2022-02-11.
//

#include <stdexcept>
#include "WIZ/asset/FontAsset.h"

wiz::FontAsset::FontAsset(const std::string& path)
    : SinglePathAsset(path) {}

void* wiz::FontAsset::load() const {
    auto* font = new sf::Font();

#ifdef OS_SWITCH
    if(!font->loadFromFile("romfs:/" + path))
#else
	if(!font->loadFromFile("res/" + path))
#endif
        throw std::runtime_error("Failed to load font " + path);

    return font;
}
