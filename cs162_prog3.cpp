#include <iostream>
#include <fstream>
#include "prog3_datatypes.h"
#include <cstring>
#include <cctype>
using namespace std;

// Anisha Aggarwal
// CS162, Program 3
// Purpose is to help people sell or trade their used electronic devices
// Have them input: type of item, manufacturer, model, description of the
// condition its in, value, and whether it is available for trade or not.
// All of this information must be remembered so that each time a program ends,
// it doesn’t  get lost

// Prototypes:
void get_device_type(char trade[], char device_type[], char manufacturer[], char model[], char description[], char value[]);

int main()
{
   // Variables
   fstream f_inv;			// variable for the inventory data file for reading in the file
   device_info a_device;		// variable to allow functions to access struct variables
   char user_input;			// variable to hold what task the user wants the app to preform
   inventory a_inv;			// variable to access the inventory class

   // Read in the existing inventory file
   a_inv.read_inv();
   do
   {
      do
      {
         cout << " Would you like to (A) add a device to the inventory, (B) display all of the items currently in inventory, or (Q) quit?" << endl;
         cin >> user_input;
         cin.ignore(100, '\n');
         user_input = toupper(user_input);
//         cout << user_input;
      } while (user_input != 'A' && user_input != 'B' && user_input != 'Q');

      if (user_input == 'A')
      {
         // allow user to add a device to the inventory
         a_inv.add(a_device);
      } else if (user_input == 'B')
      {
         // Print the current inventory
         a_inv.display_all();
         // Ask the user if they would like to purchase an item - if yes, allow them to do so, else go to get user_input again
         a_inv.remove();
      } else if (user_input == 'Q')
      {
         // clear the current inventory file and rewrite it with all the updated inventory
         // quit out of the program
         a_inv.write_inv();
      }
   } while (user_input != 'Q');

   return 0;
}

// Functions bodies:

//Function that will read in the necessary information about the device
void get_device_type(char trade_sell[], char device_type[], char manufacturer[], char model[], char description[], char value[])
{
   // Read in the type of device, manufacturer, model, a description of it's condition,
   // and whether the user would like to sell/trade the device.
   do
   {
      cout << "Would you like to (A) trade or (B) sell the device you are posting? (A or B)" << endl;
      cin.get(trade_sell, 6, '\n');
      cin.ignore(100, '\n');
      trade_sell[0] = toupper(trade_sell[0]);
   } while (trade_sell[0] != 'A' && trade_sell[0] != 'B');
   if (trade_sell[0] == 'A')
   {
      strcpy(trade_sell, "Trade");
   } else strcpy(trade_sell, "Sell");

   cout << "What type of device would you like to post?" << endl;
   cin.get(device_type, 20, '\n');
   cin.ignore(100, '\n');
   device_type[0] = toupper(device_type[0]);

   cout << "Who is the manufacturer?" << endl;
   cin.get(manufacturer, 20, '\n');
   cin.ignore(100, '\n');
   manufacturer[0] = toupper(manufacturer[0]);

   cout << "What is the model?" << endl;
   cin.get(model, 20, '\n');
   cin.ignore(100, '\n');
   model[0] = toupper(model[0]);

   cout << "Describe the condition the product is in in less than 100 characters" << endl;
   cin.get(description, 100, '\n');
   cin.ignore(100, '\n');
   description[0] = toupper(description[0]);

   cout << "What would you price this products value at? " << endl;
   cin.get(value, 8, '\n');
   cin.ignore(100, '\n');

}


// Function to impliment the class
inventory::inventory()
{
//   cout << "Constructor is called" << endl;
   num_devices = 0;
   for(int i = 0; i < MAX_INV; ++i)
   {
      device_inv[i].valid = false;
   }
}

// Function that will read in the inventory from the external file
int inventory::read_inv()
{
   fstream f_inv;			// variable for the inventory data file for reading and writing in

   // Open the external file
   f_inv.open("inventory");

   // Check to make sure file exists
   if (f_inv != 0)
   {
//      cout << "FILE WAS OPENED!" << endl;
      // Read in the existing inventory into the memory
      while (f_inv.getline(device_inv[num_devices].device_type, 100, ':') && !f_inv.eof())
      {
         f_inv.getline(device_inv[num_devices].manufacturer, 100, ':');
         f_inv.getline(device_inv[num_devices].model, 100, ':');
         f_inv.getline(device_inv[num_devices].description, 100, ':');
         f_inv.getline(device_inv[num_devices].value, 100, ':');
         f_inv.getline(device_inv[num_devices].trade, 100, '\n');

         // make the entry being read set to valid so that it may be displayed
         device_inv[num_devices].valid = true;

//         cout << "Device type: " << device_inv[num_devices].device_type << endl;
//         cout << "Manufacturer: " << device_inv[num_devices].manufacturer << endl;
//         cout << "Model: " << device_inv[num_devices].model << endl;
//         cout << "Description: " << device_inv[num_devices].description << endl;
//         cout << "Value: $" << device_inv[num_devices].value << endl;
//         cout << "Available for: " << device_inv[num_devices].trade << endl;

         ++num_devices;
      }
   } else cout << "File doesn't exist" << endl;

}

