//
// Created by Alexander Winter on 2022-09-27.
//

#include "WIZ/pathfinding/PathFinderDebugDrawable.h"
#include "SFML/Graphics/RenderTarget.hpp"

using namespace wiz;

PathFinderDebugDrawable::PathFinderDebugDrawable(const TilePathFinder& pathFinder,
												 const wiz::AssetLoader& assets,
                                                 const wiz::TextureAsset& white_pixel)
		: pathFinder(pathFinder) {

	debugSprite.setTexture(*assets.get(white_pixel));
}


void PathFinderDebugDrawable::draw(sf::RenderTarget& target, const sf::RenderStates& states) const
{
	int16_t minX = 0;
	int16_t minY = 0;

	int16_t maxX = floor((pathFinder.getTileEnd().x - pathFinder.getTileStart().x) / pathFinder.getTileSize().x);
	int16_t maxY = floor((pathFinder.getTileEnd().y - pathFinder.getTileStart().y) / pathFinder.getTileSize().y);

	for(int16_t y = minY; y < maxY; y++) {
		for(int16_t x = minX; x < maxX; x++) {
			uint32_t key = x & 0x0000FFFF | (static_cast<uint32_t>(y << 16) & 0xFFFF0000);
			if(!pathFinder.map.at(key)->isObstructed())
				continue;

			b2Vec2 worldPos = pathFinder.tileToWorldCoordinates({x, y});
			b2Vec2 center = worldPos;
			center.x += pathFinder.getTileSize().x / 2.0f;
			center.y += pathFinder.getTileSize().y / 2.0f;

			debugSprite.setPosition(sf::Vector2f(center.x, 100.0f - center.y));
			debugSprite.setOrigin({ 0.5f, 0.5f });
			debugSprite.setScale(sf::Vector2f(pathFinder.getTileSize().x, pathFinder.getTileSize().y));
			debugSprite.setColor(pathFinder.map.at(key)->isObstructed() ? sf::Color::White : sf::Color::Green);
			target.draw(debugSprite);
		}
	}
}