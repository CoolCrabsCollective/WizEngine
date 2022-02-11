//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_ASSET_H
#define GAMETEMPLATE_ASSET_H

#include "AssetBase.h"

namespace wiz {
	template <typename T>
	class Asset;
}

template <typename T>
class wiz::Asset : public wiz::AssetBase {
public:
    void dispose(void* data) const override {
        delete (T*)data;
    }
};


#endif //GAMETEMPLATE_ASSET_H
