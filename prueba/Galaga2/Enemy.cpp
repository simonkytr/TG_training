#include "Enemy.h"

    FEnemy::FEnemy(const olc::vf2d& InSize, const olc::vf2d& InPosition, const olc::vf2d& InVelocity): FSpaceObject(
            InSize, InPosition, InVelocity)
    {
        OriginPosition = olc::vf2d(0.0f, 0.0f);
        SavedPosition = Position;
        Paths[0].Points = {
            {-20, 200}, //0
            {10, 10}, //1
            {30, 85}, //2
            {50, 62}, //3
             {70, 96}, //4
             {95, 56}, //5
             {60, 86}, //6
             {45, 50}, //7
             {20, 70},//8
             {60, 50},//9
             {60, 30},//9
            {0, 0},
            {x, y}
        };

        Paths[1].Points = {
            {140, -20}, //0
            {120, 0}, //1
            {30, 65}, //2
            {30, 32}, //3
            {55, 46}, //4
            {65, 96}, //5
            {90, 86}, //6
            {65, 70}, //7
            // {EndEnemy.x, 160},//9
            // {EndEnemy.x, 200}//10
        };
    }

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& FEnemy::GetOriginPosition() const
    {
        return OriginPosition;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::SetOriginPosition(const olc::vf2d& NewPosition)
        {
            OriginPosition = NewPosition;
        }

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& FEnemy::GetSavedPosition() const
    {
        return SavedPosition;
    };

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::SetSavedPosition(const olc::vf2d& NewPosition)
    {
        SavedPosition = NewPosition;
    };

    //--------------------------------------------------------------------------------------------------------------
    bool FEnemy::IsSelected() const
    {
        return bIsSelected;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::UpdateIsSelected(bool Selection)
    {
        bIsSelected = Selection;
    }

    //-------------------------------------------------------------------------------------------------------------
    bool FEnemy::IsSnake() const
    {
        return bIsSnake;
    };

    //-------------------------------------------------------------------------------------------------------------
    void FEnemy::UpdateIsSnake(bool Selection)
    {
        bIsSnake = Selection;
    };

    //--------------------------------------------------------------------------------------------------------------
    float FEnemy::GetMarker() const
    {
        return Marker;
    }

//--------------------------------------------------------------------------------------------------------------
    void FEnemy::SetMarker(const float NewMarker)
    {
        Marker = NewMarker;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::UpdateMarker(float NewMarker)
    {
        Marker += NewMarker;
    }

    //-------------------------------------------------------------------------------------------------------------
    void FEnemy::CalculateFormationPath(float Timer)
    {
        SetVelocity(olc::vf2d(1.5, 0.5));
        SetSavedPosition(olc::vf2d(
        15.0f * std::sin(GetVelocity().x * Timer) + GetOriginPosition().x +
        20.0f,
        18.0f * std::sin(Timer * GetVelocity().y) + GetOriginPosition().y +
        20.0f));
    }

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::FollowFormationPath()
    {
        SetPosition(GetSavedPosition());
    }

    //---------------------------------------------------------------------------------------------------------------
    void FEnemy::ActivatePath(float Timer, int PathSelector)
    {       
                
        Paths[PathSelector].Points[Paths[PathSelector].Points.size() - 2].PositionX = GetSavedPosition().x ;
        Paths[PathSelector].Points[Paths[PathSelector].Points.size() - 2].PositionY = GetSavedPosition().y;
        
        if (GetMarker() < static_cast<float>(Paths[PathSelector].Points.size() - 3.0f))
        {
            const FPoint2D Point1 = Paths[PathSelector].GetSplinePoint(GetMarker());
            SetPosition(olc::vf2d(Point1.PositionX, Point1.PositionY));
            UpdateMarker(Timer);
        }
        else
        {
            UpdateIsSnake(false);
            UpdateIsSelected(false);
            SetMarker(0);
        }
    }

