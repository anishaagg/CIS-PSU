#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Anisha Aggarwal, Ordering Drinks
// CS 162 - Program 2

// PROGRAM 1 = Create a program that will take a persons drink order
// Determine the type of coffee drink they want with whatever flavors they want
// After they have made each drink order, tell them what the fany name is
// PROGRAM 2 = add on that the user can type in a size and it will output # of oz
// They can also type in the type of coffee they want
// If they miss a letter when typing the program will still work as well as swapping 2 letters

// Define coffee types
#define COFFEE_ESPRESSO		1
#define COFFEE_MACCHIATO	2
#define COFFEE_LATTE		3
#define COFFEE_CAPPUCCINO	4
#define COFFEE_MOCHA		5
#define COFFEE_BREWED_COFFEE	6

// Define flavor types
#define FLAVOR_NONE		1
#define FLAVOR_CHOCOLATE	2
#define FLAVOR_VANILLA		3
#define FLAVOR_HAZELNUT		4
#define FLAVOR_CARAMEL		5

// Define coffee sizes
#define SIZE_SMALL		1
#define SIZE_MEDIUM		2
#define SIZE_LARGE		3

// Define milk type
#define MILK_SKIM		1
#define MILK_2_PERCENT		2
#define MILK_HALF_AND_HALF	3
#define MILK_SOY		4

// Define the amount of milk
#define MILK_AMOUNT_NONE	1
#define MILK_AMOUNT_SOME	2
#define MILK_AMOUNT_MOSTLY	3

// Define whether they want foam
#define FOAM_NONE		1
#define FOAM_SOME		2

// Prototypes of functions
// PROGRAM 1 Functions
int get_num_drinks();
int get_user_input_size();
int get_user_input_milk_amount();
int get_user_input_milk_type();
int get_user_input_foam();
int get_user_input_coffee_flavor();
int determine_coffee_type(int coffee_flavor, int milk_amount, int foam_amount);
void determine_fancy_name(int size, int milk_type, int coffee_flavor, int coffee_type);
char determine_more_customers();
int size_to_oz();
// PROGRAM 2 Added Functions
char get_know_fancy_drink();
void get_typed_size(char typed_size[]);
void get_typed_desired_milk(char typed_desired_milk[]);
void get_typed_flavor(char typed_flavor[]);
void get_typed_desired_coffee(char typed_desired_coffee[]);
char exact_match();
char missing_letter_match();
char swapped_letter_match();
bool exact_match(char * typed_input, const char * string_compare);
bool missing_letter_match(char * typed_input, const char * string_compare);
bool swapped_letter_match(char * typed_input, const char * string_compare);
char find_match_size(char * typed_size, char * matched_coffee_type);
char find_match_milk_type(char * typed_desired_milk, char * matched_milk_type_string);
char find_flavor_match(char * typed_desired_flavor, char * matched_flavor_string);
char find_coffee_type_match(char * typed_desired_coffee, char * matched_coffee_type);
void valid_drink_typed(char * matched_size_string, char * matched_flavor_string, char * matched_coffee_type);

