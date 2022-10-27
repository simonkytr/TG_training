#include "Spline.h"
FPoint2D FSpline::GetSplinePoint(float t) const
{
    const int Point1 = static_cast<int>(t) + 1;
    const int Point2 = Point1 + 1;
    const int Point3 = Point2 + 1;
    const int Point0 = Point1 - 1;

    t = t - static_cast<int>(t);

    const float tt = t * t;
    const float ttt = tt * t;

    //q = influence field values
    const float q1 = -ttt + 2.0 * tt - t;
    const float q2 = 3.0f * ttt - 5.0f * tt + 2.0f;
    const float q3 = -3.0f * ttt + 4.0f * tt + t;
    const float q4 = ttt - tt;

    const float tx = 0.5f * (Points[Point0].PositionX * q1 + Points[Point1].PositionX * q2 + Points[Point2].PositionX * q3
        + Points[Point3].PositionX * q4);
    const float ty = 0.5f * (Points[Point0].PositionY * q1 + Points[Point1].PositionY * q2 + Points[Point2].PositionY * q3
        + Points[Point3].PositionY * q4);

    return {tx, ty};
}

FPoint2D FSpline::GetSplineGradient(float t) const
{
    const int Point1 = static_cast<int>(t) + 1;
    const int Point2 = Point1 + 1;
    const int Point3 = Point2 + 1;
    const int Point0 = Point1 - 1;

    t = t - static_cast<int>(t);

    const float tt = t * t;

    //q = influence field values
    const float q1 = -3.0f * tt + 4.0 * t - 1.0f;
    const float q2 = 9.0f * tt - 10.0f * t;
    const float q3 = -9.0f * tt + 8.0f * t + 1.0f;
    const float q4 = 3.0f * tt - 2 * t;

    const float tx = 0.5f * (Points[Point0].PositionX * q1 + Points[Point1].PositionX * q2 + Points[Point2].PositionX * q3
        + Points[Point3].PositionX * q4);
    float ty = 0.5f * (Points[Point0].PositionY * q1 + Points[Point1].PositionY * q2 + Points[Point2].PositionY * q3
        + Points[Point3].PositionY * q4);

    return {tx, ty};
}