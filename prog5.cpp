// Anisha Aggarwal, CS161, Program 5
// Purpose is to have 2 players play the Word Guessing Game
// Player 1 will enter a word and Player 2 will try to guess the word based on hints

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Constants
const int MAX = 21;

// Prototypes
void welcome();
void get_word(char word[], int length);
void clear_screen();
void prompt_one(char word[], int length);
void prompt_two(char word[], int length);
void prompt_three(char word[], int length);
void prompt_four(char word[], int length);
void get_guess(char guess_word[], int length);
bool match(char word[], char guess_word[], bool & matched);
void add_points(int & add_point, bool & matched, int & chances, int & points_1, int & points_2);
int calc_points(int & chances, int & points);

int main()
{
   char word[MAX];		// array to hold player's word
   char guess_word[MAX];	// array to hold player's guessed word
   bool matched = false;	// bool to figure out whether the guessed word matched the word or not
   int length = 0;		// length to hold the number of letters in word
   int points_1 = 0;		// points for Player 1
   int points_2 = 0;		// points for Player 2
   int add_point;		// which player will recieve points
   int chances;                 // number of chances the guessing player will get

   // Welcome the user and prompt player to type in a word that will be guessed
   welcome();
   do {
      get_word(word, length);
//      cout << word << endl;
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
         get_guess(guess_word, length);
         //cout << guess_word << endl;
         match(word, guess_word, matched);
         //cout << "Chances left: " << 4 - chances << endl; 
         //cout << "Matched: " << matched << endl;
      } while ((chances < 4) && (matched == false));
      add_points(add_point, matched, chances, points_1, points_2);
      
   } while ((points_1 < 10) && (points_2 < 10));

   if (points_1 >= 10) {
      cout << "Player 1 WON!" << endl;
   } else if (points_2 <= 10) {
      cout << "Player 2 WON!" << endl;
   }

   return 0;
}

// Functions to be implemented
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

// Function that will read in Player 1's word and capitalize all of the letters to allow for comparison
void get_word(char word[], int length)
{
   cout << "Please enter in a word." << endl;
   cin.get(word, MAX, '\n');
   cin.ignore(100, '\n');

   length = strlen(word);
   for (int i = 0; i < length; ++i)
   {
      word[i] = toupper(word[i]);
   }

}

// Function that will clear the screen so that Player 2 doesn't see what the word is
void clear_screen()
{
   for (int i = 0; i < 50; ++i)
   {
      cout << endl;
   }
}

// Function that will show Player 2 the number of letters that are in the word
// with underscores
void prompt_one(char word[], int length)
{
   length = strlen(word);
   for (int i = 0; i < length; ++i)
   {
      cout << "_ ";
   }
   cout << endl;
}

// Function that will give Player 2 a hint and will show the first character of the word
void prompt_two(char word[], int length)
{
   length = strlen(word);
   for(int i = 0; i < length; ++i)
   {
      if (i == 0) {
         cout << word[i] << " ";
      } else {
         cout << "_ ";
      }
   }
   cout << endl;
}

// Function that will give Player 2 another hint that will
// provide the first and last character of the word
void prompt_three(char word[], int length)
{
   length = strlen(word);
   for(int i = 0; i < length; ++i)
   {
      if (i == 0) {
         cout << word[i] << " ";
      } else if (i == (length - 1)) {
         cout << word[i] << " ";
      } else {
         cout << "_ ";
      }
   }
   cout << endl;

}

// Fuction that will give Player 2 a last hint it will show them
// the first character, all of the vowels, and the last character of the word
void prompt_four(char word[], int length)
{
   length = strlen(word);
   for(int i = 0; i < length; ++i)
   {
      if (i == 0) {
         cout << word[i] << " ";
      } else if (i == (length - 1)) {
         cout << word[i] << " ";
      } else if((word[i] == 'A') || (word[i] == 'E') || (word[i] == 'I') || (word[i] == 'O') || (word[i] == 'U')) {
         cout << word[i] << " ";
      } else {
         cout << "_ ";
      }
   }
   cout << endl;

}

// Function that will read in Player 2's guess on what the word is
// and will capitalize each letter so that it can be compared to Player 1's word
void get_guess(char guess_word[], int length)
{
   cout << "Please enter in a word that you would like to guess" << endl;
   cin.get(guess_word, MAX, '\n');
   cin.ignore(100, '\n');

   length = strlen(guess_word);
   for (int i = 0; i < length; ++i)
   {
       guess_word[i] = toupper(guess_word[i]);
   }

   cout << endl;
}

// Function that will match the word with the guessed word
bool match(char word[], char guess_word[], bool & matched)
{
   if (strcmp(word, guess_word) == 0)
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
void add_points(int & add_point, bool & matched, int & chances, int & points_1, int & points_2)
{
   do {
      if (matched == true) {
         cout << "Which player guessed the word correctly? (1 or 2)" << endl;
         cin >> add_point;
         cin.ignore(100,'\n');
      } else {
          add_point = 0;
      }
   } while ((add_point != 0) && (add_point != 1) && (add_point != 2));

   if (add_point == 1) {
      calc_points(chances, points_1);
   } else if (add_point == 2) {
      calc_points(chances, points_2);
   }
   cout << endl << "Points: " << endl;
   cout << "Player 1: " << points_1 << endl;
   cout << "Player 2: " << points_2 << endl;
}

// Function that will add points to either Player 1 or 2
int calc_points(int & chances, int & points)
{
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


