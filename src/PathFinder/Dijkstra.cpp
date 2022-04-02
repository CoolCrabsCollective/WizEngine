#include "PathFinder/Dijkstra.h"

#include <limits>
#include <algorithm>

const float pf::DijkstraNode::infinity = std::numeric_limits<float>::infinity();

pf::Dijkstra::Dijkstra()
{}

pf::Dijkstra::~Dijkstra()
{}

bool pf::Dijkstra::getPath(pf::DijkstraNode* start, pf::DijkstraNode* goal, std::vector<pf::DijkstraNode*>& path)
{
	pf::DijkstraNode *currentNode, *childNode;
	float dist;

	std::make_heap(open.begin(), open.end(), pf::CompareNodes());
	pushOpen(start);
	start->setDistance(0.0f);

	while(!open.empty())
	{
		std::sort(open.begin(), open.end(), pf::CompareNodes());

		currentNode = open.front();
		popOpen(currentNode);

		if(currentNode == goal)
		{
			reconstructPath(currentNode, path);
			return true;
		}

		for(const auto& children : currentNode->getChildren())
		{
			childNode = static_cast<pf::DijkstraNode*>(children.first);
			
			dist = currentNode->getDistance() + children.second;
			if(!childNode->isClosed() && dist < childNode->getDistance())
			{
				childNode->setDistance(dist);
				childNode->setParent(currentNode);
				pushOpen(childNode);
			}
		}
	}

	return false;
}

void pf::Dijkstra::pushOpen(pf::DijkstraNode* node)
{
	open.push_back(node);
	std::push_heap(open.begin(), open.end(), pf::CompareNodes());
}

void pf::Dijkstra::popOpen(pf::DijkstraNode* node)
{
	std::pop_heap(open.begin(), open.end(), pf::CompareNodes());
	open.pop_back();
	node->setClosed(true);
	closed.push_back(node);
}


void pf::Dijkstra::releaseNodes()
{
	for(const auto& node : open)
		node->release();
	for(const auto& node : closed)
		node->release();
}

void pf::Dijkstra::clear()
{
	releaseNodes();
	open.clear();
	closed.clear();
}