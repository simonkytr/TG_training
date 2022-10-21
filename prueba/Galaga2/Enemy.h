#pragma once
#include "Spline.h"
#include "SpaceObject.h"

class FEnemy : public FSpaceObject
{
private:
    olc::vf2d OriginPosition;
    olc::vf2d SavedPosition;

    enum EEstate { Formation, Selected, Snake, Dead};
    EEstate Estate;
    
    bool bIsSelected = false;
    bool bIsSnake = false;
    float Marker = 0.0f;
    //FSpline Path;
    std::vector<FSpline> Paths;

    float x = 0;
    float y = 0;


public:
    
    FEnemy(const olc::vf2d& InSize, const olc::vf2d& InPosition, const olc::vf2d& InVelocity);

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& GetOriginPosition() const;

    //--------------------------------------------------------------------------------------------------------------
    void SetOriginPosition(const olc::vf2d& NewPosition);

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& GetSavedPosition() const;

    //--------------------------------------------------------------------------------------------------------------
    void SetSavedPosition(const olc::vf2d& NewPosition);

    //--------------------------------------------------------------------------------------------------------------
    bool IsSelected() const;

    //--------------------------------------------------------------------------------------------------------------
    void UpdateIsSelected(bool Selection);

    //-------------------------------------------------------------------------------------------------------------
    bool IsSnake() const;

    //-------------------------------------------------------------------------------------------------------------
    void UpdateIsSnake(bool Selection);

    //--------------------------------------------------------------------------------------------------------------
    float GetMarker() const;

    //--------------------------------------------------------------------------------------------------------------
    void SetMarker(const float NewMarker);
    
    //--------------------------------------------------------------------------------------------------------------
    void UpdateMarker(float NewMarker);

    //-------------------------------------------------------------------------------------------------------------
    void CalculateFormationPath(float Timer);
    
    //---------------------------------------------------------------------------------------------------------------
    void FollowFormationPath();

    //---------------------------------------------------------------------------------------------------------------
    void ActivatePath(float Timer, int PathSelector);
};
