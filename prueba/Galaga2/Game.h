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
    int Score = 0;

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


protected:
    virtual bool OnUserCreate() override
    {
        ShipSprite = new olc::Sprite("./sprites/Ship.png");
        ShipDecal = new olc::Decal(ShipSprite);

        EnemySprite = new olc::Sprite("./sprites/Bee.png");
        EnemyDecals.push_back(new olc::Decal(EnemySprite));

        EnemySprite1 = new olc::Sprite("./sprites/Butterfly.png");
        EnemyDecals.push_back(new olc::Decal(EnemySprite1));

        MissileSprite = new olc::Sprite("./sprites/Missile.png");
        MissileDecal = new olc::Decal(MissileSprite);

        MissileEnemySprite = new olc::Sprite("./sprites/EnemyBullets.png");
        MissileEnemyDecal = new olc::Decal(MissileEnemySprite);

        //Create Enemy Matrix
        for (int x = 0; x < EnemyCountX; x++)
        {
            for (int y = 0; y < EnemyCountY; y++)
            {
                std::shared_ptr<FEnemy> NewEnemy = std::make_shared<FEnemy>(olc::vf2d(11.0, 10.0),
                    olc::vf2d(-1000.0f, 10.0f),
                    olc::vf2d(0, 0));
                
                NewEnemy->SetOriginPosition(olc::vf2d((x * SizeEnemy.x) + (x * DistanceEnemy.x),
                              (y * SizeEnemy.y) + (y * DistanceEnemy.y)));

                NewEnemy->SetState(FEnemy::Start);

                int SelectEnemySprite = rand() % EnemyDecals.size();
                NewEnemy->SetDecal(EnemyDecals[SelectEnemySprite]);
                
                MatrixEnemies.push_back(NewEnemy);
                Enemies.push_back(NewEnemy);
            }
        }

        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime) override
    {
        
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

        if (GetKey(olc::Key::UP).bPressed && BWouldStartGame)
        {
            Missiles.push_back({
                olc::vf2d(2.0, 3.0),
                olc::vf2d(SpaceShip.GetPosition().x + SpaceShip.GetSize().x / 2,
                          (float)SpaceShip.GetPosition().y),
                olc::vf2d(0.0f, -200.0f)
            });
        }

        //Start game
        if(GetKey(olc::Key::ENTER).bPressed)
        {
            BWouldStartGame = true;
        }

        //////////////////////////////////////////////////////////////////////////
        /////              updating            ///////////////////////////////
        //////////////////////////////////////////////////////////////////////

        if(Lives == 0)
        {
            BWouldStartGame = false;
        }
        if(BWouldStartGame)
        {
            //convert Matrix to Snake
            
        EnemyTime += fElapsedTime;
        if(!MatrixEnemies.empty() && OutEnemyCount < static_cast<int>(MatrixEnemies.size()))
        {
            const std::shared_ptr<FEnemy> Enemy = MatrixEnemies[OutEnemyCount].lock();
            
            if(OutEnemyCount < static_cast<int>(MatrixEnemies.size()) && EnemyTime > 0.5f)
            {
                Enemy->SetState(FEnemy::Snake);
            
                OutEnemyCount++;
                EnemyTime = 0.0f;
            }
        }
        
        //Select RandomEnemy to shoot
        MissileTime += fElapsedTime;
        if (MissileTime >= 1.0f && !MatrixEnemies.empty())
        {
            const int RandomValue = GetRandomEnemy();

            if(RandomValue != -1)
            {
                std::shared_ptr<FEnemy> RandomEnemy = Enemies[RandomValue];
                EnemyMissiles.push_back({
                    olc::vf2d(2.0, 3.0),
                    olc::vf2d(RandomEnemy->GetPosition().x + RandomEnemy->GetSize().x / 2,
                              (float)RandomEnemy->GetPosition().y),
                    olc::vf2d(0.0f, 60.0f)
                });
                MissileTime = 0;
            }
            else
            {
                bWouldStartSnake = true;
            }
        }

        //logic EnemyMissiles
        for (auto& EnemyMissile : EnemyMissiles)
        {
            EnemyMissile.Mover(fElapsedTime);
            //collision between ship and EnemyMissile
            if (HasCollidedBoxBox(EnemyMissile.GetSize(), EnemyMissile.GetPosition(), SpaceShip.GetSize(),
                                  SpaceShip.GetPosition()))
            {
                Lives = Lives - 1;
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
                
                switch (Enemy->GetState())
                {
                case FEnemy::Start:
                    Enemy->SetPosition(olc::vf2d(-10, 0));
                    break;
                    
                case FEnemy::Formation:
                    Enemy->FollowFormationPath();
                    break;

                case FEnemy::Snake:
                    Enemy->ActivatePath(fElapsedTime, 0);
                    break;

                case FEnemy::Selected:
                    Enemy->ActivatePath(fElapsedTime, 1);
                    break;
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
        SnakeTime += fElapsedTime;
            
        if(MatrixEnemies.empty() || bWouldStartSnake == true)
        {
            std::cout << SnakeTime << std::endl;
            if(SnakeTime > 0.5 && SnakeEnemyCount < 6)
            {
                std::shared_ptr<FEnemy> NewEnemy = std::make_shared<FEnemy>(olc::vf2d(7.0, 10.0),
                    olc::vf2d((0), 0),
                    olc::vf2d(0, 0));
                SnakeEnemies.push_back(NewEnemy);
                Enemies.push_back(NewEnemy);

                int SelectEnemySprite = rand() % EnemyDecals.size();
                NewEnemy->SetDecal(EnemyDecals[SelectEnemySprite]);
            
                SnakeTime = 0.0f;
                SnakeEnemyCount++;
            }
        
            EnemyMovementTime = EnemyMovementTime + fElapsedTime;
            for(auto& EnemyWeak : SnakeEnemies)
            {
                std::shared_ptr<FEnemy> Enemy = EnemyWeak.lock();
                if(!Enemy)
                {
                    continue;
                }
                if(!Enemy->IsDead())
                {
                    if (Enemy->GetMarker() < static_cast<float>(Path.Points.size() - 3.0f))
                    {
                        const FPoint2D Point1 = Path.GetSplinePoint(Enemy->GetMarker());
                        Enemy->SetPosition(olc::vf2d(Point1.PositionX, Point1.PositionY));
                        Enemy->CalculateAngle(Path);
                        Enemy->UpdateMarker(fElapsedTime);
                    }
                }
                else
                {
                    Enemy->SetPosition(olc::vf2d(-100, -100));
                }
            }
        }
        
        
        //Remove off screen Missile
        DeleteMissile();

        //Remove OffScreen Enemies
        DeleteEnemy();

        //Remove OffScreen EnemyMissiles
        DeleteEnemyMissile();
        }
        
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


        //////////////////////////////////////////////////////////////////////////
        /////              Render             ///////////////////////////////
        //////////////////////////////////////////////////////////////////////
        
        if(!BWouldStartGame)
        {
            DrawString(20, 40, "Press enter to play", olc::WHITE, 1);
        }
        else
        {
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

        
        //DrawPlayer
        olc::vf2d ScaleShip = {0.05f, 0.055f};
        DrawDecal(olc::vf2d(SpaceShip.GetPosition().x - 1.6, SpaceShip.GetPosition().y), ShipDecal, ScaleShip);

        //Draw enemies
        if(!Enemies.empty())
        {
            for (const auto& Enemy : Enemies)
            {
                olc::vf2d ScaleEnemy = {0.02f, 0.02f};
                float Angle = Enemy->GetAngle();
            
                DrawRotatedDecal(olc::vf2d(Enemy->GetPosition().x + 5.5f, Enemy->GetPosition().y + 5), Enemy->GetDecal(), Angle, {312.5f,240.5f}, ScaleEnemy);
            }
        }

        //Draw Missiles
        for (auto& Missile : Missiles)
        {
            olc::vf2d Scale = {0.02f, 0.02f};
            DrawDecal(olc::vf2d(Missile.GetPosition().x, Missile.GetPosition().y), MissileDecal, Scale);
        }

        //draw EnemyMissiles
        for (auto& Missile : EnemyMissiles)
        {
            olc::vf2d Scale = {0.01f, -0.01f};
            DrawDecal(olc::vf2d(Missile.GetPosition().x, Missile.GetPosition().y + 2), MissileEnemyDecal, Scale);
        }

        //clear screen
        FillRect(0, 0, 180, ScreenHeight(), olc::BLACK);
        DrawRect(0, 0, 107, ScreenHeight(), olc::RED);

        //Draw screen
        FillRect(108, 0, 83, ScreenHeight(), olc::BLUE);
        
        DrawString(110, 50, "score :", olc::WHITE, 1);
        DrawString(110, 60, std::to_string(Score), olc::WHITE, 1);
        DrawString(110, 90, "lives", olc::WHITE, 1);

            for(int i = 0; i < Lives; i++)
            {
                ScaleShip = {0.05f, 0.055f};
                DrawDecal(olc::vf2d((i * SizeEnemy.x) + (131), 110), ShipDecal, ScaleShip);

            }
            
        }
        
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


