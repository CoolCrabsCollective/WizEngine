//
// Created by Alexander Winter on 2022-02-11.
//

#include <stdexcept>
#include "WIZ/asset/SoundAsset.h"

wiz::SoundAsset::SoundAsset(const std::string& path)
    : SinglePathAsset(path) {}

void* wiz::SoundAsset::load() const {
    auto* sound = new sf::SoundBuffer();

#ifdef OS_SWITCH
	if(!sound->loadFromFile("romfs:/" + path))
#else
	if(!sound->loadFromFile("res/" + path))
#endif
        throw std::runtime_error("Failed to load sound " + path);

    return sound;
}