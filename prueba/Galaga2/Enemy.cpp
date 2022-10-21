#include "Enemy.h"

    FEnemy::FEnemy(const olc::vf2d& InSize, const olc::vf2d& InPosition, const olc::vf2d& InVelocity): FSpaceObject(
            InSize, InPosition, InVelocity)
    {
        OriginPosition = olc::vf2d(0.0f, 0.0f);
        SavedPosition = Position;
        
        FSpline Path;
        Path.Points = {
            {-20, 200}, //0
            {-10, 10}, //1
            {30, 85}, //2
            {50, 62}, //3
             // {70, 96}, //4
             // {95, 56}, //5
             {60, 86}, //6
             // {45, 50}, //7
             {20, 70},//8
             {60, 50},//9
            {0, 0},
            {70, 0}
        };
        Paths.push_back(Path);

        FSpline Path1;
        Path1.Points = {
            {140, -20}, //0
            {120, 0}, //1
            {30, 65}, //2
            {30, 32}, //3
            {55, 46}, //4
            {65, 96}, //5
            {90, 86}, //6
            {70, 0}, //7
            
        };
        Paths.push_back(Path1);
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
    FEnemy::EEstate FEnemy::GetState() const
    {
        return Estate;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FEnemy::SetState(EEstate NewState)
    {
        Estate = NewState;
    }

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
        if(PathSelector >= 0 && PathSelector < static_cast<int>(Paths.size()))
        {
            
                Paths[PathSelector].Points[Paths[PathSelector].Points.size() - 2].PositionX = GetSavedPosition().x;
                Paths[PathSelector].Points[Paths[PathSelector].Points.size() - 2].PositionY = GetSavedPosition().y;
            
            if(PathSelector != 0)
            {
                Paths[PathSelector].Points[1].PositionX = GetSavedPosition().x;
                Paths[PathSelector].Points[1].PositionY = GetSavedPosition().y;
            }
        
            if (GetMarker() < static_cast<float>(Paths[PathSelector].Points.size() - 3.0f))
            {
                const FPoint2D Point1 = Paths[PathSelector].GetSplinePoint(GetMarker());
                SetPosition(olc::vf2d(Point1.PositionX, Point1.PositionY));
                CalculateAngle(Paths[PathSelector]);
                UpdateMarker(Timer);
            }
            else
            {
                SetState(Formation);
                SetMarker(0);
            }
        }
        else
        {
            return;
        }
    }

    //---------------------------------------------------------------------------------------------------------------
    void FEnemy::CalculateAngle(const FSpline& PathToCalculate)
    {
        const FPoint2D Gradient1 = PathToCalculate.GetSplineGradient(Marker);
        Angle = atan2(-Gradient1.PositionX, -Gradient1.PositionY);
    };

    //---------------------------------------------------------------------------------------------------------------
    float FEnemy::GetAngle() const
    {
        return Angle;
    }

//----------------------------------------------------------------------------------------------------------------
    olc::Decal* FEnemy::GetDecal() const
    {
        return Decal;
    };

//----------------------------------------------------------------------------------------------------------------
void FEnemy::SetDecal(olc::Decal* NewDecal)
{
    Decal = NewDecal;
};