int main()
{
   // Variables being used
   int num_drinks;					// the number of drinks the customer would like = number of loops
   int coffee_type;					// the type of coffee the customer wants
   int size;						// size of the drink the customer wants
   int coffee_flavor;					// the flavor of coffee the customer would like
   int milk_type;					// the type of milk the customer would like in their coffee
   int milk_amount;					// the amount of milk the customer wants
   int foam_amount;					// the amount of foam the customer wants
   char more_customers = 'N';	 			// variable to hold yes or no for whether there are/aren't more customers
   char know_fancy_drink;       			// varibale to hold whether the user knows what they want or not
   char typed_size[7];  				// array to determine which size they want
   char typed_desired_milk[12];				// array to determine which type of milk they want
   char typed_flavor[10];				// array to determine which flavor they want
   char typed_desired_coffee[11];			// array to determine which coffee type they want
   char matched_size_string[8];				// to point to a previous array for drink size
   char matched_milk_type_string[13];			// to point to a previous array for milk type
   char matched_flavor_string[11];			// to point to a previous array for flavor
   char matched_coffee_type[12];			// to point to a previous array for coffee type

   know_fancy_drink = get_know_fancy_drink();
   if (know_fancy_drink == 'A')
   {
      do
      {
         num_drinks = get_num_drinks();
         do
         {
            get_typed_size(typed_size);
            get_typed_desired_milk(typed_desired_milk);
            get_typed_flavor(typed_flavor);
            get_typed_desired_coffee(typed_desired_coffee);

            find_match_size(typed_size, matched_size_string);
            find_match_milk_type(typed_desired_milk, matched_milk_type_string);
            find_flavor_match(typed_flavor, matched_flavor_string);
            find_coffee_type_match(typed_desired_coffee, matched_coffee_type);
            valid_drink_typed(matched_size_string, matched_flavor_string, matched_coffee_type);

            num_drinks = num_drinks - 1;
         } while (num_drinks > 0);
         more_customers = determine_more_customers();
      } while (more_customers = 'Y');
   } else
   {
      do
      {
         num_drinks = get_num_drinks();
	 do
	 {
	    size = get_user_input_size();
	    milk_amount = get_user_input_milk_amount();
            if (milk_amount != MILK_AMOUNT_NONE)
	    {
	       milk_type = get_user_input_milk_type();
	    }
	    foam_amount = get_user_input_foam();
            coffee_flavor = get_user_input_coffee_flavor();
            coffee_type = determine_coffee_type(coffee_flavor, milk_amount, foam_amount);
            determine_fancy_name(size, milk_type, coffee_flavor, coffee_type);
            num_drinks = num_drinks - 1;
	 } while (num_drinks > 0);
   	 more_customers = determine_more_customers();
      } while(more_customers == 'Y');
   }

   return 0;
}

// Function to determine the number of drinks the customer wants
// It will return the number of drinks
int get_num_drinks()
{
   int num_drinks;   // the number of drinks the customer would like = number of loops

   cout << "How many drinks would you like to order today?" << endl;
   cin >> num_drinks;
   cin.ignore(100, '\n');
   while (num_drinks < 1)
   {
      cout<< "Please re-enter..." << endl;
      cin >> num_drinks;
      cin.ignore(100, '\n');
   }
   return num_drinks;
}

// Function to get users input on the size for the coffee order
int get_user_input_size()
{
   int size;                    // size of the drink the customer wants
   cout << "What size drink would you like? (Small = 1, Medium = 2, Large = 3)" << endl;
   cin >> size;
   cin.ignore(100, '\n');
   while ((size < 1) || (size > 3))
   {
      cout << "What size drink would you like? (Small = 1, Medium = 2, Large = 3)" << endl;
      cin >> size;
      cin.ignore(100, '\n');
   }
   return size;
}

// Function to get users input on the amount of milk for the coffee order
int get_user_input_milk_amount()
{
   int milk_amount;             // the amount of milk the customer wants

   cout << "How much milk would you like? (None = 1, Some = 2, or Mostly = 3)" << endl;
   cin >> milk_amount;
   cin.ignore(100, '\n');
   while ((milk_amount < 1) || (milk_amount > 3))
   {
      cout << "How much milk would you like? (None = 1, Some = 2, or Mostly = 3)" << endl;
      cin >> milk_amount;
      cin.ignore(100, '\n');
   }
   return milk_amount;
}

// Function to get users input on the type of milk for the coffee order
int get_user_input_milk_type()
{
   int milk_type;               // the type of milk the customer would like in their coffee

   {
      cout << "What type of milk would you like in your coffee? (Skim = 1, 2% = 2, Half & Half = 3, Soy = 4)" <<endl;
      cin >> milk_type;
      cin.ignore(100, '\n');
   }

   return milk_type;
}

// Function to get users input on the foam that will be added in for the coffee order
int get_user_input_foam()
{
   int foam_amount;             // the amount of foam the customer wants

   cout << "How much foam would you like? (None = 1 or Some = 2)" << endl;
   cin >> foam_amount;
   cin.ignore(100, '\n');
   while ((foam_amount != 1) && (foam_amount != 2))
   {
      cout << "How much foam would you like? (None = 1 or Some = 2)" << endl;
      cin >> foam_amount;
      cin.ignore(100, '\n');
   }
   return foam_amount;
}

