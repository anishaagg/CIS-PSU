// Anisha Aggarwal, CS161, Program 5
// Purpose is to have 2 players play the Word Guessing Game
// Player 1 will enter a word and Player 2 will try to guess the word based on hints

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


// Prototypes
void welcome();
void get_word(string word[], int & length);
void clear_screen();
void prompt_one(string word[], int length);
void prompt_two(string word[], int length);
void prompt_three(string word[], int length);
void prompt_four(string word[], int length);
void get_guess(string word[], int chances);
bool match(string word[], bool & matched, int chances);
void add_points(int & add_point, bool & matched, int & chances, int points[]);
int calc_points(int & chances, int & points);


int main()
{
   string word[5];		// array to hold player's word
   //char guess_word[MAX];	// array to hold player's guessed word
   bool matched = false;	// bool to figure out whether the guessed word matched the word or not
   int length = 0;		// length to hold the number of letters in word
   int points[2] = {0, 0};	// points for Player 1 and Player 2
   int add_point;		// which player will recieve points
   int chances;                 // number of chances the guessing player will get

   // Welcome the user and prompt player to type in a word that will be guessed
   welcome();
   do {
      get_word(word, length);
      clear_screen();		//clear screen so that other player doesn't see the word
      chances = 0;		// number of chances player gets to guess correctly
      do {
         chances++;
         if (chances == 1) {
            prompt_one(word, length);
         } else if (chances == 2) {
            prompt_two(word, length);
         } else if (chances == 3) {
            prompt_three(word, length);
         } else if (chances == 4) {
            prompt_four(word, length);
         }
         get_guess(word, chances);
         //cout << guess_word << endl;
         match(word, matched, chances);
         //cout << "Chances left: " << 4 - chances << endl; 
         //cout << "Matched: " << matched << endl;
      } while ((chances < 4) && (matched == false));
     
      // add up points and display
      add_points(add_point, matched, chances, points);

     // print out the actual word and the guesses made 
      cout << endl;
      cout << "The actual word was: " << word[0] << endl;
      cout << "The guesses made were: " << endl << word[1] << endl << word[2] << endl << word[3] << endl <<word[4] << endl;
     
      // clear all of the words in the string array
      word[0].clear();
      word[1].clear();
      word[2].clear();
      word[3].clear();
      word[4].clear();
   } while ((points[0] < 10) && (points[1] < 10));

   if (points[0] >= 10) {
      cout << "Player 1 WON!" << endl;
   } else if (points[1] >= 10) {
      cout << "Player 2 WON!" << endl;
   }
  
   return 0;
}

// Function that will read in Player 1's word and capitalize all of the letters to allow for comparison
void get_word(string word[], int & len)
{
    
    // get user input on word
    cout << "Please enter in a word." << endl;
    cin >> word[0];
    cin.ignore(100, '\n');
    
    // capitalize every letter in that word for comparison later
    len = word[0].length();
    for (int i = 0; i < len; ++i) {
        word[0][i] = toupper(word[0][i]);
    }
    
    // display the word to check if it is storing correctly
    //cout << word[0] << endl;
}

// Function that will clear the screen so that Player 2 doesn't see what the word is
void clear_screen()
{
    // clear the screen 500 lines
   for (int i = 0; i < 500; ++i)
   {
      cout << endl;
   }
}

// Function that will show Player 2 the number of letters that are in the word
// with underscores
void prompt_one(string word[], int length)
{
    // get the length of the word and display underscores for each letter in the word
    for (int i = 0; i < length; ++i)
    {
        cout << "_ ";
    }
    cout << endl;
}

// Function that will give Player 2 a hint and will show the first character of the word
void prompt_two(string word[], int length)
{
    // get the length of the word so that the first letter of the word and correct number of underscores can be displayed
    for(int i = 0; i < length; ++i)
    {
        // if its the first letter of the word display it
        if (i == 0) {
            cout << word[0][i] << " ";
        } else {    // else display underscores
             cout << "_ ";
        }
    }
    cout << endl;
}

// Function that will give Player 2 another hint that will
// provide the first and last character of the word
void prompt_three(string word[], int length)
{
    // get the length of the word and display first letter, last letter or underscore
    for(int i = 0; i < length; ++i)
    {
        if (i == 0) {                       // first letter
            cout << word[0][i] << " ";
        } else if (i == (length - 1)) {     // last letter
            cout << word[0][i] << " ";
        } else {                            // underscores for the rest
            cout << "_ ";
        }
    }
    cout << endl;

}

