// Anisha Aggarwal, CS162, Lab5
// The purpose is to read in a student's name and courses they want to take
// using structures and external files

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Place your structure definition here (globally):
struct student{ char first[21];
                char middle;
                char last[31];
                int crn;
                char course_des[6];
                int section; };

//Place any prototypes that use the structure here:
void readname(char first[], char middle, char last[]);
void read_course_info(student & a_student);

int main()
{
     //Create a variable of the struct here:
	student a_student;

     //Call the functions here:
	readname(a_student.first, a_student.middle, a_student.last);
	read_course_info(a_student);


     return 0;
}

//Implement the body of the functions here:

// Function to read in the name of the student
// first name, middle initial, and last name
void readname(char first[], char middle, char last[])
{
	cout << "Enter in your first name: " << endl;
	cin.get (first, 20, '\n');
	cin.ignore(100, '\n');
	first[0] = toupper(first[0]);
	cout << "Enter in your middle initial: " << endl;
	cin >> middle;
	cin.ignore(100, '\n');
	middle = toupper(middle);
	cout << "Enter in your last name: " << endl;
	cin.get (last, 30, '\n');
	cin.ignore(100, '\n');
	last[0] = toupper(last[0]);
	cout << first << " " << middle << " " << last << endl;
}

// Function to read in the course information the student would like to enroll in
void read_course_info(student & a_student)
{
	cout << "What is the CRN of the course you would like to enroll in?" << endl;
	cin >> a_student.crn;
	cin.ignore(100, '\n');
	cout << "What is the course designator?" <<endl;
	cin.get (a_student.course_des, 6, '\n');
	cin.ignore(100, '\n');
	cout << "What is the section number?" << endl;
	cin >> a_student.section;
	cin.ignore(100, '\n');
	cout << "CRN: " << a_student.crn << endl;
	cout << "Course Designator: " << a_student.course_des << endl;
	cout << "Section: " << a_student.section << endl;
}
