//
// Created by Alexander Winter🤤 on 2022-04-02.
//

#ifndef LD50_CLIENT_FORESTPATHFINDER_H
#define LD50_CLIENT_FORESTPATHFINDER_H

#include <unordered_map>
#include <functional>
#include "TileNode.h"
#include "Box2D/Common/b2Math.h"
#include "PathFinder/PathFinder.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "WIZ/asset/AssetLoader.h"
#include "WIZ/asset/TextureAsset.h"

namespace wiz {
	class TilePathFinder;
}

class wiz::TilePathFinder {
	const wiz::Logger& logger;

	mutable pf::PathFinder<TileNode> pathFinder;
	std::unordered_map<uint32_t, TileNode*> map;

	const b2Vec2 tileSize;
	const b2Vec2 tileStart;
	const b2Vec2 tileEnd;
public:
	TilePathFinder(const wiz::Logger& logger,
				   const b2Vec2& tileSize,
				   const b2Vec2& tileStart,
				   const b2Vec2& tileEnd);

	void initialize(const std::function<bool(b2Vec2)>& is_obstructed);

	bool findPath(b2Vec2 start, b2Vec2 goal, std::vector<TileNode*>& path) const;

	b2Vec2 getTileSize() const;

	b2Vec2 getTileStart() const;

	b2Vec2 getTileEnd() const;

	sf::Vector2i worldToTileCoordinates(b2Vec2 worldCoords) const;

	b2Vec2 tileToWorldCoordinates(sf::Vector2i worldCoords) const;

	void addBridge(b2Vec2 start, b2Vec2 end);

private:
	TileNode* node(b2Vec2 position) const;

	uint32_t keyOf(b2Vec2 position) const;

	uint32_t keyOf(sf::Vector2i tile) const;

	friend class PathFinderDebugDrawable;
};


#endif //LD50_CLIENT_FORESTPATHFINDER_H
