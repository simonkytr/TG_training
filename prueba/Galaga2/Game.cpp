#include "Game.h"
bool FGame::HasCollidedBoxBox(const olc::vf2d& SizeBox1, const olc::vf2d& PositionBox1, const olc::vf2d& SizeBox2,
                          const olc::vf2d& PositionBox2) const
{
    return PositionBox1.x <= PositionBox2.x + SizeBox2.x &&
        PositionBox1.x + SizeBox1.x >= PositionBox2.x &&
        PositionBox1.y <= PositionBox2.y + SizeBox2.y &&
        PositionBox1.y + SizeBox1.y >= PositionBox2.y;
}

//----------------------------------------------------------------------------------------------------------------------
int FGame::GetRandomEnemy() const
{
    if(!Enemies.empty())
    {
        return rand() % static_cast<int>(Enemies.size());
    }
    return -1;
}

//------------------------------------------------------------------------------------------------------------------
void FGame::SelectRandomEnemy()
{
    const int RandomValue = GetRandomEnemy();
    if(RandomValue == -1)
    {
        return;
    }
    
    const std::shared_ptr<FEnemy> RandomEnemy = Enemies[RandomValue];
       
    RandomEnemy->SetState(FEnemy::Selected);
}

//------------------------------------------------------------------------------------------------------------------
void FGame::DeleteMissile()
{
    if (!Missiles.empty())
    {
        const auto i = std::remove_if(Missiles.begin(), Missiles.end(), [&](FSpaceObject Object)
        {
            return (static_cast<float>(Object.GetPosition().y) < 1);
        });
        if (i != Missiles.end())
            Missiles.erase(i);
    }
};

//------------------------------------------------------------------------------------------------------------------
void FGame::DeleteEnemyMissile()
{
    if (!EnemyMissiles.empty())
    {
        const auto i = std::remove_if(EnemyMissiles.begin(), EnemyMissiles.end(), [&](const FSpaceObject& Object)
        {
            return (static_cast<float>(Object.GetPosition().y) < 1);
        });
        if (i != EnemyMissiles.end())
            EnemyMissiles.erase(i);
    }
};

//------------------------------------------------------------------------------------------------------------------
void FGame::DeleteEnemy()
{
    if (!Enemies.empty())
    {
        const auto i = std::remove_if(Enemies.begin(), Enemies.end(), [&](std::shared_ptr<FEnemy> Object)
        {
            return (static_cast<float>(Object->GetPosition().y) >= ScreenHeight() - 1 || static_cast<float>(Object->GetPosition().y) <= - 1 );
        }); 
        if (i != Enemies.end())
            Enemies.erase(i);
    }
};