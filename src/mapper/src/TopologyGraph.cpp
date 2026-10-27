// MTRX3760 2026 Project 2: Package Deal
// File: TopologyGraph.cpp
// Author(s): Isabella Armitstead
// Description: Initialises the map and provides basic status information.

#include "mapper/TopologyGraph.hpp"

TopologyGraph::TopologyGraph()
    : rooms_(1)
{
    // Start with one room. Its type label is initially empty.
}

std::string TopologyGraph::statusText() const
{
    return "Rooms: " + std::to_string(rooms_.size())
        + ", passages: " + std::to_string(passages_.size())
        + ", current room: " + std::to_string(currentRoom_ + 1);
}