// Fuction that will give Player 2 a last hint it will show them
// the first character, all of the vowels, and the last character of the word
void prompt_four(string word[], int length)
{
    char ch;    // variable that will hold the letter to match
    
    for(int i = 0; i < length; ++i)
    {
        if (i == 0) {                       // first letter
            cout << ch << " ";
        } else if (i == (length - 1)) {     // last letter
            cout << ch << " ";
        } else if((ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U')) {    //matches a vowel
            cout << ch << " ";
        } else {                            // underscores for the rest
            cout << "_ ";
        }
    }
    cout << endl;

}

// Function that will read in Player 2's guess on what the word is
// and will capitalize each letter so that it can be compared to Player 1's word
void get_guess(string word[], int chances)
{
    int len = 0;

    // have the user enter in their guessed word
    cout << "Please enter in a word that you would like to guess" << endl;
    cin >> word[chances];
    cin.ignore(100, '\n');

    // get the length of that word and capitalize each letter of that word
    len = word[chances].length();
    for (int i = 0; i < len; ++i)
    {
        word[chances][i] = toupper(word[chances][i]);
    }

    //cout << word[chances] << endl;
}

// Function that will match the word with the guessed word
bool match(string word[], bool & matched, int chances)
{
   if (word[0].compare(word[chances]) == 0)
   {
      cout << "CONGRATULATIONS! YOU HAVE GUESSED THE WORD CORRECTLY!" << endl;
      matched = true;
   } else
   {
      cout << "I'm sorry! That is not correct.." << endl;
      matched = false;
   }
   return matched;
}

// Function that will add points to either player 1 or player 2
void add_points(int & add_point, bool & matched, int & chances, int points[])
{
    // figure out which player should be earning the points
   do {
      if (matched == true) {
         cout << "Which player guessed the word correctly? (1 or 2)" << endl;
         cin >> add_point;
         cin.ignore(100,'\n');
      } else {
          add_point = 0;
      }
   } while ((add_point != 0) && (add_point != 1) && (add_point != 2));

   // add points to the correct player
   if (add_point == 1) {
      calc_points(chances, points[0]);
   } else if (add_point == 2) {
      calc_points(chances, points[1]);
   }

   // display the points at the end of the round
   cout << endl << "Points: " << endl;
   cout << "Player 1: " << points[0] << endl;
   cout << "Player 2: " << points[1] << endl;
}

// Function that will add points to either Player 1 or 2
int calc_points(int & chances, int & points)
{
    // based on how many guesses the player took, determine number of points they should earn
   if (chances == 1) {
      points = points + 4;
   } else if (chances == 2) {
      points = points + 3;
   } else if (chances == 3) {
      points = points + 2;
   } else if (chances == 4) {
      points = points + 1;
   }

   return points;
}

// Function that will explain all of the rules
void welcome()
{
   char instructions = 'N';

   cout << "Welcome to the Word Guessing Game!" << endl;

   cout << "Do you know how to play this game? (Y or N)" << endl;
   cin >> instructions;
   cin.ignore(100, '\n');
   instructions = toupper(instructions);
   while ((instructions != 'Y') && (instructions != 'N'))
   {
      cout << "Please re-enter.." << endl;
      cin >> instructions;
      cin.ignore(100, '\n');
      instructions = toupper(instructions);
   }

   if (instructions == 'N')
   {
      cout << endl << endl <<  "Instructions: " << endl;
      cout << "The goal of this game is for Player 2 to guess what word Player 1 has thought of." << endl;
      cout << "Player 1 will type in a single word, while Player 2 was not looking!" << endl;
      cout << "Once Player 1 has entered a word, Player 2 will be shown the number of letters";
      cout << " in that word and will then try to guess the word." << endl;
      cout << "Player 2 will get 4 tries to guess the word and will be given a new hint every ";
      cout << "time they guess wrong." << endl << endl;
      cout << "If Player 2 guesses correctly they will recieve points:" << endl;
      cout << "4 = on first try" << endl << "3 = on second try" << endl;
      cout << "2 = on third try" << endl  << "1 = on fourth try" << endl;
      cout << "Then switch roles. The first player to 10 points wins!" << endl;
   }
   cout << "Now decide who will be Player 1 and who will be Player 2!" << endl;
   cout << "Good luck!" << endl;
}
