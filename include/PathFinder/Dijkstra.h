#pragma once

#include "PathAlgorithm.h"
#include "Node.h"
#include <vector>

namespace pf {
	class DijkstraNode : public Node {
		static const float infinity;

	protected:
		bool closed;
		float distance;

	public:
		DijkstraNode() :
			closed(false),
			distance(infinity) {}

		~DijkstraNode() override = default;

		void setClosed(bool value) {
			closed = value;
		}

		void setDistance(float value) {
			distance = value;
		}

		[[nodiscard]]
		inline bool isClosed() const {
			return closed;
		}

		[[nodiscard]]
		inline float getDistance() const {
			return distance;
		}

		void release() {
			distance = infinity;
			closed = false;
			m_parent = nullptr;
		}
	};

	struct CompareNodes {
		bool operator() (const DijkstraNode* n1, const DijkstraNode* n2) {
			return n1->getDistance() < n2->getDistance();
		}
	};

	class Dijkstra : public pf::PathAlgorithm<DijkstraNode> {
		std::vector<DijkstraNode*> open, closed;

	public:
		static Dijkstra& getInstance() {
			static Dijkstra instance;
			return instance;
		}

		bool getPath(DijkstraNode* start,
					 DijkstraNode* goal,
					 std::vector<DijkstraNode*>& path) override;
		void clear() override;

	private:
		Dijkstra();
		~Dijkstra();

		void pushOpen(DijkstraNode* node);
		void popOpen(DijkstraNode* node);
		void releaseNodes();
	};
}