// Function to get users input on the flavor that will be added in for the coffee order
int get_user_input_coffee_flavor()
{
   int coffee_flavor;           // the flavor of coffee the customer would like

   cout << "What flavor of coffee would you like? (None = 1, Chocolate = 2, Vanilla = 3, Hazelnut = 4, Caramel = 5)" <<endl;
   cin >> coffee_flavor;
   cin.ignore(100, '\n');
   while ((coffee_flavor < 1) || (coffee_flavor > 5))
   {
      cout << "What flavor of coffee would you like? (None = 1, Chocolate = 2, Vanilla = 3, Hazelnut = 4, Caramel = 5)" <<endl;
      cin >> coffee_flavor;
      cin.ignore(100, '\n');
   }
   return coffee_flavor;
}


// Function to determine the type of coffee the customer would like
// This is based on milk_type, foam_wanted, flavor_type
// It will return coffee_type
int determine_coffee_type(int coffee_flavor, int milk_amount, int foam_amount)
{
   int coffee_type;             // the type of coffee the customer wants

   if ((milk_amount == MILK_AMOUNT_NONE) && (foam_amount == FOAM_NONE))
   {
      coffee_type =  COFFEE_ESPRESSO;
   } else if ((milk_amount == MILK_AMOUNT_NONE) && (foam_amount == FOAM_SOME))
   {
      coffee_type =  COFFEE_MACCHIATO;
   } else if ((milk_amount == MILK_AMOUNT_SOME) && (foam_amount == FOAM_NONE))
   {
      coffee_type =  COFFEE_BREWED_COFFEE;
   } else if ((milk_amount == MILK_AMOUNT_SOME) && (foam_amount == FOAM_SOME))
   {
      if (coffee_flavor == FLAVOR_CHOCOLATE)
      {
         coffee_type = COFFEE_MOCHA;
      } else
      {
         coffee_type = COFFEE_LATTE;
      }
   } else if (milk_amount == MILK_AMOUNT_MOSTLY)
   {
      coffee_type =  COFFEE_CAPPUCCINO;
   }

   return coffee_type;
}

// Print the fancy name of the drink
// Pass in all the variables from before
void determine_fancy_name(int size, int milk_type, int coffee_flavor, int coffee_type)
{
   // Print the size field of the fancy drink name
   switch (size)
   {
      case SIZE_SMALL:
         cout << "Tall ";
         break;
      case SIZE_MEDIUM:
         cout << "Grande ";
         break;
      case SIZE_LARGE:
         cout << "Venti ";
         break;
      default:
         cout << "ERROR SIZE ERROR";
         break;
   }

   // Print the milk type field of the fancy drink name
   switch (milk_type)
   {
      case MILK_SKIM:
         cout << "Skinny ";
	 break;
      case MILK_2_PERCENT:
         cout << "2% ";
         break;
      case MILK_HALF_AND_HALF:
         cout << "Half & Half ";
         break;
      case MILK_SOY:
         cout << "Soy ";
         break;
   }

   // Print the coffee flavor field of the fancy drink name
   switch (coffee_flavor)
   {
      case FLAVOR_NONE:
         // Print nothing
         break;
      case FLAVOR_CHOCOLATE:
         if (coffee_type != COFFEE_MOCHA)
         {
            cout << "Chocolate ";
            break;
         } else
         {
            break;
         }
      case FLAVOR_VANILLA:
         cout << "Vanilla ";
         break;
      case FLAVOR_HAZELNUT:
         cout << "Hazelnut ";
         break;
      case FLAVOR_CARAMEL:
         cout << "Caramel ";
         break;
      default:
         cout << "ERROR FLAVOR ERROR";
         break;
   }

   // Print the coffee type field of the fancy drink name
   switch (coffee_type)
   {
      case COFFEE_ESPRESSO:
         cout << "Espresso" << endl;
         break;
      case COFFEE_MACCHIATO:
         cout << "Macchiato" << endl;
         break;
      case COFFEE_LATTE:
         cout << "Latte" << endl;
         break;
      case COFFEE_CAPPUCCINO:
         cout << "Cappuccino" << endl;
         break;
      case COFFEE_MOCHA:
         cout << "Mocha" << endl;
         break;
      case COFFEE_BREWED_COFFEE:
         cout << "Brewed Coffee" << endl;
         break;
      default:
         cout << "ERROR COFFEE TYPE ERROR" << endl;
         break;
   }
}

