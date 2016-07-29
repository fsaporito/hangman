#ifndef _HANGMAN_HPP

	#define _HANGMAN_HPP

	using namespace std;

	#include <iostream> 	// std::cout, std::cin
	#include <cctype>		// std::isalpha, std::isupper, std::tolower
	#include <cstring>		// std::append, std::at, std::substr
	#include <fstream>		// std::ifstream
	#include <algorithm>    // std::find
	#include <vector>       // std::vector
	#include <ctime>			// time(), used to seed srand() and rand()

	class hangman {

		public:

			// Constructor With No Parameters
			hangman ();

			// Constructor With Parameters
			hangman (string input);

			// Custom Destructor
			~hangman ();

			// Check If The Input Is Correct
			bool check_input (string &word);

			// Returns The Word To Guess
			string get_word ();

			// Set New Word
			void set_word (string new_word);


		private:

			// Word Field
			string word;

			// Word Length
			int word_len;

			// Guessed Word Field
			string guessed_word;

			// New Letter
			string new_letter;

			// Counter
			int counter;

			// Vector List Of Tried Letters
			vector<string> list;

			// Vector Containing The Dictionary
			vector<string> dict;

			// Dictionary Lenght
			int dict_line_num;

			// Read A Random Word From The Dictionary
			// Returns The File's Lines Number
			int read_dict();

			// Initialize The Class Fields
			void init ();

			// Play Function
			void play ();

			// Find The Letter In The Word That Has To Be Guessed
			// 0 -> Letter Present In Word
			// 1 -> Letter Not Present In Word
			// 2 -> Letter Already Checked
			int find_char (string letter);


	};

#endif


