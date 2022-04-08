#include <stdexcept>
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
	if(child == this)
		throw std::runtime_error("Node cannot be its own child");

	m_children.emplace_back(child, distance);
}

void pf::Node::clearChildren()
{
	m_children.clear();
}

void pf::Node::setParent(pf::Node* parent)
{
	if(parent == this)
		throw std::runtime_error("Node cannot be its own parent");

	m_parent = parent;
}
