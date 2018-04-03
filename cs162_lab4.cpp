//Anisha Aggarwal, CS162
//Purpose is to read in the student's name
//and the classes they want to register for
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX = 20;
const int COURSE_MAX = 10;

// ***************************************** 
//Place your prototypes here:
void read_name(char first[], char last[]);
void read_course_info(int & crn, char cour_des[], int & section);
bool again();
void capitalize();

int main()
{

	//Make sure to call the function(s) that you write from main!
	char first[MAX];		//variable that will hold student's first name
	char last[MAX];			//variable that will hold student's last name
	int crn;			//variable that will hold the CRN of the course
	char cour_des[COURSE_MAX];	//variable that will hold the course designator
	int section;			//varibale that will hold the section of the course
	char more_classes;		//variable to determine whether the student want to enter in more classes

	read_name(first, last);
	do
	{
	   read_course_info(crn, cour_des, section);
	} while (again());

     return 0;
}

//Now implement the functions here:

//Function that will read in the first and last name of the student
void read_name(char first[], char last[])
{
	//Get the student's first name and last name
	cout << "What is your first name?" <<endl;
	cin.get(first, MAX, '\n');
	cin.ignore(100,'\n');

	cout << "What is your last name?" <<endl;
	cin.get(last, MAX, '\n');
	cin.ignore(100, '\n');

	cout << first << " " << last << endl;

}

//Function tha will read in the students desired course information
void read_course_info(int & crn, char cour_des[], int & section)
{
	//Get the students desired class schedule informaiton
	cout << "What is the CRN of the course you would like to take?" <<endl;
	cin >> crn;
	cin.ignore(100, '\n');

	cout << "What is the course designator?" <<endl;
	cin.get(cour_des, COURSE_MAX, '\n');
	cin.ignore(100, '\n');

	cout << "What is the section number?" <<endl;
	cin >> section;
	cin.ignore(100, '\n');

	cout << "CRN = " << crn << endl;
	cout << "Course Designator = " << cour_des << endl;
	cout << "Section = " << section << endl;
}

//Function that wil allow the one student to enter in multiple courses
bool again()
{
	char more_classes;	//variable to hold whethere they want to enter in more classes or not

	//Find out whether the student wants to enter in more classes or quit
	cout << "Would you like to enroll in more classes?" <<endl;
	cin >> more_classes;
	cin.ignore(100, '\n');
	more_classes = toupper(more_classes);
	if (more_classes != 'Y' && more_classes != 'N')
	{
	   cout << "PLease re-enter..." <<endl;
	   cin >> more_classes;
	   cin.ignore(100, '\n');
	}
	if (more_classes == 'Y')
	{
	   return true;
	} else return false;
}

//Function to capitalize words
void capitalize()
{

}
