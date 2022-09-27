//
// Created by Alexander Winter🤤 on 2022-04-02.
//

#include "WIZ/pathfinding/TileNode.h"
#include "WIZ/pathfinding/TilePathFinder.h"


using namespace wiz;

TileNode::TileNode(TilePathFinder& pathFinder, b2Vec2 worldPos)
	: pathFinder(pathFinder), worldPos(worldPos)
{

}

float TileNode::distanceTo(pf::AStarNode* node) const {
	TileNode* forestNode = dynamic_cast<TileNode*>(node);

	if(!forestNode)
		throw std::runtime_error("Not a TileNode");

	return b2Distance(forestNode->getWorldPosition(), getWorldPosition());
}

b2Vec2 TileNode::getWorldPosition() const {
	return worldPos;
}

bool TileNode::isObstructed() const {
	return obstructed;
}

void TileNode::setObstructed(bool obstructed) {
	TileNode::obstructed = obstructed;
}
