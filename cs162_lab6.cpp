 //Put your header comments here with your name, class
//and purpose of the program

#include "cs162_course.h"





int main()
{

    //Step #4 - Create an object of the class here:
    course a_course;



    //Steps #5-10 - Call the member functions here:
    char a_first_name[21];
    char a_last_name[21];

    a_course.read_name();
    a_course.read_course();
    a_course.display();

    cout << "Please re-enter your first name: ";
    cin.get(a_first_name, 21, '\n');
    cin.ignore(100, '\n');
    cout << "Please re-enter your last name: ";
    cin.get(a_last_name, 21, '\n');
    cin.ignore(100, '\n');

    a_course.is_match(a_first_name, a_last_name);

    return 0;
}
