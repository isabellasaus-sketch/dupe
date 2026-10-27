// MTRX3760 2026 Project 2: Package Deal
// File: CRoomClassifier.cpp
// Author(s): 490550744, 530141790
//
// Implements dimension-based classification of the supported room types.

//---Includes-------------------------------------------------------------------
#include "roomshape/CRoomClassifier.h"

#include <cmath>
#include <limits>
#include <string>

namespace roomshape {

//---CRoomClassifier------------------------------------------------------------
// Reference sizes describe the interior bounding rectangle, in metres.
// A one-metre equilateral triangle has height sqrt(3)/2 and base length 1.
CRoomClassifier::CRoomClassifier(double aMatchTolerance)
    : mMatchTolerance(aMatchTolerance),
      mRoomDefinitions{{"SMALL_SQUARE", 1.00, 1.00},
          {"LARGE_SQUARE", 1.50, 1.50},
          {"RECTANGLE", 0.50, 1.00},
          {"HALLWAY", 0.45, 1.45},
          {"EQUILATERAL_TRIANGLE", std::sqrt(3.0) / 2.0, 1.00}} {}

//------------------------------------------------------------------------------
std::string CRoomClassifier::Classify(
    const RoomDimensions& arDimensions) const {
  // A failed scan estimate must not be compared as a zero-sized room.
  if (!arDimensions.Valid) {
    return "";
  }

  std::string BestRoomName;
  double SmallestError = std::numeric_limits<double>::infinity();

  for (const RoomDefinition& Definition : mRoomDefinitions) {
    const double ShortSideError =
        std::abs(arDimensions.ShortSide - Definition.ShortSide);

    const double LongSideError =
        std::abs(arDimensions.LongSide - Definition.LongSide);

    // Both measured sides must be within the allowed tolerance.
    if (ShortSideError <= mMatchTolerance && LongSideError <= mMatchTolerance) {
      const double TotalError = CalculateError(arDimensions, Definition);

      // Rank only eligible rooms; equal errors keep the earlier definition.
      if (TotalError < SmallestError) {
        SmallestError = TotalError;
        BestRoomName = Definition.Name;
      }
    }
  }

  // The name remains empty if no reference passed both side tolerances.
  return BestRoomName;
}

//------------------------------------------------------------------------------
double CRoomClassifier::CalculateError(
    const RoomDimensions& arDimensions,
    const RoomDefinition& arDefinition) const {
  const double ShortSideError =
      std::abs(arDimensions.ShortSide - arDefinition.ShortSide);

  const double LongSideError =
      std::abs(arDimensions.LongSide - arDefinition.LongSide);

  return ShortSideError + LongSideError;
}

}  // namespace roomshape
