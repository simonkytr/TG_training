/*
Exercise 2 - Military Clock
Create a class called MilitaryClock that stores and displays the military time.
*/

#include <iostream>


class MilitaryClock
{

private:

	short hours;
	short minutes;

public:

	MilitaryClock()
	{
		hours = 0;
		minutes = 0;
	}

	MilitaryClock(short MilitaryHours, short MilitaryMinutes)
	{
		hours = MilitaryHours;
		minutes = MilitaryMinutes;
	}

	void setTime(short MilitaryHours, short MilitaryMinutes)
	{
		hours = MilitaryHours;
		minutes = MilitaryMinutes;
	}

	void displayTime()
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
	MilitaryClock clock;
	clock.displayTime();
	clock = MilitaryClock(7, 0);
	clock.displayTime();
	clock.setTime(12, 15);
	clock.displayTime();

}