#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

struct FPoint2D
{
	float PositionX;
	float PositionY;
};

struct FSpline
{
	std::vector<FPoint2D> Points;

	FPoint2D GetSplinePoint(float t, bool Blooped = false)
	{
		int Point0, Point1, Point2, Point3;
		if(!Blooped)
		{
			Point1 = (int)t + 1;
			Point2 = Point1 + 1;
			Point3 = Point2 + 1;
			Point0 = Point1 - 1;
		}
		else
		{
			Point1 = (int)t;
			Point2 = (Point1 + 1) % Points.size();
			Point3 = (Point2 + 1) % Points.size();
			Point0 = Point1 >= 1 ? Point1 - 1 : Points.size() - 1;
		}
		
		t = t -(int)t;

		float tt = t * t;
		float ttt = tt * t;

		//q = influence field values
		float q1 = -ttt + 2.0 * tt - t;
		float q2 = 3.0f * ttt - 5.0f * tt + 2.0f;
		float q3 = -3.0f * ttt + 4.0f * tt + t;
		float q4 = ttt - tt;

		float tx = 0.5f * (Points[Point0].PositionX * q1 + Points[Point1].PositionX * q2 + Points[Point2].PositionX * q3 + Points[Point3].PositionX * q4);
		float ty = 0.5f * (Points[Point0].PositionY * q1 + Points[Point1].PositionY * q2 + Points[Point2].PositionY * q3 + Points[Point3].PositionY * q4);
		
		return {tx,ty};
	}
	
	FPoint2D GetSplineGradient(float t, bool Blooped = false)
	{
		int Point0, Point1, Point2, Point3;
		if(!Blooped)
		{
			Point1 = (int)t + 1;
			Point2 = Point1 + 1;
			Point3 = Point2 + 1;
			Point0 = Point1 - 1;
		}
		else
		{
			Point1 = (int)t;
			Point2 = (Point1 + 1) % Points.size();
			Point3 = (Point2 + 1) % Points.size();
			Point0 = Point1 >= 1 ? Point1 - 1 : Points.size() - 1;
		}
		
		t = t -(int)t;

		float tt = t * t;
		float ttt = tt * t;

		//q = influence field values
		float q1 = -3.0f * tt + 4.0 * t - 1;
		float q2 = 9.0f * tt - 10.0f * t;
		float q3 = -9.0f * tt + 8.0f * t + 1.0f;
		float q4 = 3.0f * tt - 2 * t;

		float tx = 0.5f * (Points[Point0].PositionX * q1 + Points[Point1].PositionX * q2 + Points[Point2].PositionX * q3 + Points[Point3].PositionX * q4);
		float ty = 0.5f * (Points[Point0].PositionY * q1 + Points[Point1].PositionY * q2 + Points[Point2].PositionY * q3 + Points[Point3].PositionY * q4);
		
		return {tx,ty};
	}
};

class Example : public olc::PixelGameEngine
{
public: 
	Example()
	{
		sAppName = "Noise";
	}

public:
	FSpline Path;
	int SelectedPoint = 0;
	float Marker = 0.0f;
	
protected:
	bool OnUserCreate() override
	{
		//Path.Points = {{ 10, 41 },{ 40, 41 },{ 70, 41 },{ 100, 41 } };
		Path.Points = {{ 10, 41 },{ 10, 51 },{ 30, 41 },{ 30, 51 },{ 50, 41 },{ 60, 41 },{ 70, 41 },{ 80, 41 },{ 90, 41 },{ 100, 41 } };
		
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		// for (int x=0; x < ScreenWidth(); x++)
		// 	for (int y = 0; y < ScreenHeight(); y++)
		// 	{
		// 		Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand() % 255, rand() % 255));
		//
		//
		// 	}
		FillRect(0,0,ScreenHeight(),ScreenHeight(),olc::BLACK);
		//
		if(GetKey(olc::X).bReleased)
		{
			SelectedPoint++;
			if(SelectedPoint >= Path.Points.size())
				SelectedPoint = 0;
		}

		if(GetKey(olc::Z).bReleased)
		{
			SelectedPoint--;
			if(SelectedPoint < 0)
				SelectedPoint = Path.Points.size() - 1;
		}

		if(GetKey(olc::LEFT).bHeld)
			Path.Points[SelectedPoint].PositionX -= 30.0f * fElapsedTime;

		if(GetKey(olc::RIGHT).bHeld)
			Path.Points[SelectedPoint].PositionX += 30.0f * fElapsedTime;

		if(GetKey(olc::UP).bHeld)
			Path.Points[SelectedPoint].PositionY -= 30.0f * fElapsedTime;

		if(GetKey(olc::DOWN).bHeld)
			Path.Points[SelectedPoint].PositionY += 30.0f * fElapsedTime;


		if(GetKey(olc::A).bHeld)
			Marker -=5.0f * fElapsedTime;

		if(GetKey(olc::S).bHeld)
			Marker += 5.0f * fElapsedTime;

		if(Marker >= (float)Path.Points.size())
			Marker -= (float)Path.Points.size();

		if(Marker < 0.0f)
			Marker += (float)Path.Points.size();

		//spline
		for (float t = 0.0f; t < (float)Path.Points.size(); t += 0.005f)
		{
			FPoint2D pos = Path.GetSplinePoint(t, true);
			Draw(pos.PositionX, pos.PositionY);
		}
		
		//Call Path
		for(int i = 0; i < Path.Points.size(); i++)
		{
			DrawRect(Path.Points[i].PositionX - 1, Path.Points[i].PositionY - 1,  8, 8, olc::RED);
			DrawString(Path.Points[i].PositionX, Path.Points[i].PositionY, std::to_string(i));
		}

		//Hihtlight
		FillRect(Path.Points[SelectedPoint].PositionX - 1, Path.Points[SelectedPoint].PositionY - 1,  8, 8, olc::RED);
		DrawString(Path.Points[SelectedPoint].PositionX, Path.Points[SelectedPoint].PositionY, std::to_string(SelectedPoint));


		//DrawAgent
		FPoint2D Point1 = Path.GetSplinePoint(Marker);
		FPoint2D Gradient1 = Path.GetSplineGradient(Marker);

		float r = atan2(-Gradient1.PositionY, Gradient1.PositionX);
		DrawLine(5.0f * std::sin(r) + Point1.PositionX, 5.0f * cos(r) + Point1.PositionY, -5.0f * sin(r) +Point1.PositionX, -5.0f * cos(r) + Point1.PositionY, olc::BLUE );
		
		 return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(160, 80, 10, 10)) 
		demo.Start();

	return 0;
}
