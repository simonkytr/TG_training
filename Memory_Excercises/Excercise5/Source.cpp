/*Exercise 5 - Dynamic Allocation for Array Sizes
*Create a Student class that contains a char array of size 5 for a name and an int for an age. Ask
*the user to enter how many students they want in a class. Then, initialize an array of students in
*the heap of exactly the size they asked for. You can now probably tell how dynamic allocation is
*useful.
*Ask the user for a name and an age for each student and then print them all to the screen. Note
*that you won’t be able to use names longer than 4 characters.
*Remember to free any allocated memory.*/

/**/

#include <iostream>


class FStudent
{
public:
	char* NameStudent;
	int StudentAge;

	FStudent()
	{
		NameStudent = nullptr;
		StudentAge = 0;
	}

	//----------------------------------------------
	FStudent( int NewAge)
	{
		NameStudent = nullptr;
		StudentAge = NewAge;
	}

	//----------------------------------------------
	~FStudent()
	{
		delete NameStudent;
	}

	//----------------------------------------------
	void SetName(const char* NewName)
	{
		/*Exercise 9: At this point, it’s obvious that keeping track of all memory allocations in a program can be a hassle. In the future, 
		*we’ll discuss techniques that will make life a lot easier for us.
		*/

		if (NameStudent != nullptr)
		{
			NameStudent = nullptr;
		}

		int NameLenght = 0;
		for (int i = 0; i < 32; i++)
		{
			if (NewName[i] != '\0')
			{
				NameLenght++;
			}
		}

		NameStudent = new char[NameLenght + 1];

		memcpy_s(NameStudent, sizeof(char) * NameLenght + 1, NewName, sizeof(char) *
			NameLenght + 1);
	};
};

//--------------------------------------------------------------------
int ValidateAge()
{
	int Age;
	std::cin >> Age;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> Age;
	};
	return Age;
}

//-------------------------------------------------------------------
int main()
{
	
	FStudent* Student = new FStudent(8);
	Student->SetName("Diego1");
	Student->SetName("Diego2");
	delete Student;


	std::cout << "How many students do you want? ";
	int StudentsAmount;
	std::cin >> StudentsAmount;
	std::cout << "You now have " << StudentsAmount << " students" << std::endl;

	FStudent* Students = new FStudent[StudentsAmount];

	char StudentName[32];
	
	for (int i = 0; i < StudentsAmount; i++)
	{
		std::cout << "insert a name for student #" << i + 1 << ": ";
		std::cin >> StudentName;
		Students[i].SetName(StudentName);

		std::cout << "insert an age for student #" << i + 1 << ": ";
		Students[i].StudentAge = ValidateAge();

		std::cout << std::endl;
	}

	std::cout << "Here are your students:" << std::endl;

	for (int i = 0; i < StudentsAmount; i++)
	{
		std::cout << "student " << i + 1 << std::endl;
		std::cout << "Name " << Students[i].NameStudent << std::endl;
		std::cout << "Age " << Students[i].StudentAge << std::endl;
	}

	std::cout << "Excercise 7) why deleting the student object does not delete the name’s char array?" << std::endl;
	std::cout << "the name’s char array doesn't delete because when the class is deleted, just is deleting the memory of the class but not the variable that is allocated in the memory stack" << std::endl;
}

