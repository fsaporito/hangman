#include "hangman.hpp"


// Constructor With No Parameters
hangman::hangman () {

	cout << "Constructor With No Parameters \n";


	// Load Dictionary
	dict_line_num = read_dict();
	
	int random = 0;
	
	bool flag = false;

	while (!flag) {

		cout << "Lets Create a random number: ";
		srand (time(NULL)+random);
		random = rand() % dict_line_num;
		cout << random << "  -  " << dict[random] << "\n";
		
		if (dict.at(random).length() < 6) {
			
			cout << "Lengh less than 6" << endl;
		
			flag = false;
			
		} else {
			
			flag = check_input (dict.at(random));
			
		}		

	}

	// Set The Chosen Word
	set_word(dict.at(random));

	// Initialize The Class Fields
	init();

	// Start Playing The Game
	play();

}


// Contructor With Parameters
hangman::hangman (string input) {

	cout << "Constructor With String Parameter: " << input << "\n";

	// Set The Chosen Word
	set_word(input);

	// Initialize The Class Fields
	init();

	// Start playing the game
	play();

}


// Destructor
hangman::~hangman () {

	cout << "Hangman Destructor ... ";

	/*
	delete word;
	delete word_len;
	delete counter;
	delete guessed_word;
	delete new_letter;
	delete [] list;
	*/

	cout << "Done\n";

}

// Read Random Word From Dictionary
int hangman::read_dict() {

	cout << "Loading Dictionary: " << "en.dict" << "\n";

	string line;
	int file_len = 0;

	ifstream file("en.dict");
	
	if (!file.is_open()) { cerr << "error while opening file"; }
	
	cout << "Reading en.dict: \n";

	//while (getline(file, line)) {
	while (file >> line) {

		dict.push_back(line);
		
		file_len++;		
		
		cout << "\rLines Read: " << file_len;
		
	}
	
	if (file.bad()) { cerr << "\nerror while reading file"; }
	
	cout << "\nRead Dictionary - Lines: " << file_len << "\n";

	return file_len;

}


// Initialize The Class Fields
void hangman::init () {

	// Guessed Word Field
	guessed_word = "";

	// This Loop Creates The Guessed Word With Underscores
	for (int i = 0; i < word_len; i++) {

		guessed_word.append("_");

	}

	// Counter Initialisation
	// You Have 4 tries
	counter = 4;

	// Initialize The Letter Vector List
	vector<string> my_list;
	list = my_list;

}


// Play The Game Set Up By The Constructor
void hangman::play () {

	// Win Flag
	bool win = false;

	// Input Flag
	bool input_ok = true;

	// Find Function Result
	// 0 -> Letter Present In Word
	// 1 -> Letter Not Present In Word
	// 2 -> Letter Already Checked
	int find_res = 0;

	// Automatically Gives First Letter
	new_letter = word.substr(0,1);
	cout << "First Letter: " << new_letter << "\n";
	find_res = find_char (new_letter);

	// Automatically Gives Last Letter
	new_letter = word.substr((unsigned int) (word_len-1), (unsigned int) word_len);;
	cout << "Last Letter: " << new_letter << "\n";
	find_res = find_char (new_letter);

	while (!win && counter > 0) {

		//cout << "\n\n\n\n\n\n\n\n\n";

		cout << guessed_word << "\n\n";

		cout << "Remaning Tries: " << counter << "\n\n";

		do {

			cout << "Guess the next letter: ";

			cin >> new_letter;

			input_ok = check_input (new_letter);

			if (!input_ok) {

				cerr << "Not Accepted Letter !!!\n\n";

				new_letter = "";

			}

		} while (!input_ok);

		find_res = find_char (new_letter.substr(0, 1));

		if (find_res == 0) { // Letter Found

			cout << "\n\n Letter Found :) \n";

		}

		if (find_res == 1) { // Letter Not Present In Word

			cout << "\n\n Letter Not Present :( Try Again \n";
		    counter--;

		}

		if (find_res == 2) { // Letter Already Checked

			cout << "\n\n Letter Already Checked :( Try Again \n";

		}

		if (word.compare(guessed_word) == 0) {

			win = true;

		}

	}

	if (win) {

		cout << "\n\n YOU WON !!! \n\n";
		cout << "Your Guess: " << guessed_word << "\n";
		cout << "Correct Word: " << word << "\n";

	} else {

		cout << "\n\n YOU LOST :( !!! \n\n";
		cout << "Your Guess: " << guessed_word << "\n";
		cout << "Correct Word: " << word << "\n";

	}

	return;

}


// Check If The Input Is Correct
bool hangman::check_input (string &word) {

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


// 0 -> Letter Present In Word
// 1 -> Letter Not Present In Word
// 2 -> Letter Already Checked
int hangman::find_char (string letter) {

	int res = 0;

	// Check If The Letter Has Been Already Inserted
	if (find(list.begin(), list.end(), letter) != list.end()) {

		res = 2; // Letter Already Inserted

	} else {

		list.push_back(letter); // Add letter to list

		if (word.find(letter.at(0)) != -1) { // Check if word contains letter

			for (int i = 0; i < word_len; i++) {

				if (word.at(i) == letter.at(0)) {

					guessed_word[i] =(char) letter.at(0);

				}

			}

			res = 0;

		} else { // Wrong letter

			res = 1;

		}

	}

	return res;

}


// Return The Chosen Word To Guess
string hangman::get_word () {

	return word;

}


// Set A New Word To Guess
void hangman::set_word (string new_word) {

	// Word Initialisation
	word = new_word;

	// Word Length Initialisation
	word_len = word.length();

	return;

}


