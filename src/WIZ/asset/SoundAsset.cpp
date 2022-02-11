//
// Created by Alexander Winter on 2022-02-11.
//

#include <stdexcept>
#include "WIZ/asset/SoundAsset.h"

wiz::SoundAsset::SoundAsset(const std::string& path)
    : SinglePathAsset(path) {}

void* wiz::SoundAsset::load() const {
    auto* sound = new sf::SoundBuffer();

    if(!sound->loadFromFile(path))
        throw std::runtime_error("Failed to load sound " + path);

    return sound;
}