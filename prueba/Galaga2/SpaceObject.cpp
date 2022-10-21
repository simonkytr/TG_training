 
#include "SpaceObject.h"
    
    FSpaceObject::FSpaceObject(const olc::vf2d& InSize, const olc::vf2d& InPosition, const olc::vf2d& InVelocity)
    {
        Size = InSize;
        Position = InPosition;
        Velocity = InVelocity;
    }

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& FSpaceObject::GetPosition() const
    {
        return Position;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FSpaceObject::SetPosition(const olc::vf2d& NewPosition)
    {
        Position = NewPosition;
    }

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& FSpaceObject::GetSize() const
    {
        return Size;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FSpaceObject::GetSize(const olc::vf2d& NewSize)
    {
        Size = NewSize;
    }

    //--------------------------------------------------------------------------------------------------------------
    const olc::vf2d& FSpaceObject::GetVelocity() const
    {
        return Velocity;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FSpaceObject::SetVelocity(const olc::vf2d& NewVelocity)
    {
        Velocity = NewVelocity;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FSpaceObject::Mover(float Time)
    {
        Position += Velocity * Time;
    }

    //--------------------------------------------------------------------------------------------------------------
    bool FSpaceObject::IsDead() const
    {
        return bIsDead;
    }

    //--------------------------------------------------------------------------------------------------------------
    void FSpaceObject::IsDeadTrue()
    {
        bIsDead = true;
    }
  
