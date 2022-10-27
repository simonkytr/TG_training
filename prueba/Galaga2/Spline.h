#pragma once
#include "Point2D.h"
#include <vector>

struct FSpline
{
    std::vector<FPoint2D> Points;

    FPoint2D GetSplinePoint(float t) const;

    FPoint2D GetSplineGradient(float t) const;
};
