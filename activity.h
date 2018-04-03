// Anisha Aggarwal, CS162
// Activity Class - will hold one activity that the user is storing
// Explore Struct that will hold the activity information

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Structure
struct explore {
   char * p_season;
   char * p_type_act;
   char * p_location;
   char * p_description;
   int month;
   int year;
};

// Class that will hold just one activity
class activity
{
   public:
      activity();
      ~activity();			//A destructor used to deallocate dynamic memory
      void add_info();			//add a description and date to an activity
      void display(char season[]);	//Only displays the information if the season matches
      void display();			//Displays all of the activity’s information
   private:
      /*Put a dynamically allocated arrays here */
      explore an_activity;
};

