#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class FGame : public olc::PixelGameEngine
{
public:
	FGame()
	{
		sAppName = "FlappyBird";
	}

private:
	struct FBird
	{
		float BirdPosition = 0.0f;
		float BirdVelocity = 0.0f;
		float BirdAcceleration = 0.0f;
	};

	FBird* Bird = new FBird;

	float Gravity = 600.0f;

	float SectionWidth;
	std::list<int> ListSection;
	float LevelPosition = 0.0f;

	bool bHasCollided = false;

	int AttempCount = 0;
	int FlapCount = 0;
	int MaxFlapCount = 0;

	bool bResetGame = false;

protected:
	virtual bool OnUserCreate() override
	{
		ListSection = { 0, 0, 0, 0 };
		SectionWidth = (float)ScreenWidth() / (float)(ListSection.size() - 1);
		bResetGame = true;

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (bResetGame)
		{
			ResetGame();
		}
		if (bHasCollided)
		{
			if (GetKey(olc::Key::SPACE).bReleased)
				bResetGame = true;
		}
		else
		{

			if (GetKey(olc::Key::SPACE).bPressed)
			{
				Bird->BirdAcceleration = 0.0f;
				Bird->BirdVelocity = -Gravity / 4.50f;
				FlapCount++;
				if (FlapCount > MaxFlapCount)
					MaxFlapCount = FlapCount;
			}
			else
				Bird->BirdAcceleration += Gravity * fElapsedTime;

			if (Bird->BirdAcceleration >= Gravity)
				Bird->BirdAcceleration = Gravity;

			Bird->BirdVelocity += Bird->BirdAcceleration * fElapsedTime;
			Bird->BirdPosition += Bird->BirdVelocity * fElapsedTime;

			LevelPosition += 25.0f * 4.0f * fElapsedTime;

			if (LevelPosition > SectionWidth)
			{
				LevelPosition -= SectionWidth;
				ListSection.pop_front();
				int i = rand() % (int)(ScreenHeight() * 0.8);
				if (i <= 0.6) i = 0;
				ListSection.push_back(i);
			}


			FillRect(0, 0, ScreenWidth(), ScreenHeight(), olc::Pixel(136,235,255,255));

			int BirdX= (int)(ScreenWidth() / 3.0f);

			int Section = 0;
			for (auto s : ListSection)
			{
				int sectionStart = Section * SectionWidth;
				int RectangleStart = sectionStart - LevelPosition + 40;
				int LowerRectangleStartY = ScreenHeight() - s;
				int RectangleWight = SectionWidth / 3;
				int UpperRectangleOfsset = ScreenHeight() - s - 90;

				if (s != 0)
				{ 
					FillRect(RectangleStart,
						LowerRectangleStartY,
						RectangleWight,
						ScreenHeight(),
						olc::GREEN);
					FillRect(RectangleStart,
						0,
						RectangleWight,
						UpperRectangleOfsset,
						olc::GREEN);

					if(Section == 1)
					{
						bool XYUpperLeft  = BirdX > RectangleStart && BirdX < RectangleStart + RectangleWight && Bird->BirdPosition < UpperRectangleOfsset;
						bool XYUpperRight = BirdX + 40 > RectangleStart && BirdX + 40 < RectangleStart + RectangleWight && Bird->BirdPosition < UpperRectangleOfsset;
						bool XYLowerLeft = BirdX > RectangleStart && BirdX < RectangleStart + RectangleWight && Bird->BirdPosition + 16 > LowerRectangleStartY;
						bool XYLowerRight = BirdX + 40 > RectangleStart && BirdX + 40 < RectangleStart + RectangleWight && Bird->BirdPosition + 16 > LowerRectangleStartY;

						bHasCollided = Bird->BirdPosition < 2
							|| Bird->BirdPosition > ScreenHeight() - 2
							|| (XYUpperLeft)
							|| (XYUpperRight)
							|| (XYLowerLeft)
							|| (XYLowerRight);
					}
					
				}
				Section++;
			}

			DrawingBird(BirdX );

			DrawString(1, 1, "attemp: " + std::to_string(AttempCount) + "Score: " + std::to_string(FlapCount) + "high score: " + std::to_string(MaxFlapCount));
		}
		return true;
	}

	private:
		void ResetGame()
		{
			bHasCollided = false;
			bResetGame = false;
			ListSection = { 0,0,0,0 };
			Bird->BirdAcceleration = 0.0f;
			Bird->BirdVelocity = 0.0f;
			Bird->BirdPosition = ScreenHeight() / 2.0f;
			FlapCount = 0;
			AttempCount++;
		}

		void DrawingBird(int BirdX)
		{
			// Draw
			if (Bird->BirdVelocity > 0)
			{
				DrawString(BirdX, Bird->BirdPosition + 0, "E=)0>", olc::YELLOW);
				DrawString(BirdX, Bird->BirdPosition + 8, "//", olc::YELLOW);
			}
			else
			{
				DrawString(BirdX, Bird->BirdPosition + 0, " //", olc::YELLOW);
				DrawString(BirdX, Bird->BirdPosition + 8, "E=)0>", olc::YELLOW);
			}
		}
};


int main()
{
	FGame demo;
	if (demo.Construct(720, 350, 2, 2))
		demo.Start();

	return 0;
}