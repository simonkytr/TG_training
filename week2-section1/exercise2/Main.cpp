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

	short hours;
	short minutes;

public:

	FMilitaryClock()
	{
		hours = 0;
		minutes = 0;
	}

	FMilitaryClock(short MilitaryHours, short MilitaryMinutes)
	{
		hours = MilitaryHours;
		minutes = MilitaryMinutes;
	}

	void SetTime(short MilitaryHours, short MilitaryMinutes)
	{
		hours = MilitaryHours;
		minutes = MilitaryMinutes;
	}

	void DisplayTime()
	{
		if (hours < 10)
		{
			std::cout << "0" << hours;
		}
		
		if (minutes < 10)
		{
			std::cout << "0" << minutes;
		}
		else
		{
			std::cout << hours << minutes;
		}
		std::cout << std::endl;
	}
};

int main()
{
	FMilitaryClock clock;
	clock.DisplayTime();
	clock = FMilitaryClock(7, 0);
	clock.DisplayTime();
	clock.SetTime(12, 15);
	clock.DisplayTime();

}