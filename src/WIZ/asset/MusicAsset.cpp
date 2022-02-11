//
// Created by Alexander Winter on 2022-02-11.
//

#include "WIZ/asset/MusicAsset.h"


wiz::MusicAsset::MusicAsset(const std::string& path)
        : SinglePathAsset(path) {}

void* wiz::MusicAsset::load() const {
    auto* music = new sf::Music();

    if(!music->openFromFile(path))
        throw std::runtime_error("Failed to load music " + path);

    return music;
}
