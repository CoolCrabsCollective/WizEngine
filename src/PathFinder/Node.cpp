#include "PathFinder/Node.h"

pf::Node::Node() :
	m_parent(nullptr)
{}

pf::Node::~Node()
{}

pf::Node* pf::Node::getParent() const
{
	return m_parent;
}

std::vector<std::pair<pf::Node*, float>>& pf::Node::getChildren()
{
	return m_children;
}

void pf::Node::addChild(pf::Node* child, float distance)
{
	m_children.push_back(std::make_pair(child,distance));
}

void pf::Node::clearChildren()
{
	m_children.clear();
}

void pf::Node::setParent(pf::Node* parent)
{
	m_parent = parent;
}