// Ask if there are more customers? (yes or no)
char determine_more_customers()
{
   char more_customers = 'N';   // variable to hold yes or no for whether there are/aren't more customers

   cout << "Are there any more customers? (Y or N)" <<endl;
   cin >> more_customers;
   cin.ignore(100, '\n');
   more_customers = toupper(more_customers);
   while ((more_customers != 'Y') && (more_customers != 'N'))
   {
      cout << "Sorry I did not understand that. Please try again" <<endl;
      cout << "Are there any more customers? (Y or N)" <<endl;
      cin >> more_customers;
      cin.ignore(100, '\n');
      more_customers = toupper(more_customers);
   }
   // cout << more_customers;    //to check if this was capitalizing properly
   return more_customers;
}


// Function to determine whether the customer wants to type in order or have it determined for them
char get_know_fancy_drink()
{
   // Ask the user if they know what they want to allow them to type in their desired order
   // or if they don't know what the fancy names are then to allow the program to determine it for them

   char know_fancy_drink;	// varibale to hold whether the user knows what they want or not

   cout << "Hello! Do you know (A) what type of coffee you would like or (B) would you liked to be guided through [type either A or B]" << endl;
   cin >> know_fancy_drink;
   cin.ignore(100, '\n');
   know_fancy_drink = toupper(know_fancy_drink);
   while (know_fancy_drink != 'A' && know_fancy_drink != 'B')
   {
      cout << "I'm sorry, please re-enter" << endl;
      cin >> know_fancy_drink;
      cin.ignore(100, '\n');
      know_fancy_drink = toupper(know_fancy_drink);
   }

   return know_fancy_drink;
}

// Function to determine typed size
void get_typed_size(char typed_size[])
{
   cout << "What size would you like? (Tall, Grande, or Venti)" << endl;
   cin.get(typed_size, 7, '\n');
   cin.ignore(100, '\n');
   //cout << "DEBUG Typed Size " << typed_size << endl;

}

// Function to determine typed milk type
void get_typed_desired_milk(char typed_desired_milk[])
{
   cout << "What type of milk would you like? (None, Skim, 2%, Half & Half, or Soy)" << endl;
   cin.get(typed_desired_milk, 12, '\n');
   cin.ignore(100, '\n');
   //cout << "DEBUG Typed Desired Milk " << typed_desired_milk << endl;

}

// Function to determine typed flavor
void get_typed_flavor(char typed_flavor[])
{
   cout << "What flavor would you like added? (None, Chocolate, Vanilla, Hazelnut, or Caramel)" << endl;
   cin.get(typed_flavor, 10, '\n');
   cin.ignore(100, '\n');
   //cout << "DEBUG Typed Flavor " << typed_flavor << endl;

}

// Function to determine typed coffee type
void get_typed_desired_coffee(char typed_desired_coffee[])
{
   cout << "What type of coffee would you like? (Espresso, Macchiato, Latte, Cappuccino, or Mocha)" << endl;
   cin.get(typed_desired_coffee, 11, '\n');
   cin.ignore(100, '\n');
   //cout << "DEBUG Typed Coffee Type " << typed_desired_coffee << endl;

}

// Function to check for an exact match for any part of the fancy name
// if there is an exact match it will return true, else it will return false
bool exact_match(char * typed_input, const char * string_compare)
{
   int len_typed_input;       // variable that will hold the string length of the array typed_input

   if (strlen(typed_input) ==  strlen(string_compare))
   {
      len_typed_input = strlen(typed_input);
      for (int i=0; i < len_typed_input; ++i)
      {
         typed_input[i] = tolower(typed_input[i]);
      }
      if (strcmp(typed_input, string_compare) == 0)
      {
         //cout << typed_input <<endl;
         //cout << "DEBUG TYPED INPUT EXACT MATCH" << endl;
         return true;
      }
   }
   //cout << "DEBUG TYPED INPUT NO EXACT MATCH" << endl;
   return false;
}

