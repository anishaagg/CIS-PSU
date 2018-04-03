//Anisha Aggarwal, CS162
//To compute wage for each employee

//Be able to gather the employee's initials and make them capitalized.
//Then input their hourly wage and how many hours they have worked
//in order to calculate how much they have earned.
//If there is an increase in cost of living then change the amount of 
//money they earn.
//Be able to calculate the earnings for other employees as well.

#include <iostream>
using namespace std;

int main()
{
char more_employee; //are there any more employees after first person?
   do
   {
	char f_initial;	//first initial
	char m_initial;	//middle initial
	char l_initial;	//last initial
	float hourly_wage; //the hourly wage for employee
	int hours_worked; //number of hours worked
	char col_applied;  //to determine if cost of living increase is to be applied
	float col_increase;   // what the cost of living increase is

	cout << "What is your first initial?" <<endl;
	cin >> f_initial;
	cout << "What is your middle initial?" <<endl;
	cin >> m_initial;
	cout << "What is your last initial?" <<endl;
	cin >> l_initial;
	f_initial = toupper(f_initial);
	m_initial = toupper(m_initial);
	l_initial = toupper(l_initial);
	cout << f_initial;
	cout << m_initial;
	cout << l_initial << endl;

	do
	{
	cout << "What is the hourly wage?" <<endl;
	cin >> hourly_wage;
	cout << "How many hours has the employee worked?" <<endl;
	cin >> hours_worked;
	} while (hourly_wage <= 0 || hours_worked <= 0);
	cout << "The hourly wage is $";
	cout <<  hourly_wage <<endl;
	cout << "The employee has worked is ";
	cout << hours_worked;
	cout << " hours" <<endl;

	cout << "Is there a cost of living increase? (Y or N)" <<endl;
	cin >> col_applied;
	if (col_applied == 'Y' || col_applied == 'y')
	{
	cout << "What is the increase in cost of living?" <<endl;
        cin >> col_increase;
	cout << "You have earned $";
	cout <<  hourly_wage * hours_worked * col_increase <<endl;
	} else
	{
	cout << "You have earned $";
	cout <<  hourly_wage * hours_worked <<endl;
	}
    cout << "Are there more employees?(Y or N)" <<endl;
    cin >> more_employee;
   } while (more_employee == 'Y' || more_employee == 'y');



     return 0;
}
