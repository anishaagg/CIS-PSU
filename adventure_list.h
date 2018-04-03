// Anisha Aggarwal, CS162
// Adventure Class - will hold an array of Activities

#include "activity.h"

// Structure that will contain an activity
struct node {
	activity act_data;
	node * next;
};

// Class that will hold a list of Activities
class adventure
{
   public:
      adventure ();
      ~adventure();				//A destructor used to deallocate dynamic memory
      void new_activity();	           	//Read in a new activity’s information to the list
      void display_all (char season[]);
      void display_all();

   private:
      /*Put a dynamically allocated array of activities, an integer count of the
      number of activities, and an integer for the size of the array created */
      int adv_count;
      node *head;
};


