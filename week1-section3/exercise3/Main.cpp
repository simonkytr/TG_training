/*Exercise 2 - More Input Validation
Rewrite the true or false quiz you did in the previous section. This time, instead of asking for 1 or 2 as inputs, ask them to answer T or F. If they enter invalid input, give them a couple of tries before you automatically fail them.
*/
#include <iostream>


int main()
{
	std::cout << "Welcome to this quiz\How many doy you know about general culture?"<<std::endl;
	std::cout << "Remember to use F to false or T to true\nLet's play!!\n"<<std::endl;


	//creating asks and answers
	std::string question[5] = {"The paramecium is a flower? ","does the platypus lay eggs? ", "Is the whale a mammal? ","Is the bat a bird? ", "Is the tomatoe a fruit? "};
	std::string answer[5] = {"F","T","T","F","T"};
	
	//creating inputs
	std::string EntryAnswer;
	int score=0;

	int IncorrectAnswer=0;//to validate the wrong typing

	for ( int i = 0; i < 5; i++)
	{
		std::cout << question[i];//reading the question
		std::cin >> EntryAnswer;//input the answer

		if ((EntryAnswer == "T") || (EntryAnswer == "F"))
		{
		
			if (EntryAnswer == answer[i]) {
				std::cout << "That's Correct!" << std::endl;
				score++;
			}
			else {
				std::cout << "That's wrong!" << std::endl;
			}

		}
		else {
			//when the player type wrong
			while (!(EntryAnswer == "T") || !(EntryAnswer == "F"))
			{
				std::cout << "do you remember how to type?" << std::endl;

				//repeat the question until the player type any valid option 
				std::cout << question[i];//reading the question
				std::cin >> EntryAnswer;//input the answer

				if ((EntryAnswer == "T") || (EntryAnswer == "F"))
				{

					if (EntryAnswer == answer[i]) {
						std::cout << "That's Correct!" << std::endl;
						score++;
						break;
					}
					else {
						std::cout << "That's wrong!" << std::endl;
						break;
					}


				}
				if (IncorrectAnswer == 2)//skip the question
				{
					std::cout << "is this a Hard question for you?, don't worry go to the next question" << std::endl;
						break;
				}

				IncorrectAnswer++;//rise the answrong
				
				continue;
			}

		}

		
	}
	
	std::cout<<"You answered " << score << "/5 Yo final grade is: " << 5/score;
	
}