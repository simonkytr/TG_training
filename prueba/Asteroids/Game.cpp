#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class FGame : public olc::PixelGameEngine
{
public:
	FGame()
	{
		sAppName = "Asteroids";
	}

private:
	struct FSpaceObject
	{
		float x;
		float y;
		float dx;
		float dy;
		int nSize;
		float angle;
	};

	std::vector<FSpaceObject> Asteroids;
	std::vector<FSpaceObject> Bullets;

	FSpaceObject Player;

	int nScore = 0;
	int level = 0;
	bool bIsDead = false;

	std::vector<std::pair<float, float>> ModelShip;
	std::vector<std::pair<float, float>> ModelAsteroid;

protected:
	virtual bool OnUserCreate() override
	{
		//a simple isoceles triangle
		ModelShip =
		{
			{0.0f, -5.0f},
			{-2.5f, +2.5f},
			{+2.5f, +2.5f}
		};

		//create asteroid
		int Verts = 20;
		for (int i = 0; i < Verts; i++)
		{
			float Radius = (float)std::rand() / (float)RAND_MAX * 0.4f + 0.8f;
			float a = ((float)i / (float)Verts) * 6.28318f;
			ModelAsteroid.push_back(std::make_pair(Radius * std::sinf(a), Radius * std::cosf(a)));
		}

		ResetGame();
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (bIsDead)
			ResetGame();

		//clear screen
		FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::BLACK);   

		//move the ship
		MoveShip(fElapsedTime);

		//Shoot bullets
		ShootBullets();

		//update and Draw the asteroids
		UpdateAsteroid(fElapsedTime);

		//Check collision with asteroids
		for (auto& Asteroid : Asteroids)
		{
			if (IsPointInsideCircle(Asteroid.x, Asteroid.y, Asteroid.nSize, Player.x, Player.y))
			{
				bIsDead = true;
			}
		}	
				
		std::vector<FSpaceObject> NewAsteroids;

		//Update and draw bullets
		for (auto& Bullet : Bullets)
		{
			Bullet.x += Bullet.dx * fElapsedTime;
			Bullet.y += Bullet.dy * fElapsedTime;

			WrapCoordinates(Bullet.x, Bullet.y, Bullet.x, Bullet.y);
			Draw(Bullet.x, Bullet.y);
			//check the asteroids
			for (auto& Asteroid : Asteroids)
			{
				if (IsPointInsideCircle(Asteroid.x, Asteroid.y, Asteroid.nSize, Bullet.x, Bullet.y))
				{
					//asteroid Hit
					Bullet.x = -100;
					if (Asteroid.nSize > 4)
					{
						// create two child asteroids
						float angle1 = ((float)std::rand() / (float)RAND_MAX) * 6.28318f;
						float angle2 = ((float)std::rand() / (float)RAND_MAX) * 6.28318f;
						NewAsteroids.push_back({ Asteroid.x, Asteroid.y, 10.0f * std::sinf(angle1), 10.0f * std::cosf(angle1), (int)Asteroid.nSize >> 1, 0.0f });
						NewAsteroids.push_back({ Asteroid.x, Asteroid.y, 10.0f * std::sinf(angle2), 10.0f * std::cosf(angle2), (int)Asteroid.nSize >> 1, 0.0f });
					}
					Asteroid.x = -100;
					nScore += 100;
				}

			}
		}

		// Append new asteroids to existing vector
		for (auto Asteroid : NewAsteroids)
		{
			Asteroids.push_back(Asteroid);
		}

		//Remove off screen bullets
		if (Bullets.size() > 0)
		{
			auto i = std::remove_if(Bullets.begin(), Bullets.end(), [&](FSpaceObject Object) {return (Object.x < 1 || Object.y < 1 || Object.x >= ScreenWidth() - 1 || Object.y >= ScreenHeight() - 1); });
			if (i != Bullets.end())
				Bullets.erase(i);
		}

		// Remove asteroids that have been blown up
		if (Asteroids.size() > 0)
		{
			auto i = std::remove_if(Asteroids.begin(), Asteroids.end(), [&](FSpaceObject Object) { return (Object.x < 0); });
			if (i != Asteroids.end())
				Asteroids.erase(i);
		}

		if (Asteroids.empty())
		{
			nScore += 1000;
			Asteroids.clear();
			Bullets.clear();
			level++;
			// Add two new asteroids, but in a place where the player is not, we'll simply
			// add them 90 degrees left and right to the player, their coordinates will
			// be wrapped by th enext asteroid update
			for (int i = 0; i < level; i++)
			{
				Asteroids.push_back({ (float)(std::rand() % 65 - 5)+ 30.0f * sinf(Player.angle - 3.14159f / 2.0f) + Player.x,
									(float)(std::rand() % 65 - 5) + 30.0f * cosf(Player.angle - 3.14159f / 2.0f) + Player.y,
									(float)(std::rand() % 2 - 1) + 10.0f * sinf(Player.angle),
									(float)(std::rand() % 2 - 1) +  10.0f * cosf(Player.angle), (int)16, 0.0f });

			}
		}

		//DrawShip
		DrawWireFrameModel(ModelShip, Player.x, Player.y, Player.angle);

		//DrawScore
		DrawString(2, 2, "Score: " + std::to_string(nScore));

	return true;


	}

	//--------------------------------------------------------------------------------------------------------------------------
	void MoveShip(float fElapsedTime)
	{
		//Steer
		if (GetKey(olc::Key::LEFT).bHeld)
			Player.angle -= 5.0f * fElapsedTime;
		if (GetKey(olc::Key::RIGHT).bHeld)
			Player.angle += 5.0f * fElapsedTime;

		//Thrust
		if (GetKey(olc::Key::UP).bHeld)
		{
			//Acceleration changes velocity 
			Player.dx += std::sin(Player.angle) * 20.0f * fElapsedTime;
			Player.dy += -std::cos(Player.angle) * 20.0f * fElapsedTime;
		}

		//Velocity changes Position
		Player.x += Player.dx * fElapsedTime;
		Player.y += Player.dy * fElapsedTime;

		//keep ship in gamespace
		WrapCoordinates(Player.x, Player.y, Player.x, Player.y);
	}

	//--------------------------------------------------------------------------------------------------------------------------
	void ShootBullets()
	{
		//Fire Bullets in direction of player
		float BulletImpulse = 0.2;
		if (GetKey(olc::Key::SPACE).bReleased)
		{
			Bullets.push_back({ Player.x, Player.y, 50.0f * std::sinf(Player.angle), -50.0f * std::cosf(Player.angle), 0, 0 });

			//thirdth newton's law
			Player.dx += -std::sin(Player.angle) * 20.0f + BulletImpulse;
			Player.dy += std::cos(Player.angle) * 20.0f + BulletImpulse;


		}
	}

	//--------------------------------------------------------------------------------------------------------------------------
	void UpdateAsteroid(float fElapsedTime)
	{
		for (auto& Asteroid : Asteroids)
		{
			Asteroid.x += Asteroid.dx * fElapsedTime;
			Asteroid.y += Asteroid.dy * fElapsedTime;
			Asteroid.angle += 0.5f * fElapsedTime;
			WrapCoordinates(Asteroid.x, Asteroid.y, Asteroid.x, Asteroid.y);
			DrawWireFrameModel(ModelAsteroid, Asteroid.x, Asteroid.y, Asteroid.angle, Asteroid.nSize, olc::YELLOW);
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------
	bool IsPointInsideCircle(float CircleX, float CircleY, float Radius, float PositionX, float PositionY)
	{
		return std::sqrt((PositionX - CircleX) * (PositionX - CircleX) + (PositionY - CircleY) * (PositionY - CircleY)) < Radius;
	}

	//--------------------------------------------------------------------------------------------------------------------------
	void DrawWireFrameModel(const std::vector<std::pair<float, float>>& vecModelCoordinates, float x, float y, float r = 0.0f, float s = 1.0f, olc::Pixel p = olc::WHITE)
	{
		//pair.first = x;
		//pair.second = y;
		
		//create translated model vector
		std::vector<std::pair<float, float>> vecTransformedCoordinates;
		int verts = vecModelCoordinates.size();
		vecTransformedCoordinates.resize(verts);

		
		//Rotate
		for (int i = 0; i < verts; i++)
		{
			vecTransformedCoordinates[i].first = vecModelCoordinates[i].first * cosf(r) - vecModelCoordinates[i].second * sinf(r);
			vecTransformedCoordinates[i].second = vecModelCoordinates[i].first * sinf(r) + vecModelCoordinates[i].second * cosf(r);
		}

		// Scale
		for (int i = 0; i < verts; i++)
		{
			vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first * s;
			vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second * s;
		}

		//Translate
		for (int i = 0; i < verts; i++)
		{
			vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first + x;
			vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second + y;
		}

		//Draw Closed Polygon 
		for (int i = 0; i < verts; i++)
		{
			int j = (i + 1);
			DrawLine(vecTransformedCoordinates[i % verts].first, vecTransformedCoordinates[i % verts].second,
				vecTransformedCoordinates[j % verts].first, vecTransformedCoordinates[j % verts].second, p);
		
		}
	}

	//--------------------------------------------------------------------------------------------------------------------------
	void WrapCoordinates(float Ix, float Iy, float &Ox, float &Oy)
	{
		Ox = Ix;
		Oy = Iy;

		if (Ix < 0.0f) Ox = Ix + (float) ScreenWidth();
		if (Ix >= (float) ScreenWidth()) Ox = Ix - (float) ScreenWidth();
		if (Iy < 0.0f) Oy = Iy + (float) ScreenHeight();
		if (Iy >= (float) ScreenHeight()) Oy = Iy - (float) ScreenHeight();
	}

	//--------------------------------------------------------------------------------------------------------------------------
	virtual bool Draw(int32_t x, int32_t y, olc::Pixel p = olc::WHITE)
	{
		float fx, fy;
		WrapCoordinates(x, y, fx, fy);
		
		return olc::PixelGameEngine::Draw(fx, fy, p);
	}

	//--------------------------------------------------------------------------------------------------------------------------
	void ResetGame()
	{
		Asteroids.clear();
		Bullets.clear();

		Asteroids.push_back({ 20.0f, 20.0f, 8.0f, -6.0f, (int)16, 0.0f });
		
		//Initialize player position
		Player.x = ScreenWidth() / 2;
		Player.y = ScreenHeight() / 2;
		Player.dx = 0.0f;
		Player.dy = 0.0f;
		Player.angle = 0.0f;

		bIsDead = false;
		nScore = 0;
	}
};

int main()
{
	FGame Game;
	Game.Construct(260, 200, 3, 3);
	Game.Start();
	return 0;
}