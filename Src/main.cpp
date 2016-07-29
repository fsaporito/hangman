#include "main.hpp"

int main (int argc, char *argv[]) {

	bool input_ok = true;

	string word = "";
	/*
	do {

		cout << "Input Word: ";

		cin >> word;

		input_ok = check_input (word);

		if (!input_ok) {

			cerr << "Not Accepted Word !!!\n\n\n";

			word = "";

		}

	} while (!input_ok);

	hangman my_hangman(word);
	*/
	
	hangman my_hangman;

	// cout << "instantiated :)\n";

	//my_hangman.~hangman ();

	//cout << "Destroyed Hangman object\n";


	return 0;

}


// Check If The Input Is Correct
bool check_input (string &word) {

	bool input_ok = true;

	if (word == "" && input_ok) {

		input_ok = false;

	}

	for (int i = 0; (i < word.length() && input_ok); i++) {

		if (isalpha(word.at(i))) {

			input_ok = true;

			if (isalpha(word.at(i))) {

				word[i] =(char) tolower(word.at(i));

			}

		} else {

			input_ok = false;

		}

	}


	return input_ok;

}



