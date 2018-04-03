//Anisha Aggarwal, CS162
//To determine the name of the person and what major they are

//In this program I will be retrieving the persons' full name
//I will then make sure to capitalize all parts of their name
//I will ask them what their major is and if it is CS then I will
//display a message that  says they are a CS major
//Making sure that there is no major exceeding the character limit in the array
//If there are extra characters I will remove them

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//Here is an example of a constant; constants should
//be global so that they are accessible by all functions
//and there are no "side effects" unlike with global
//variables (which should be avoided!)
const int SIZE = 21;		//constant that will be used to determine the max # of letters can be held in major
const int MAX_CHAR = 30;	//constant that will be used to determine the max # of letters that can be held in full_name

int main()
{
	//Arrays that will be available to use
	char full_name[MAX_CHAR];	//array that will read in a persons whole name
	char major[SIZE];		//array that will read in the ir major

	//Prompt for users full name and echo it
	cout << "Type in your full name" <<endl;
	cin.get(full_name, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << full_name <<endl;

	//Capitalize the first letter of the first word
	full_name[0] = toupper(full_name[0]);
	cout << full_name <<endl;

	//Capitalize the beginning of each word in the name
	//A new word can be defined by a blank space in between each word
	int name;	//variable that will hold the string length of the array full_name
	name = strlen(full_name);
	for (int i=0; i<name; ++i)
	{
	   if (full_name[i] == ' ')
	   {
		full_name[(i + 1)] = toupper(full_name[(i + 1)]);
	   }
	}
	cout << full_name <<endl;

	//Prompt the user for their major and echo it
	cout << "What is your major?" <<endl;
	cin.get(major, SIZE, '\n');
	cin.ignore(100, '\n');
	cout << major <<endl;

	//Compare to see if the major is Computer Science and display a message
	if (strcmp(major, "computer science") == 0)
	{
	   cout << "Yay! You are a Computer Science major!" <<endl;
	}

	//If the user enters in too many characters
	//display an error message and have them re-enter the data
	do
	{
	   
	} while (

     return 0;
}
