//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_TEXTUREASSET_H
#define GAMETEMPLATE_TEXTUREASSET_H


#include <string>
#include "SinglePathAsset.h"
#include "SFML/Graphics/Texture.hpp"

namespace wiz {
	class TextureAsset;
}

class wiz::TextureAsset : public wiz::SinglePathAsset<sf::Texture> {
public:
    TextureAsset(std::string path);

    ~TextureAsset() override = default;

    void* load() const override;
};


#endif //GAMETEMPLATE_TEXTUREASSET_H
