/*
Create a class called MilitaryClock that stores and displays the military time.

Your class should contain the following constructors and methods:
MilitaryClock();
MilitaryClock(short hours, short minutes);
void SetTime(short hours, short minutes);
void DisplayTime();

Here’s an example of how the class could be used:
MilitaryClock clock;
clock.Display();
clock = MilitaryClock(7,0);
clock.Display();
clock.SetTime(12, 15);
clock.Display();

Don’t forget that military time is displayed as hhmm so add a preceding 0 before hours/minutes if their value is less than 10.
*/

#include <iostream>


class FMilitaryClock
{

private:

	short Hours;
	short Minutes;

public:

	FMilitaryClock()
	{
		Hours = 0;
		Minutes = 0;
	}

	FMilitaryClock (short MilitaryHours, short MilitaryMinutes)
	{
		Hours = MilitaryHours;
		Minutes = MilitaryMinutes;
	}
//-----------------------------------------------------------------------
	void SetTime (short MilitaryHours, short MilitaryMinutes)
	{
		Hours = MilitaryHours;
		Minutes = MilitaryMinutes;
	}
//-----------------------------------------------------------------------
	void DisplayTime()
	{
		if (Hours < 10)
		{
			std::cout << "0" << Hours;
		}
		else 
		{
			std::cout << Hours;
		}
		if (Minutes < 10)
		{
			std::cout << "0" << Minutes;
		}
		else
		{
			std::cout << Minutes;
		}
		std::cout << std::endl;
	}
};

int main()
{
	FMilitaryClock Clock;
	Clock.DisplayTime();
	Clock = FMilitaryClock(5, -2);
	Clock.DisplayTime();
	Clock.SetTime(10, 10);
	Clock.DisplayTime();

}