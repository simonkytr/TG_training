#include "Game.h"

bool FGame::OnUserCreate()
{
    InitializeReferences();
        
    CreateEnemyMatrix();

    return true;
}

 bool FGame::OnUserUpdate(float fElapsedTime)
    {
    
        //////////////////////////////////////////////////////////////////////////
        /////              Logic           ///////////////////////////////
        //////////////////////////////////////////////////////////////////////
        
        HandleInputs(fElapsedTime);
    
        //////////////////////////////////////////////////////////////////////////
        /////              updating            ///////////////////////////////
        //////////////////////////////////////////////////////////////////////

        if(Lives == 0)
        {
            BWouldStartGame = false;
        }
        
        if(BWouldStartGame)
        {
            EnemyTime += fElapsedTime;
            ConvertMatrixToSnake();
            
            MissileTime += fElapsedTime;
            ShootRandomEnemy();

            // EnemyMissiles logic
            for (auto& EnemyMissile : EnemyMissiles)
            {
                EnemyMissile.Mover(fElapsedTime);
                //collision between ship and EnemyMissile
                if (HasCollidedBoxBox(EnemyMissile.GetSize(), EnemyMissile.GetPosition(),
                                                SpaceShip.GetSize(), SpaceShip.GetPosition()))
                {
                    EnemyMissile.SetPosition(olc::vf2d(-10, -10));
                    SpaceShip.UpdateIsDead(true);
                }
            }
            
            if(SpaceShip.IsDead())
            {
                Lives = Lives - 1;
                SpaceShip.UpdateIsDead(false);
            }

            
            SelectEnemyRandomTime = SelectEnemyRandomTime + fElapsedTime;
            if (SelectEnemyRandomTime >= 10.0f)
            {
                SelectRandomEnemy();
                SelectEnemyRandomTime = 0;
            }

            
            EnemyMovementTime = EnemyMovementTime + fElapsedTime;
            MoveEnemies(fElapsedTime);
            
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
                        Enemy->UpdateIsDead(true);
                        Score = Score + 100;
                    }
                }
            }

            // Snake
            SnakeTime += fElapsedTime;
            if(MatrixEnemies.empty() || bWouldStartSnake == true)
            {
                InitializeSnake();
                
                MoveEnemiesSnake(fElapsedTime);
            }
            
            //Remove off screen Missile
            DeleteMissile();

            //Remove OffScreen Enemies
            DeleteEnemy();

            //Remove OffScreen EnemyMissiles
            DeleteEnemyMissile();
        }
    
    EndEnemy = SpaceShip.GetPosition();
    InizialiteSnakePath();
    
        //////////////////////////////////////////////////////////////////////////
        /////              Render             ///////////////////////////////
        //////////////////////////////////////////////////////////////////////
        
        if(!BWouldStartGame)
        {
            DrawString(20, 40, "Press enter to play", olc::WHITE, 1);
        }
        else
        {
            
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

            //Draw EnemyMissiles
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

            //Draw Lives count
            for(int i = 0; i < Lives; i++)
            {
                ScaleShip = {0.05f, 0.055f};
                DrawDecal(olc::vf2d((i * SizeEnemy.x) + (132), 110), ShipDecal, ScaleShip);
            }
        }
        
        return true;
    }
//----------------------------------------------------------------------------------------------------------------------
void FGame::HandleInputs(float Timer)
{
    if(GetKey(olc::Key::ENTER).bPressed)
    {
        BWouldStartGame = true;
    }

    if (GetKey(olc::Key::LEFT).bHeld && SpaceShip.GetPosition().x > 3)
    {
        SpaceShip.SetVelocity(olc::vf2d(-50.0, SpaceShip.GetVelocity().y));
        SpaceShip.Mover(Timer);
    }

    if (GetKey(olc::Key::RIGHT).bHeld && SpaceShip.GetPosition().x < 100)
    {
        SpaceShip.SetVelocity(olc::vf2d(50.0, SpaceShip.GetVelocity().y));
        SpaceShip.Mover(Timer);
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
}

//----------------------------------------------------------------------------------------------------------------------
void FGame::InitializeReferences()
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
}

//----------------------------------------------------------------------------------------------------------------------
void FGame::CreateEnemyMatrix()
{
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
}



void FGame::MoveEnemies(float Timer)
{
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
                Enemy->ActivatePath(Timer, 0);
                break;

            case FEnemy::Selected:
                Enemy->ActivatePath(Timer, 1);
                break;
            }
        }
        else
        {
            Enemy->SetPosition(olc::vf2d(-100, -100));
        }
    }
};

void FGame::InitializeSnake()
{
    std::cout << SnakeTime << std::endl;
    if(SnakeTime > 0.5 && SnakeEnemyCount < 6)
    {
        std::shared_ptr<FEnemy> NewEnemy = std::make_shared<FEnemy>(olc::vf2d(7.0, 10.0),
            olc::vf2d((0), 0),
            olc::vf2d(0, 0));
        SnakeEnemies.push_back(NewEnemy);
        Enemies.push_back(NewEnemy);

        const int SelectEnemySprite = rand() % EnemyDecals.size();
        NewEnemy->SetDecal(EnemyDecals[SelectEnemySprite]);
                
        SnakeTime = 0.0f;
        SnakeEnemyCount++;
    }
}

void FGame::MoveEnemiesSnake( float Timer)
{
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
                Enemy->UpdateMarker(Timer);
            }
        }
                    
        else
        {
            Enemy->SetPosition(olc::vf2d(-100, -100));
        }
    }
};

void FGame::InizialiteSnakePath()
{
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
}




//----------------------------------------------------------------------------------------------------------------------
void FGame::ConvertMatrixToSnake()
{
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
}

//---------------------------------------------------------------------------------------------------------------------
void FGame::ShootRandomEnemy()
{
    if (MissileTime >= 0.3f && !MatrixEnemies.empty())
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
}

//----------------------------------------------------------------------------------------------------------------------
bool FGame::HasCollidedBoxBox(const olc::vf2d& SizeBox1, const olc::vf2d& PositionBox1,
                                const olc::vf2d& SizeBox2, const olc::vf2d& PositionBox2) const
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