// Function to check for a missing letter for any part of the fancy name
bool missing_letter_match(char * typed_input, const char * string_compare)
{
   int len_typed_input;			// variable that will hold the string length of the array typed_input

   // check if there is one letter missing by looking at the string length -1
   if ((strlen(typed_input) + 1) == strlen(string_compare))
   {
      len_typed_input = strlen(typed_input);
      // for loop to go through each letter to find a match
      for (int i=0; i < len_typed_input; ++i)
      {
         typed_input[i] = tolower(typed_input[i]);
         // if the letter does not match the string compare then check if the next letter matches
         if (typed_input[i] != string_compare[i])
         {
            // if the next letter matches then continue (else return false)
            if (typed_input[i] == string_compare[i + 1])
            {
               // for loop to test the rest of the letters. we don't want there to be another missing letter
               // set j=i so that the letter matching will start from where it left off
               for(int j=i; j < len_typed_input; ++j)
               {
                  typed_input[j] = tolower(typed_input[j]);
                  // if the letter doesn't match now, return false
                  if (typed_input[j] != string_compare[j + 1])
                  {
                     return false;
                  } else
                     // set i=j so that once this for loop is done it wont go back to the big for loop and check for more missing letters
                     i = j;
                     //cout << typed_input << endl;
               }
            } else return false;
         } //else
            //cout << typed_input << endl;
      }
      //cout << "WE MATCHED EXACTLY IN MISSING LETTER LOOP" << string_compare << endl;
      return true;
   }
   return false;
}

// Function to check for two swapped letters for any part of the fancy name
bool swapped_letter_match(char * typed_input, const char * string_compare)
{
   int len_typed_input;			// variable that will hold the string length of the array typed_input

   if (strlen(typed_input) == strlen(string_compare))		// swapped letters will stil have the same number of letters as the string_compare
   {
      len_typed_input = strlen(typed_input);
      for (int i=0; i < len_typed_input; ++i)			// for loop to go through each letter to find a match
      {
         typed_input[i] = tolower(typed_input[i]);		// lowercase each letter to make an equivalent comparison
         if (typed_input[i] != string_compare[i])
         {
            // check to see if the letter matches the next letter in string_compare (if not return false)
            if (typed_input[i] == string_compare[i + 1])
            {
               // check to make sure letters were swapped (if not return false)
               typed_input[i + 1] = tolower(typed_input[i + 1]);
               if (typed_input[i + 1] == string_compare[i])
               {
                  // check if there is an exact match for the rest of the letters (if not return false)
                  for (int j = i + 2; j < len_typed_input; ++j)
                  {
                     typed_input[j] = tolower(typed_input[j]);
                     if (typed_input[j] != string_compare[j])
                     {
                        return false;
                     } else
                     {
                        i = j;
                     }
                  }
               } else return false;
            } else return false;
         }
         // cout << "WE FOUND A SWAPPED LETTER MATCH FOR THE LOOP " << string_compare << endl;
         return true;
      }
   } else
      return false;
}

// Function to find a match to the size drink they want
char find_match_size(char * typed_size, char * matched_size_string)
{
   const char size_tall_string[] = "tall";		// array to compare to matched array
   const char size_grande_string[] = "grande";		// array to compare to matched array
   const char size_venti_string[] = "venti";		// array to compare to matched array

   if (exact_match(typed_size, size_tall_string) || missing_letter_match(typed_size, size_tall_string) || swapped_letter_match(typed_size, size_tall_string))
   {
      strcpy(matched_size_string, "Tall ");
      cout << endl << endl << "A tall is 8 oz" << endl;
   } else if (exact_match(typed_size, size_grande_string) || missing_letter_match(typed_size, size_grande_string)|| swapped_letter_match(typed_size, size_grande_string))
   {
      strcpy(matched_size_string, "Grande ");
      cout << endl << endl << "A grande size is 12 oz" << endl;
   } else if(exact_match(typed_size, size_venti_string) || missing_letter_match(typed_size, size_venti_string)|| swapped_letter_match(typed_size, size_venti_string))
   {
      strcpy(matched_size_string, "Venti ");
      cout << endl << endl << "A venti size is 16 oz" << endl;
   } else
      cout << "WE DIDN'T FIND A MATCH FOR THE SIZE!" << endl;
   cout << matched_size_string;
}

