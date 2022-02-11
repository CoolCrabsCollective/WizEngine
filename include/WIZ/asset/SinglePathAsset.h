//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_SINGLEPATHASSET_H
#define GAMETEMPLATE_SINGLEPATHASSET_H

#include <string>
#include <utility>
#include "Asset.h"

namespace wiz {
	template <typename T>
	class SinglePathAsset;
}

template <typename T>
class wiz::SinglePathAsset : public wiz::Asset<T> {
protected:
    const std::string path;
public:
    explicit SinglePathAsset(std::string path);

    const std::string& getName() const override;

};

template<typename T>
wiz::SinglePathAsset<T>::SinglePathAsset(std::string path)
    : path(std::move(path)) {}

template<typename T>
const std::string& wiz::SinglePathAsset<T>::getName() const {
    return path;
}


#endif //GAMETEMPLATE_SINGLEPATHASSET_H
