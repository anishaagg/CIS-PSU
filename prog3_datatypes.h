// Anisha Aggarwal, CS162
// prog3_datatypes.h

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Constants
#define MAX_INV 100

// Structure definitions here (globally)
struct device_info{char trade[6];
                   char device_type[20];
                   char manufacturer[20];
                   char model[20];
                   char description[100];
                   char value[8];
                   bool valid; };


// Class that will hold the inventory information
class inventory
{
   public:
      // operations go here
      inventory();                      // constructor (Default)
      int read_inv();                   // will read in the inventory
      bool add(device_info &);		// add another device with all of its information
      int display_all();                // displays the inventory
      int remove();			// removes the serial number of the item being purchased
      int write_inv();                  // will write the inventory into the external file
   private:
      // memory is reserved here
      device_info device_inv[MAX_INV];              // an array of devices in the inventory
      int num_devices;                          // holds the number of devices are being stored
};
