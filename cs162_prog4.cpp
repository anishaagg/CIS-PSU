// Anisha Aggarwal, CS160
// PURPOSE - To keep track of all of the different Activites there are around Oregon
// There will be multiple Activities that make up Adventure 

#include "adventure.h"
#define SIZE 100	// the number of activities that will be stored in the dynamic array

// Prototypes
void get_user_input(char * question, char* & y);

int main()
{
   adventure an_adv;	// variable that will access the Adventure class
   char season[10];	// array that will hold the user input on what season they want to display
   char to_do = 'Q'; 

   do
   {
      cout << "Would you like to add an activity (A), display activities by season (B), display all (C), or quit (Q)" << endl;
      cin >> to_do;
      cin.ignore(100, '\n');
      to_do = toupper(to_do);
      while ((to_do != 'A') && (to_do != 'B') && (to_do != 'C') && (to_do != 'Q'))
      {
         cout << "Sorry.. Please re-enter!" << endl;
         cin >> to_do;
         cin.ignore(100, '\n');
         to_do = toupper(to_do);
      }
      if (to_do == 'A')
      {
         an_adv.new_activity();
      } else if (to_do == 'B')
      {
         cout << "What season's activities would you like to display?" << endl;
         cin.get(season, 10, '\n');
         cin.ignore(100, '\n'); 
         an_adv.display_all(season);
      } else if (to_do == 'C') 
      {
         an_adv.display_all();
      }
   } while (to_do != 'Q');

   return 0;
}

// Constructor for Activity class
activity::activity()
{
   //cout << "Constructor is called!" << endl;
   an_activity.p_season = NULL;
   an_activity.p_type_act = NULL;
   an_activity.p_location = NULL;
   an_activity.p_description = NULL;
   an_activity.month = 0;
   an_activity.year = 0; 
   
}

// Destructor for Activity class
activity::~activity()
{
   if (an_activity.p_season) {
      delete an_activity.p_season;
   }
   if (an_activity.p_type_act) {
      delete an_activity.p_type_act;
   }
   if (an_activity.p_location) {
      delete an_activity.p_location;
   }
   if (an_activity.p_description) {
      delete an_activity.p_description;
   }

}

// Function that will copy the temporary arrays into the activity arrays
void get_user_input(char * question, char* & y)
{
   char temp_array[100];
   int len = 0;
   cout << question << endl;
   cin.get(temp_array, 100, '\n');
   cin.ignore(100, '\n');
//   cout << temp_array << endl;
   len = strlen(temp_array) + 1;
   y = new char[len];
   strcpy(y, temp_array);

}

// Function that will read in all of the information on the activity
void activity::add_info()
{
   // Read in the season
   get_user_input((char *) "What season did you do this activity in?", an_activity.p_season);
//   cout << "Pointer Season: " << an_activity.p_season << endl;   

   // Read in the type of activity
   get_user_input((char *) "What is the type of activity?", an_activity.p_type_act);
//   cout << "Pointer Activity Type: " << an_activity.p_type_act << endl;

   // Read in where the activity is done
   get_user_input((char *) "Where can this activity be done?", an_activity.p_location);
//   cout << "Pointer Location: " << an_activity.p_location << endl;

   // Read in the description
   get_user_input((char *) "Please give a description of your experience of this activity", an_activity.p_description);
//   cout << "Pointer Description: " << an_activity.p_description << endl;

   // Read in date the activity was done
   cout << "What month did you do this activity in?" << endl;
   cin >> an_activity.month;
   cout << "What year did you do this activity in?" << endl;
   cin >> an_activity.year;
//   cout << "Pointer Date: " << an_activity.month << "/" << an_activity.year << endl;

}

// Function that will display all of the activies stored with a specific season
void activity::display(char * season)
{
//   cout << "User is asking to find " << season << " to match " << an_activity.p_season << endl;

   if (strcmp(season, an_activity.p_season) == 0)
   {
      cout << "THERE WAS A MATCH!" << endl;
      cout << "Season: " << an_activity.p_season << endl;
      cout << "Type of Activity: " << an_activity.p_type_act << endl;
      cout << "Location: " << an_activity.p_location << endl;
      cout << "Description: " << an_activity.p_description << endl;
      cout << "Date went last: " << an_activity.month << "/" << an_activity.year << endl;
      cout << endl;
   } /*else {
      cout << "THERE WAS NO MATCH!" << endl;
   }*/

}

// Function that will display all of the activities stored
void activity::display()
{
   cout << "Season: " << an_activity.p_season << endl;
   cout << "Type of Activity: " << an_activity.p_type_act << endl;
   cout << "Location: " << an_activity.p_location << endl;
   cout << "Description: " << an_activity.p_description << endl;
   cout << "Date went last: " << an_activity.month << "/" << an_activity.year << endl;
   cout << endl;

}

// Constructor for Adventure Class
adventure::adventure()
{
   adv_count = 0;
   p_activity = new activity[SIZE];

}

// Destructor for Adventure Class
adventure::~adventure()
{
   delete [] p_activity;

}

void adventure::new_activity()
{
   if (adv_count < SIZE)
   {
      p_activity[adv_count].add_info();
      ++adv_count;
   } else {
      cout << "Sorry we currently cannot take more activities." << endl;
   }

}

void adventure::display_all(char season[])
{  
   cout << endl << endl;
   cout << "Activities in " << season << ":" << endl;
   for(int i = 0; i < adv_count; ++i)
   {
      p_activity[i].display(season);
   }

}

void adventure::display_all()
{
//   cout << "User is asking to display all of the activities stored!" << endl;
   cout << endl << endl;
   cout << "ACTIVITES:" << endl;
   for(int i = 0; i < adv_count; ++i)
   {
      p_activity[i].display();
   }

}