// Function to find a match to the type of milk they want
char find_match_milk_type(char * typed_desired_milk, char * matched_milk_type_string)
{
   const char milk_type_none[] = "none";		// array to compare to matched array
   const char milk_type_skim[] = "skim";		// array to compare to matched array
   const char milk_type_2_percent[] = "2%";		// array to compare to matched array
   const char milk_type_half[] = "half & half";		// array to compare to matched array
   const char milk_type_soy[] = "soy";			// array to compare to matched array

   if (exact_match(typed_desired_milk, milk_type_none) || missing_letter_match(typed_desired_milk, milk_type_none) || swapped_letter_match(typed_desired_milk, milk_type_none))
   {
      strcpy(matched_milk_type_string, "");
   } else if (exact_match(typed_desired_milk, milk_type_skim) || missing_letter_match(typed_desired_milk, milk_type_skim) || swapped_letter_match(typed_desired_milk, milk_type_skim))
   {
      strcpy(matched_milk_type_string, "Skinny ");
   } else if (exact_match(typed_desired_milk, milk_type_2_percent) || missing_letter_match(typed_desired_milk, milk_type_2_percent) || swapped_letter_match(typed_desired_milk, milk_type_2_percent))
   {
      strcpy(matched_milk_type_string, "2% ");
   } else if (exact_match(typed_desired_milk, milk_type_half) || missing_letter_match(typed_desired_milk, milk_type_half) || swapped_letter_match(typed_desired_milk, milk_type_half))
   {
      strcpy(matched_milk_type_string, "Half & Half ");
   } else if (exact_match(typed_desired_milk, milk_type_soy) || missing_letter_match(typed_desired_milk, milk_type_soy) || swapped_letter_match(typed_desired_milk, milk_type_soy))
   {
      strcpy(matched_milk_type_string, "Soy ");
   } else
      cout << "WE DIDN'T FIND A MATCH FOR THE MILK TYPE!" << endl;
   cout << matched_milk_type_string;
}

// Function to find a match to the flavor they want
char find_flavor_match(char * typed_desired_flavor, char * matched_flavor_string)
{
   const char flavor_none[] = "none";			// array to compare to matched array
   const char flavor_chocolate[] = "chocolate";		// array to compare to matched array
   const char flavor_vanilla[] = "vanilla";		// array to compare to matched array
   const char flavor_hazelnut[] = "hazelnut";		// array to compare to matched array
   const char flavor_caramel[] = "caramel";		// array to compare to matched array

   if (exact_match(typed_desired_flavor, flavor_none) || missing_letter_match(typed_desired_flavor, flavor_none) || swapped_letter_match(typed_desired_flavor, flavor_none))
   {
      strcpy(matched_flavor_string, "");
   } else if (exact_match(typed_desired_flavor, flavor_chocolate) || missing_letter_match(typed_desired_flavor, flavor_chocolate) || swapped_letter_match(typed_desired_flavor, flavor_chocolate))
   {
      strcpy(matched_flavor_string, "Chocolate ");
   } else if (exact_match(typed_desired_flavor, flavor_vanilla) || missing_letter_match(typed_desired_flavor, flavor_vanilla) || swapped_letter_match(typed_desired_flavor, flavor_vanilla))
   {
      strcpy(matched_flavor_string, "Vanilla ");
   } else if (exact_match(typed_desired_flavor, flavor_hazelnut) || missing_letter_match(typed_desired_flavor, flavor_hazelnut) || swapped_letter_match(typed_desired_flavor, flavor_hazelnut))
   {
      strcpy(matched_flavor_string, "Hazelnut ");
   } else  if (exact_match(typed_desired_flavor, flavor_caramel) || missing_letter_match(typed_desired_flavor, flavor_caramel) || swapped_letter_match(typed_desired_flavor, flavor_caramel))
   {
      strcpy(matched_flavor_string, "Caramel ");
   } else
      cout << "WE DIDN'T FIND A MATCH FOR THE FLAVOR!" << endl;
   cout << matched_flavor_string;
}

