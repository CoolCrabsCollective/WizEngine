//
// Created by Alexander Winter on 2022-09-27.
//

#ifndef WIZENGINE_PATHFINDERDEBUGDRAWABLE_H
#define WIZENGINE_PATHFINDERDEBUGDRAWABLE_H

#include "SFML/Graphics/Drawable.hpp"
#include "WIZ/asset/AssetLoader.h"
#include "WIZ/asset/TextureAsset.h"
#include "SFML/Graphics/Sprite.hpp"
#include "TilePathFinder.h"

namespace wiz {
	class PathFinderDebugDrawable;
}

class wiz::PathFinderDebugDrawable : public sf::Drawable {
	const TilePathFinder& pathFinder;
	mutable sf::Sprite debugSprite;
public:
	PathFinderDebugDrawable(const TilePathFinder& pathFinder,
							const wiz::AssetLoader& assets,
							const wiz::TextureAsset& white_pixel);

	void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;

};


#endif //WIZENGINE_PATHFINDERDEBUGDRAWABLE_H
