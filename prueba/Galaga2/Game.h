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
    int EnemyCountX = 3;
    int EnemyCountY = 1;
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
    FSpline Path2;
    
    //timers
    float EnemyMovementTime = 0;
    float EnemyTime = 0;
    float MissileTime = 0;
    float SelectEnemyRandomTime = 0;
    
    float SnakeTime = 0;
    int Score = 0;

    olc::Sprite* ShipSprite;
    olc::Decal* ShipDecal;

protected:
    virtual bool OnUserCreate() override
    {
        //Create Enemy Matrix
        for (int x = 0; x < EnemyCountX; x++)
        {
            for (int y = 0; y < EnemyCountY; y++)
            {
                std::shared_ptr<FEnemy> NewEnemy = std::make_shared<FEnemy>(olc::vf2d(7.0, 10.0),
                    olc::vf2d(-1000.0f, 10.0f),
                    olc::vf2d(0, 0));
                
                NewEnemy->SetOriginPosition(olc::vf2d((x * SizeEnemy.x) + (x * DistanceEnemy.x),
                              (y * SizeEnemy.y) + (y * DistanceEnemy.y)));
                
                MatrixEnemies.push_back(NewEnemy);
                Enemies.push_back(NewEnemy);
            }
        }

        ShipSprite = new olc::Sprite("./sprites/spaceShip.png");
        ShipDecal = new olc::Decal(ShipSprite);

        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime) override
    {
        // if(fElapsedTime > 5)
        // {
        //     fElapsedTime = 0.02;
        // }
        //////////////////////////////////////////////////////////////////////////
        /////              logic              ///////////////////////////////
        //////////////////////////////////////////////////////////////////////

        if (GetKey(olc::Key::LEFT).bHeld && SpaceShip.GetPosition().x > 3)
        {
            SpaceShip.SetVelocity(olc::vf2d(-50.0, SpaceShip.GetVelocity().y));
            SpaceShip.Mover(fElapsedTime);
        }

        if (GetKey(olc::Key::RIGHT).bHeld && SpaceShip.GetPosition().x < 100)
        {
            SpaceShip.SetVelocity(olc::vf2d(50.0, SpaceShip.GetVelocity().y));
            SpaceShip.Mover(fElapsedTime);
        }

        if (GetKey(olc::Key::UP).bPressed)
        {
            Missiles.push_back({
                olc::vf2d(2.0, 3.0),
                olc::vf2d(SpaceShip.GetPosition().x + SpaceShip.GetSize().x / 2,
                          (float)SpaceShip.GetPosition().y),
                olc::vf2d(0.0f, -60.0f)
            });
        }

        //////////////////////////////////////////////////////////////////////////
        /////              updating            ///////////////////////////////
        //////////////////////////////////////////////////////////////////////

        //
        EnemyTime += fElapsedTime;
        
        if(!MatrixEnemies.empty())
        {
            if(OutEnemyCount < MatrixEnemies.size() && EnemyTime > 0.5f)
            {
                std::shared_ptr<FEnemy> Enemy = MatrixEnemies[OutEnemyCount].lock();
                Enemy->UpdateIsSnake(true);
                OutEnemyCount++;
                EnemyTime = 0.0f;
            }
           
        }
        
        
        //Select RandomEnemy to shoot
        MissileTime += fElapsedTime;
        if (MissileTime >= 1.0f)
        {
            const int RandomValue = GetRandomEnemy();
            std::shared_ptr<FEnemy> RandomEnemy = Enemies[RandomValue];
            EnemyMissiles.push_back({
                olc::vf2d(2.0, 3.0),
                olc::vf2d(RandomEnemy->GetPosition().x + RandomEnemy->GetSize().x / 2,
                          (float)RandomEnemy->GetPosition().y),
                olc::vf2d(0.0f, 60.0f)
            });
            MissileTime = 0;
        }

        //logic EnemyMissiles
        for (auto& EnemyMissile : EnemyMissiles)
        {
            EnemyMissile.Mover(fElapsedTime);
            //collision between ship and EnemyMissile
            if (HasCollidedBoxBox(EnemyMissile.GetSize(), EnemyMissile.GetPosition(), SpaceShip.GetSize(),
                                  SpaceShip.GetPosition()))
            {
                Score = Score - 50;
            }
        }

        //Select EnemyRandom to RandomMove
        SelectEnemyRandomTime = SelectEnemyRandomTime + fElapsedTime;
        std::cout << SelectEnemyRandomTime <<std::endl;
        
        if (SelectEnemyRandomTime >= 10.0f)
        {
            SelectRandomEnemy();
            SelectEnemyRandomTime = 0;
        }
        
        
        //enemies movement
        EnemyMovementTime = EnemyMovementTime + fElapsedTime;
        EnemyTime += fElapsedTime;
        for (const auto& EnemyWeak : MatrixEnemies)
        {
            std::shared_ptr<FEnemy> Enemy = EnemyWeak.lock();
            
            if (!Enemy)
            {
                continue;
            }
            if (!Enemy->IsDead())
            {
                Enemy->CalculateFormationPath(EnemyMovementTime);
                
                if (!Enemy->IsSelected() && !Enemy->IsSnake())
                {
                    Enemy->FollowFormationPath();
                }
                else if(Enemy->IsSnake())
                {
                    Enemy->ActivatePath(fElapsedTime, 1);
                }
                else if(Enemy->IsSelected())
                {
                    Enemy->ActivatePath(fElapsedTime, 2);
                }
            }
            else
            {
                Enemy->SetPosition(olc::vf2d(-100, -100));
            }
        }
        
        
        //Logic playerMissiles
        for (auto& Missile : Missiles)
        {
            Missile.Mover(fElapsedTime);
        
            //check the enemies
            for (const auto& Enemy : Enemies)
            {
                if (HasCollidedBoxBox(Enemy->GetSize(), Enemy->GetPosition(), Missile.GetSize(), Missile.GetPosition()))
                {
                    Missile.SetPosition(olc::vf2d(0, -100));
                    Enemy->IsDeadTrue();
                    Score = Score + 100;
                }
            }
        }

        // ///////////snake
        //  SnakeTime += fElapsedTime;
        //  std::cout << SnakeTime << std::endl;
        //  if(SnakeTime > 0.5 && SnakeEnemyCount < 6)
        //  {
        //      std::shared_ptr<FEnemy> NewEnemy = std::make_shared<FEnemy>(olc::vf2d(7.0, 10.0),
        //          olc::vf2d((0), 0),
        //          olc::vf2d(0, 0));
        //      NewEnemy->UpdateIsSelected(true);
        //      SnakeEnemies.push_back(NewEnemy);
        //      Enemies.push_back(NewEnemy);
        //      
        //      SnakeTime = 0.0f;
        //      SnakeEnemyCount++;
        //  }
        //
        //
        //     EnemyMovementTime = EnemyMovementTime + fElapsedTime;
        //     for(auto& EnemyWeak : SnakeEnemies)
        //     {
        //         std::shared_ptr<FEnemy> Enemy = EnemyWeak.lock();
        //         if(!Enemy)
        //         {
        //             continue;
        //         }
        //         if(!Enemy->IsDead())
        //         {
        //             Enemy->ActivatePath(fElapsedTime, 2);
        //         }
        //         else
        //         {
        //             Enemy->SetPosition(olc::vf2d(-100, -100));
        //         }
        //     }
        
        
        
        //Remove off screen Missile
        DeleteMissile();

        //Remove OffScreen Enemies
        //DeleteEnemy();

        //Remove OffScreen EnemyMissiles
        DeleteEnemyMissile();

       
        
        EndEnemy = SpaceShip.GetPosition();
        Path.Points = {
            {140, -20}, //0
            {120, 0}, //1
            {30, 65}, //2
            {30, 32}, //3
            {55, 46}, //4
            {65, 96}, //5
            {90, 86}, //6
            {65, 70}, //7
            {EndEnemy.x, 160},//9
            {EndEnemy.x, 200}//10
        };

        Path2.Points = {
            {-20, 200}, //0
            {10, 60}, //1
            {30, 85}, //2
            {50, 62}, //3
        };


        //////////////////////////////////////////////////////////////////////////
        /////              Render             ///////////////////////////////
        //////////////////////////////////////////////////////////////////////

        //clear screen
        FillRect(0, 0, 180, ScreenHeight(), olc::BLACK);
        DrawRect(0, 0, 107, ScreenHeight(), olc::RED);

        //Draw screen
        FillRect(108, 0, 83, ScreenHeight(), olc::BLUE);
        DrawString(110, 40, "SpaceShip", olc::BLACK, 1);
        DrawString(110, 50, "score :" + std::to_string(Score), olc::BLACK, 1);

        //draw player
        DrawRect(SpaceShip.GetPosition(), SpaceShip.GetSize(), olc::RED);

        //draw enemies
        for (const auto& Enemy : Enemies)
        {
            DrawRect(Enemy->GetPosition(), Enemy->GetSize(), olc::YELLOW);
        }

        //draw missiles
        for (auto& Missile : Missiles)
        {
            DrawRect(Missile.GetPosition(), Missile.GetSize(), olc::GREEN);
        }

        //draw EnemyMissiles
        for (auto& Missile : EnemyMissiles)
        {
            DrawRect(Missile.GetPosition(), Missile.GetSize(), olc::VERY_DARK_YELLOW);
        }

        //spline
        for (float t = 0.0f; t < static_cast<float>(Path.Points.size()) - 3.0f; t += 0.005f)
        {
            const FPoint2D pos = Path.GetSplinePoint(t);
            Draw(static_cast<int32_t>(pos.PositionX), static_cast<int32_t>(pos.PositionY));
        }

        //Call Path
        for (int i = 0; i < static_cast<int32_t>(Path.Points.size()); i++)
        {
            DrawRect(static_cast<int32_t>(Path.Points[i].PositionX) - 1, static_cast<int32_t>(Path.Points[i].PositionY) - 1, 8, 8, olc::RED);
            DrawString(static_cast<int32_t>(Path.Points[i].PositionX), static_cast<int32_t>(Path.Points[i].PositionY), std::to_string(i));
        }

        //dradecal
        olc::vf2d Scale = {0.016f, 0.02f};
        DrawDecal(SpaceShip.GetPosition(), ShipDecal, Scale);

        return true;
    }

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
};
