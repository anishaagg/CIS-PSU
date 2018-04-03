// Anisha Aggarwal, CS162, Lab 6
// Purpose is to practice working with classes and continue working with
// the registration information for the student/course

#include "cs162_course.h"

//Implement the body of these functions for Lab #6

//Constructor - initialize all data members to their zero equivalent value
course::course()
{
  	//Place the code for the constructor here
	crn[0] = '\0';
	course_des[0] = '\0';
	section[0] = '\0';
	first_name[0] = '\0';
	last_name[0] = '\0';
}


//Read in the CRN, Course Description and Section
//Store these into the private data members of the class
void course::read_course()
{
        //Implement this function
	cout << "What is the CRN of the course: ";
	cin.get(crn, 10, '\n');
	cin.ignore(100, '\n');
	cout << endl;

	cout << "What is the course designator: ";
	cin.get(course_des, 10, '\n');
	cin.ignore(100, '\n');
	cout << endl;

	cout << "What is the section: ";
	cin.get(section, 10, '\n');
	cin.ignore(100, '\n');
	cout << endl;

}


//Display the name and course information
void course::display()
{

        //Implement this function
	cout << "Student Name: " << first_name << " " << last_name << endl;
	cout << "CRN: " << crn << endl;
	cout << "Course Designator: " << course_des << endl;
	cout << "Section: " << section << endl << endl;
}

//Take the argument and compare it to the student's name
//If it is the same, return a true - otherwise return false
bool course::is_match(char a_first_name[], char a_last_name[])
{
	//Implement this function

	if (strcmp(first_name, a_first_name) != 0)
	{
		cout << "a_first_name doesn't match first_name" << endl;
		return false;
	} else if (strcmp(last_name, a_last_name) != 0)
	{
		cout << "a_last_name doesn't match last_name" << endl;
		return false;
	}
	cout << "a_name matches name!" << endl;
	return true;

}


//Challenge - reset the course information for a student if they
//want to drop, given the CRN. Only drop the course if the CRN
//matches. Return true if the operation was successful and false
//if the CRN doesn't match
bool course::drop(int CRN)
{
      // Challenge

}