// Function to find a match to the the coffee type they want
char find_coffee_type_match(char * typed_desired_coffee, char * matched_coffee_type)
{
   const char coffee_type_espresso[] = "espresso";	// array to compare to matched array
   const char coffee_type_macchiato[] = "macchiato";	// array to compare to matched array
   const char coffee_type_latte[] = "latte";		// array to compare to matched array
   const char coffee_type_cappuccino[] = "cappuccino";	// array to compare to matched array
   const char coffee_type_mocha[] = "mocha";		// array to compare to matched array
   const char coffee_type_brewed[] = "brewed coffee";	// array to compare to matched array

   if (exact_match(typed_desired_coffee, coffee_type_espresso) || missing_letter_match(typed_desired_coffee, coffee_type_espresso) || swapped_letter_match(typed_desired_coffee, coffee_type_espresso))
   {
      strcpy(matched_coffee_type, "Espresso ");
   } else if (exact_match(typed_desired_coffee, coffee_type_macchiato) || missing_letter_match(typed_desired_coffee, coffee_type_macchiato) || swapped_letter_match(typed_desired_coffee, coffee_type_macchiato))
   {
      strcpy(matched_coffee_type, "Macchiato ");
   } else if (exact_match(typed_desired_coffee, coffee_type_latte) || missing_letter_match(typed_desired_coffee, coffee_type_latte) || swapped_letter_match(typed_desired_coffee, coffee_type_latte))
   {
      strcpy(matched_coffee_type, "Latte ");
   } else if (exact_match(typed_desired_coffee, coffee_type_cappuccino) || missing_letter_match(typed_desired_coffee, coffee_type_cappuccino) || swapped_letter_match(typed_desired_coffee, coffee_type_cappuccino))
   {
      strcpy(matched_coffee_type, "Cappuccino ");
   } else if (exact_match(typed_desired_coffee, coffee_type_mocha) || missing_letter_match(typed_desired_coffee, coffee_type_mocha) || swapped_letter_match(typed_desired_coffee, coffee_type_mocha))
   {
      strcpy(matched_coffee_type, "Mocha ");
   } else if (exact_match(typed_desired_coffee, coffee_type_brewed) || missing_letter_match(typed_desired_coffee, coffee_type_brewed) || swapped_letter_match(typed_desired_coffee, coffee_type_brewed))
   {
      strcpy(matched_coffee_type, "Brewed Coffee ");
   } else
      cout << "WE DIDN'T FIND A MATCH FOR THE COFFEE TYPE!" << endl;
   cout << matched_coffee_type << endl;
}

// Function to tell the user whether the order they have typed in is valid or not
// Orders that will not be valid will be:
// Espresso with flavor added to it OR Espresso bigger than a tall
// Everything else will be valid and will tell the user their order is placed
void valid_drink_typed(char * matched_size_string, char * matched_flavor_string, char * matched_coffee_type)
{
   const char coffee_type_espresso[] = "espresso ";	// array to compare to matched array
   const char flavor_chocolate[] = "chocolate ";	// array to compare to matched array
   const char flavor_vanilla[] = "vanilla ";		// array to compare to matched array
   const char flavor_hazelnut[] = "hazelnut ";		// array to compare to matched array
   const char flavor_caramel[] = "caramel ";		// array to compare to matched array
   const char size_grande_string[] = "grande ";		// array to compare to matched array
   const char size_venti_string[] = "venti ";		// array to compare to matched array

   if (exact_match(matched_size_string, size_grande_string) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, the largest size available is a Tall. Your drink has failed to be ordered" << endl;
   } else if (exact_match(matched_size_string, size_venti_string) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, the largest size available is a Tall. Your drink has failed to be ordered" << endl;
   } else if (exact_match(matched_flavor_string, flavor_chocolate) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, you can't have a flavor added. Your drink has failed to be ordered" << endl;
   } else if (exact_match(matched_flavor_string, flavor_vanilla) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, you can't have a flavor added. Your drink has failed to be ordered" << endl;
   } else if (exact_match(matched_flavor_string, flavor_hazelnut) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, you can't have a flavor added. Your drink has failed to be ordered" << endl;
   } else if (exact_match(matched_flavor_string, flavor_caramel) && exact_match(matched_coffee_type, coffee_type_espresso))
   {
      cout << "I am sorry. This is an invalid option. For an Espresso, you can't have a flavor added. Your drink has failed to be ordered" << endl;
   } else
      cout << "This is a valid drink order. Your drink order has been place!" << endl;
}