// Function that will add a device to the inventory
bool inventory::add(device_info & a_device)
{
   bool found_add_slot = false;

   for(int i = 0; i < MAX_INV; ++i)
   {
      if (device_inv[i].valid == false)
      {
         get_device_type(a_device.trade, a_device.device_type, a_device.manufacturer, a_device.model, a_device.description, a_device.value);
         device_inv[i] = a_device;
         device_inv[i].valid = true;
         cout << "Your item has been added!" << endl;
         found_add_slot = true;
         ++num_devices;
//         cout << num_devices << endl;
         return true;
      }
   }
   if (found_add_slot == false)
   {
      cout << "Inventory is full! Sorry..." << endl;
   }

   return false;
}

// Fuction that will display all of the devices in the inventory
int inventory::display_all()
{
   int serial_num;	// variable that will tell the user what number the device is

   serial_num = 1;
   cout << "There are " << num_devices << " devices in the inventory:" << endl;
   for(int i = 0; i < MAX_INV; ++i)
   {
      if (device_inv[i].valid == true)
      {
         cout << serial_num << ".  ";
         cout << "DEVICE TYPE: " << device_inv[i].device_type << '\t'<<'\t';
         cout << "MANUFACTURER: " << device_inv[i].manufacturer << '\t'<<'\t';
         cout << "MODEL: " << device_inv[i].model << '\t'<<'\t';
         cout << "VALUE: $" << device_inv[i].value << endl;
         cout << '\t'<< "AVAILABLE FOR: " << device_inv[i].trade << '\t'<< '\t';
         cout << "DESCRIPTION: " << device_inv[i].description << endl;
         ++serial_num;
      }

   }
   return 0;
}

// Function to remove a device from the inventory
int inventory::remove()
{
   int serial_num;
   char remove;
   int valid_count;
   bool item_found = false;

   if (num_devices != 0)
   {
      cout << "Would you like to purchase an item? (Y or N)" << endl;
      cin >> remove;
      remove = toupper(remove);
      while (remove != 'Y' && remove != 'N')
      {
         cout << "Please re-enter..." << endl;
         cin >> remove;
         remove = toupper(remove);
      }
      if (remove == 'Y')
      {
         // Get which item number the user would like to purchase from inventory
         cout << "Which item number would you like to purchase?" << endl;
         cin >> serial_num;
         while (serial_num <= 0 || serial_num > 100)
         {
            cout << "Please re-enter..." << endl;
            cin >> serial_num;
         }

         valid_count = 0;
         // Determine which item the user wants to purchase and remove it from the inventory
         for (int i = 0; (valid_count != serial_num) && (i < MAX_INV); ++i)
         {
            if (device_inv[i].valid == true)
            {
               ++valid_count;
               if (valid_count == (serial_num))
               {
                  item_found = true;
                  device_inv[i].valid = false;
                  --num_devices;
                  cout << "CONGRATULATIONS! Item number " << serial_num << " is yours!" << endl;
               } // else it will move on to the next element in the array
            } // else it will move on to the next element in the array
         }
         if (item_found == false)
         {
            cout << "I'm sorry, the item you have requested to purchase is not available." << endl;
         }
      }
   }
   return 0;
}

// Function to delete all of the inventory that was previously stored in the external file
// then will re-write the new updated inventory into it
int inventory::write_inv()
{
   ofstream of_inv;			// variable for the inventory data file for writing in the file

   of_inv.open("inventory", ios::trunc | ios::out);

   if (of_inv != 0)
   {
      for(int i = 0; i < MAX_INV; ++i)
      {
         if (device_inv[i].valid == true)
         {
            of_inv << device_inv[i].device_type << ":";
            of_inv << device_inv[i].manufacturer << ":";
            of_inv << device_inv[i].model << ":";
            of_inv << device_inv[i].description << ":";
            of_inv << device_inv[i].value << ":";
            of_inv << device_inv[i].trade << endl;
         }
      }
   } else
   {
      cout << "FAILED TO OPEN INVENTORY FILE!!" << endl;
      return 1;
   }

   return 0;
}



