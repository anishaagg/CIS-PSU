#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Anisha Aggarwal, Ordering Drinks
// CS 162 - Program 1

// Create a program that will take a persons drink order
// Determine the type of coffee drink they want with whatever flavors they want
// After they have made each drink order, tell them what the fancy name is

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

// Function to get users input on the size for the coffee order
int get_user_input_size()
{
   int size;                    // size of the drink the customer wants
   cout << "What size drink would you like? (Small = 1, Medium = 2, Large = 3)" << endl;
   cin >> size;
   while ((size < 1) || (size > 3))
   {
      cout << "What size drink would you like? (Small = 1, Medium = 2, Large = 3)" << endl;
      cin >> size;
   }
   return size;
}

// Function to get users input on the amount of milk for the coffee order
int get_user_input_milk_amount()
{
   int milk_amount;             // the amount of milk the customer wants

   cout << "How much milk would you like? (None = 1, Some = 2, or Mostly = 3)" << endl;
   cin >> milk_amount;
   while ((milk_amount < 1) || (milk_amount > 3))
   {
      cout << "How much milk would you like? (None = 1, Some = 2, or Mostly = 3)" << endl;
      cin >> milk_amount;
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
   }
   return milk_type;
}

// Function to get users input on the foam that will be added in for the coffee order
int get_user_input_foam()
{
   int foam_amount;             // the amount of foam the customer wants

   cout << "How much foam would you like? (None = 1 or Some = 2)" << endl;
   cin >> foam_amount;
   while ((foam_amount != 1) && (foam_amount != 2))
   {
      cout << "How much foam would you like? (None = 1 or Some = 2)" << endl;
      cin >> foam_amount;
   }
   return foam_amount;
}

// Function to get users input on the flavor that will be added in for the coffee order
int get_uesr_input_coffee_flavor()
{
   int coffee_flavor;           // the flavor of coffee the customer would like

   cout << "What flavor of coffee would you like? (None = 1, Chocolate = 2, Vanilla = 3, Hazelnut = 4, Caramel = 5)" <<endl;
   cin >> coffee_flavor;
   while ((coffee_flavor < 1) || (coffee_flavor > 5))
   {
      cout << "What flavor of coffee would you like? (None = 1, Chocolate = 2, Vanilla = 3, Hazelnut = 4, Caramel = 5)" <<endl;
      cin >> coffee_flavor;
   }
   return coffee_flavor;
}

// Function to determine the number of drinks the customer wants
// It will return the number of drinks
int get_num_drinks()
{
   int num_drinks;   // the number of drinks the customer would like = number of loops

   cout << "Hello! How many drinks would you like to order today?" << endl;
   cin >> num_drinks;
   return num_drinks;
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
   more_customers = toupper(more_customers);
   while ((more_customers != 'Y') && (more_customers != 'N'))
   {
      cout << "Sorry I did not understand that. Please try again" <<endl;
      cout << "Are there any more customers? (Y or N)" <<endl;
      cin >> more_customers;
      more_customers = toupper(more_customers);
   }
   // cout << more_customers;    //to check if this was capitalizing properly
   return more_customers;
}


int main()
{
   // With in Do/While loop, get customer input on type of drink
   // Tell customer what their fancy drink order name is
   // Repeat for number of drinks they want
   // Ask if more customers (yes = repeat all over again, n = quit out)

   int num_drinks;		// the number of drinks the customer would like = number of loops
   int coffee_type;		// the type of coffee the customer wants
   int size;			// size of the drink the customer wants
   int coffee_flavor;		// the flavor of coffee the customer would like
   int milk_type;		// the type of milk the customer would like in their coffee
   int milk_amount;		// the amount of milk the customer wants
   int foam_amount;		// the amount of foam the customer wants
   char more_customers = 'N'; 	// variable to hold yes or no for whether there are/aren't more customers

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
	   coffee_flavor = get_uesr_input_coffee_flavor();
           coffee_type = determine_coffee_type(coffee_flavor, milk_amount, foam_amount);
           determine_fancy_name(size, milk_type, coffee_flavor, coffee_type);
           num_drinks = num_drinks - 1;
	} while (num_drinks > 0);
   	more_customers = determine_more_customers();
   } while(more_customers == 'Y');

   return 0;
}
