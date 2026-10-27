// MTRX3760 2026 Project 2: Package Deal
// File: Passage.hpp
// Author(s): Isabella Armitstead
// Description: Represents a tagged connection between two rooms.

#ifndef MAPPER_PASSAGE_HPP
#define MAPPER_PASSAGE_HPP

#include <cstddef>

class Passage {
public:
    Passage(int tagId, std::size_t roomA, std::size_t roomB);

    int tagId() const;
    bool connectsRoom(std::size_t room) const;
    std::size_t otherEnd(std::size_t room) const;

    void recordCrossing();
    bool isFullyCrossed() const;

private:
    int tagId_;
    std::size_t roomA_;
    std::size_t roomB_;
    unsigned int crossingCount_ = 0;
};

#endif