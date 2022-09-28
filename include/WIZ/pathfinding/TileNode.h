//
// Created by Alexander Winter🤤 on 2022-04-02.
//

#ifndef LD50_CLIENT_FORESTNODE_H
#define LD50_CLIENT_FORESTNODE_H


#include "PathFinder/AStar.h"
#include "Box2D/Common/b2Math.h"

namespace wiz {
	class TilePathFinder;
	class TileNode;
}

class wiz::TileNode : public pf::AStarNode {
	TilePathFinder& pathFinder;

	bool obstructed = false;
	b2Vec2 worldPos;
public:
	TileNode(TilePathFinder& pathFinder, b2Vec2 worldPos);

	float distanceTo(AStarNode* node) const override;

	b2Vec2 getWorldPosition() const;

	bool isObstructed() const;

	void setObstructed(bool obstructed);
};


#endif //LD50_CLIENT_FORESTNODE_H
