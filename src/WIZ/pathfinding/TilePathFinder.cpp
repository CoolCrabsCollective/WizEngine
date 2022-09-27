//
// Created by Alexander Winter🤤 on 2022-04-02.
//

#include "WIZ/pathfinding/TilePathFinder.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "WIZ/asset/AssetLoader.h"
#include "WIZ/asset/TextureAsset.h"

using namespace wiz;

TilePathFinder::TilePathFinder(const wiz::Logger& logger, 
							   const b2Vec2& tileSize,
							   const b2Vec2& tileStart,
							   const b2Vec2& tileEnd)
	: logger(logger), 
		tileSize(tileSize), 
		tileStart(tileStart), 
		tileEnd(tileEnd) {}

void TilePathFinder::initialize(const std::function<bool(b2Vec2)>& is_obstructed) {

	int16_t minX = 0;
	int16_t minY = 0;

	int16_t maxX = floor((getTileEnd().x - getTileStart().x) / getTileSize().x);
	int16_t maxY = floor((getTileEnd().y - getTileStart().y) / getTileSize().y);

	b2Vec2 halfSize = getTileSize();
	halfSize *= 0.5f;

	for(int16_t y = minY; y < maxY; y++) {
		for(int16_t x = minX; x < maxX; x++) {
			uint32_t key = x & 0x0000FFFF | (static_cast<uint32_t>(y << 16) & 0xFFFF0000);

			b2Vec2 worldPos = tileToWorldCoordinates({x, y}) + halfSize;

			TileNode* node = new TileNode(*this, worldPos);

			node->setPosition(x, y);
			node->setObstructed(is_obstructed(worldPos));

			for(int i = -1; i <= 2; i++) {

				int16_t newX = i == 2 ? x - 1 : x + i;
				int16_t newY = i == 2 ? y : y - 1;

				if(newX < minX || newX >= maxX || newY < minY || newY >= maxY)
					continue;

				uint32_t otherKey = keyOf(sf::Vector2i {newX, newY });

				TileNode* otherNode = map[otherKey];

				float dst = node->distanceTo(otherNode);

				if(!otherNode->isObstructed())
					node->addChild(otherNode, dst);

				if(!node->isObstructed())
					otherNode->addChild(node, dst);
			}

			map[key] = node;
		}
	}
}


bool TilePathFinder::findPath(b2Vec2 start, b2Vec2 goal, std::vector<TileNode*>& path) const {
	pathFinder.setStart(*node(start));

	TileNode* processDest = node(goal);
	TileNode* originalDest = processDest;

	while(processDest->isObstructed()) {
		goal.y -= getTileSize().y / 4.0f;
		processDest = node(goal);
	}
	pathFinder.setGoal(*processDest);

	if(pathFinder.getStart() == pathFinder.getGoal())
		return false;

	for (const auto & [key, value] : map)
		value->release();

	path.clear();
	bool found = pathFinder.findPath<pf::AStar>(path);

	if(found && processDest != originalDest)
		path.push_back(originalDest);

	pf::AStar::getInstance().clear();

	return found;
}

b2Vec2 TilePathFinder::getTileSize() const {
	return tileSize;
}

b2Vec2 TilePathFinder::getTileStart() const {
	return tileStart;
}

b2Vec2 TilePathFinder::getTileEnd() const {
	return tileEnd;
}

sf::Vector2i TilePathFinder::worldToTileCoordinates(b2Vec2 worldCoords) const {
	int16_t x = static_cast<int16_t>(floor((worldCoords.x - getTileStart().x) / getTileSize().x));
	int16_t y = static_cast<int16_t>(floor((worldCoords.y - getTileStart().y) / getTileSize().y));

	return { x, y };
}

b2Vec2 TilePathFinder::tileToWorldCoordinates(sf::Vector2i worldCoords) const {
	float x = worldCoords.x * getTileSize().x + getTileStart().x;
	float y = worldCoords.y * getTileSize().y + getTileStart().y;

	return { x, y };
}

uint32_t TilePathFinder::keyOf(b2Vec2 position) const {
	sf::Vector2i index = worldToTileCoordinates(position);

	return keyOf(index);
}

uint32_t TilePathFinder::keyOf(sf::Vector2i tile) const {

	int16_t x = tile.x;
	int16_t y = tile.y;

	return x & 0x0000FFFF | (static_cast<uint32_t>(y << 16) & 0xFFFF0000);
}

TileNode* TilePathFinder::node(b2Vec2 position) const {

	sf::Vector2i tile = worldToTileCoordinates(position);

	int16_t minX = 0;
	int16_t minY = 0;

	int16_t maxX = floor((getTileEnd().x - getTileStart().x) / getTileSize().x);
	int16_t maxY = floor((getTileEnd().y - getTileStart().y) / getTileSize().y);

	tile.x = std::min(tile.x, maxX - 1);
	tile.y = std::min(tile.y, maxY - 1);
	tile.x = std::max(tile.x, static_cast<int>(minX));
	tile.y = std::max(tile.y, static_cast<int>(minY));

	return map.at(keyOf(tile));
}

void TilePathFinder::addBridge(b2Vec2 start, b2Vec2 end) {

	int16_t minX = 0;
	int16_t minY = 0;

	int16_t maxX = floor((getTileEnd().x - getTileStart().x) / getTileSize().x);
	int16_t maxY = floor((getTileEnd().y - getTileStart().y) / getTileSize().y);

	sf::Vector2i startIndex = worldToTileCoordinates(start);
	sf::Vector2i endIndex = worldToTileCoordinates(end);

	TileNode* startNode = new TileNode(*this, start);
	startNode->setPosition(startIndex.x, startIndex.y);
	startNode->setObstructed(false);

	TileNode* endNode = new TileNode(*this, end);
	endNode->setPosition(endIndex.x, endIndex.y);
	endNode->setObstructed(false);

	float dst = b2Distance(start, end);

	startNode->addChild(endNode, dst);
	endNode->addChild(startNode, dst);

	for(int16_t i = -1; i <= 1; i++) {
		for(int16_t j = -1; j <= 1; j++) {
			if(i == 0 && j == 0)
				continue;

			int16_t startNBX = startIndex.x + i;
			int16_t startNBY = startIndex.y + j;

			if(startNBX < minX || startNBX >= maxX || startNBY < minY || startNBY >= maxY)
				continue;

			uint32_t otherKey = keyOf(sf::Vector2i {startNBX, startNBY });

			TileNode* otherNode = map[otherKey];

			if(otherNode == nullptr) {
				logger.error("Other node null in addBridge");
				return;
			}

			float dst = b2Distance(otherNode->getWorldPosition(), start);

			if(!otherNode->isObstructed())
				startNode->addChild(otherNode, dst);

			otherNode->addChild(startNode, dst);
		}
	}

	for(int16_t i = -1; i <= 1; i++) {
		for(int16_t j = -1; j <= 1; j++) {
			if(i == 0 && j == 0)
				continue;

			int16_t endNBX = endIndex.x + i;
			int16_t endNBY = endIndex.y + j;

			if(endNBX < minX || endNBX >= maxX || endNBY < minY || endNBY >= maxY)
				continue;

			uint32_t otherKey = keyOf(sf::Vector2i {endNBX, endNBY });

			TileNode* otherNode = map[otherKey];

			if(otherNode == nullptr) {
				logger.error("Other node null in addBridge");
				return;
			}

			float dst = b2Distance(otherNode->getWorldPosition(), end);

			if(!otherNode->isObstructed())
				endNode->addChild(otherNode, dst);

			otherNode->addChild(endNode, dst);
		}
	}
}
