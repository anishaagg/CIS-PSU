// Anisha Aggarwal, CS162
// PURPOSE - To keep track of all of the different Activites there are around Oregon
// There will be multiple Activities that make up Adventure 

#include "adventure.h"
#define SIZE 100	// the number of activities that will be stored in the dynamic array

// Prototypes
void get_user_input(char * question, char* & y);

int main()
{
   char season[10];	// array that will hold the user input on what season they want to display
   char to_do = 'Q'; 
	adventure an_adv;

   do
   {
      cout << "Would you like to add an activity (A), display activities by season (B), display all (C), or quit (Q)" << endl;
      cin >> to_do;
      cin.ignore(100, '\n');
      to_do = toupper(to_do);

      // check to make sure that user has entered a valid action
      while ((to_do != 'A') && (to_do != 'B') && (to_do != 'C') && (to_do != 'Q'))
      {
         cout << "Sorry.. Please re-enter!" << endl;
         cin >> to_do;
         cin.ignore(100, '\n');
         to_do = toupper(to_do);
      }
      if (to_do == 'A')		// the user has asked to add an activity to the list
      {
         an_adv.new_activity();
      } else if (to_do == 'B')	// the user has asked to display all of the activities in a particular season 
      {
         cout << "What season's activities would you like to display?" << endl;
         cin.get(season, 10, '\n');
         cin.ignore(100, '\n'); 
         cout << season << endl;
         an_adv.display_all(season);
      } else if (to_do == 'C')	// the user has asked to display all of the activities
      {
	cout << endl << endl;
	an_adv.display_all();
      }
   } while (to_do != 'Q'); // keep asking the user what they would like to do until they say quit

   return 0;
}

// Constructor for Activity class
activity::activity()
{
   //cout << "Activity constructor is called!" << endl;
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
   //cout << "Pointer Season: " << an_activity.p_season << endl;   

   // Read in the type of activity
   get_user_input((char *) "What is the type of activity?", an_activity.p_type_act);
   //cout << "Pointer Activity Type: " << an_activity.p_type_act << endl;

   // Read in where the activity is done
   get_user_input((char *) "Where can this activity be done?", an_activity.p_location);
   //cout << "Pointer Location: " << an_activity.p_location << endl;

   // Read in the description
   get_user_input((char *) "Please give a description of your experience of this activity", an_activity.p_description);
   //cout << "Pointer Description: " << an_activity.p_description << endl;

   // Read in date the activity was done
   cout << "What month did you do this activity in?" << endl;
   cin >> an_activity.month;
   cout << "What year did you do this activity in?" << endl;
   cin >> an_activity.year;
   //cout << "Pointer Date: " << an_activity.month << "/" << an_activity.year << endl;

}

// Function that will display all of the activies stored with a specific season
void activity::display(char * season)
{
   //cout << "User is asking to find " << season << " to match " << an_activity.p_season << endl;

   if (strcmp(season, an_activity.p_season) == 0)
   {
      //cout << "THERE WAS A MATCH!" << endl;
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
	//cout << "Adventure constructor is called!" << endl;
	adv_count = 0;
	head = NULL;
}

// Function that will add a new node in the adventure class' list
void adventure::new_activity()
{
	node *current;
	node *temp;
	
	// check if head is null and if it is add a new node
	if (head == NULL) {
		temp = new node;
		temp->act_data.add_info();
		temp->next = NULL;
		head = temp;
		return;
	}

	// set current to head so that we can traverse through the list
	current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	// add a new node at the end of the list
	temp = new node;
	temp->next = NULL;
	current->next = temp;
	temp->act_data.add_info();		
	
	// check where the node is so that later we can check if the node is being deleted
	// increase the adv_count
	//cout << "Allocating: " << temp << endl;
	++adv_count;
}

// Function that will display all of the activities in the list if the season matches
void adventure::display_all(char season[])
{  
	node * current;

	cout << endl << endl;
	cout << "Activities in " << season << ":" << endl;
	// check if head is null
	if (head == NULL) {
		//cout << "NULL HEAD FOUND IN DISPLAY_ALL(Season)" << endl;
		return;
	}
	// set current to head so that we can traverse through the list
	current = head;
	while (current != NULL) {
		//cout << "Displaying season activities" << endl;
		// call the activity display function to see whether the season matches or not
		current->act_data.display(season);
		current = current->next;
	}
}

// Function of adventure class that will display all of the activities in the list
void adventure::display_all()
{
	node * current;
	
	cout << endl << endl;
	cout << "Activities:" << endl;
	cout << "There are " << adv_count << " activites currently stored!" << endl;
	// check if there is a null head
	if (head == NULL) {
		//cout << "NULL HEAD FOUND IN DISPLAY_ALL" << endl;
		return;
	}
	// set current to head so that we can traverse through the list
	current = head;
	while (current != NULL) {
		//cout << "Displaying season activities" << endl;
		// use recursion to display the list
		current->act_data.display();
		current = current->next;
	}

}

// Destructor for Adventure Class
adventure::~adventure()
{
	node * current;
	node * temp;
	
	// check if head is null
	if (head == NULL) {
		return;
	}
	
	// keep deleting the nodes in the list until head->next is null
	while (head->next != NULL) {
		current = head;
		// go to the second to the end of the list and delete the last node
		while (current->next->next != NULL) {
			current = current->next;
		}
		// set temp to the last node and delete the node
		temp = current->next;
		delete temp;
		//cout << "Deallocating: " << temp << endl;
		// make sure current->next is no longer pointing to memory that isn't ours
		current->next = NULL;
	}

	// only one node left so delete that and set head to null
	delete head;
	//cout << "Deallocating: " << head << endl;
	head = NULL;

	// set adventure count to 0
	adv_count = 0;
	
}







