// MTRX3760 2026 Project 2: Package Deal
// File: TopologyGraph.hpp
// Author(s): Isabella Armitstead
// Description: Owns the rooms and passages and tracks the robot's room.

#ifndef MAPPER_TOPOLOGY_GRAPH_HPP
#define MAPPER_TOPOLOGY_GRAPH_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "mapper/Room.hpp"
#include "mapper/Passage.hpp"

class TopologyGraph {
public:
    TopologyGraph();

    bool crossPassage(int tagId);
    void assignTypeLabel(const std::string& label);
    bool isFullyTraversed() const;
    std::string toDot() const;
    std::string statusText() const;

private:
    std::vector<Room> rooms_;
    std::vector<Passage> passages_;
    std::size_t currentRoom_ = 0;
};

#endif