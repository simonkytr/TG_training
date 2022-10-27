#pragma once
#include "SpaceObject.h"
#include "Enemy.h"
#include "Point2D.h"
#include "Spline.h"

class FGame : public olc::PixelGameEngine
{
public:
    FGame()
    {
        sAppName = "Galaga";
    }

private:

    //player
    FSpaceObject SpaceShip = FSpaceObject(olc::vf2d(7.0, 10.0),
                                          olc::vf2d(50, 130),
                                          olc::vf2d(0.0, 0.0));

    std::vector<FSpaceObject> Missiles;
    
    //Enemies
    int EnemyCountX = 6;
    int EnemyCountY = 4;
    int SnakeEnemyCount = 0;
    int OutEnemyCount = 0;
    
    std::vector<std::weak_ptr<FEnemy>> MatrixEnemies;
    std::vector<std::weak_ptr<FEnemy>> SnakeEnemies;
    std::vector<std::shared_ptr<FEnemy>> Enemies;
    
    olc::vf2d EndEnemy;
    
    olc::vf2d DistanceEnemy = {5.0, 5.0};
    olc::vf2d SizeEnemy = {7.0, 10.0};

    std::vector<FSpaceObject> EnemyMissiles;
    
    FSpline Path;

    bool bWouldStartSnake = false;
    bool BWouldStartGame = false;
    
    //timers
    float EnemyMovementTime = 0;
    float EnemyTime = 0;
    float MissileTime = 0;
    float SelectEnemyRandomTime = 0;
    
    float SnakeTime = 0;

    olc::Sprite* ShipSprite;
    olc::Decal* ShipDecal;

    olc::Sprite* EnemySprite;
    olc::Sprite* EnemySprite1;
    olc::Sprite* EnemySprite2;
    std::vector<olc::Decal*> EnemyDecals;

    olc::Sprite* MissileSprite;
    olc::Decal* MissileDecal;

    olc::Sprite* MissileEnemySprite;
    olc::Decal* MissileEnemyDecal;

    int Lives = 3;
    int Score = 0;


protected:
    virtual bool OnUserCreate() override;

    virtual bool OnUserUpdate(float fElapsedTime) override;

    void HandleInputs(float Timer);

    void MoveEnemies(float Timer);

    void InitializeSnake();

    void MoveEnemiesSnake( float Timer);

    void InizialiteSnakePath();
    
    //------------------------------------------------------------------------------------------------------------------
    void CreateEnemyMatrix();

    //------------------------------------------------------------------------------------------------------------------
    void InitializeReferences();
    
    //------------------------------------------------------------------------------------------------------------------
    void ConvertMatrixToSnake();

    void ShootRandomEnemy();

    //------------------------------------------------------------------------------------------------------------------
    bool HasCollidedBoxBox(const olc::vf2d& SizeBox1, const olc::vf2d& PositionBox1, const olc::vf2d& SizeBox2,
                           const olc::vf2d& PositionBox2) const;
    
    //------------------------------------------------------------------------------------------------------------------
    int GetRandomEnemy() const;

    //------------------------------------------------------------------------------------------------------------------
    void SelectRandomEnemy();

    //------------------------------------------------------------------------------------------------------------------
    void DeleteMissile();

    //------------------------------------------------------------------------------------------------------------------
    void DeleteEnemyMissile();

    //------------------------------------------------------------------------------------------------------------------
    void DeleteEnemy();

    bool OnUserDestroy() override
    {
        delete ShipSprite;
        delete ShipDecal;

        delete EnemySprite;
        delete EnemySprite1;
        delete EnemySprite2;
        
        delete MissileSprite;
        delete MissileDecal;

        delete MissileEnemySprite;
        delete MissileEnemyDecal;

        return true;
    }
};


