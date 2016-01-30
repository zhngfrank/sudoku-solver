#include "sudoku.h"

#include <std::vector>
#include <std::iostream>
#include <std::iomanip>

int menu()
{
	int a = 10; //a lot of formatting uses 10 spaces 
				//so this is just an easy way to do it
	const std::string spaces = std::string(a,' ');
	int choice = 0; //init to 0
	int n = 1; //easy way to make a dynamic list of menu options
	
	const std::string welcome_message = "SUDOKU SOLVER\nsolves sudoku " 
		"puzzles using brute force algorithm\n";
	
	
	std::cout << welcome_message;
	
	//list menu options
	std::cout << std::setw(a) << n++ << "." << spaces << "Watch the program run!"
			<< std::endl << spaces << spaces
			<< " *Note: runs slowly since it outputs the process*" << std::endl;
	std::cout << std::setw(a) << n++ << "." << spaces 
			<< "Input your own puzzle!" << std::endl;
	std::cout << std::setw(a) << n++ << "." << spaces 
			<< "Run the solver!"<< std::endl;
	std::cout << std::setw(a) << n++ << "." << "Exit" << std::endl;
	
	//choice option
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	
	if (choice <= n && choice >= 1 )
	{
		return choice;
	}
	else
	{
		std::cout << "Sorry, your choice " << choice << " was no valid\n";
		menu();
	}
}//end int menu

void menuChoice( int choice );
{
	if (choice == 1)
	{
		//call appropriate function for watch the program run 
		//(e.g. rogers original program)
	}
	if (choice == 2)
	{	
		//call appropriate function to enter in a sudoku puzzle
	}
	if (choice == 3)
	{
		//RUN THE PROGRAM OMGGGG YASS
	
	}
	if ( choice == 4 )
	{
		std::cout << "SUDOKU!!!!" << std::endl;
	}
} //end menuChoice

void inputOriginal();
{
	 
}



