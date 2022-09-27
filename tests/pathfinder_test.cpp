//
// Created by Alexander Winter on 2022-09-27.
//

#include <gtest/gtest.h>
#include "WIZ/logging/StdOutLogger.h"
#include "WIZ/pathfinding/TilePathFinder.h"
#include "WIZ/pathfinding/TileNode.h"

TEST(pathfinder, tile_pathfinder_correctness)
{
	wiz::StdOutLogger logger(wiz::LogLevel::NONE);
	wiz::TilePathFinder finder(logger, {1, 1}, {0, 0}, {50, 50});
	
	std::function<bool(b2Vec2)> func = [](b2Vec2 pos) {
		return pos.y >= 25 && pos.y <= 26 && pos.x < 49;
	};
	
	finder.initialize(func);
	
	std::vector<wiz::TileNode*> path;
	
	finder.findPath({0, 0}, {0, 50}, path);
	
	for(wiz::TileNode* ptr : path)
		std::cout << "Node: " << ptr->getWorldPosition().x << ", " << ptr->getWorldPosition().y << std::endl;
	
}