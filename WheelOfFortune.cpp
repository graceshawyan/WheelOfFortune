#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

string puzzle = "";
string phrase;

int money = 1000;
const int vowel_price = 700;
const int consonant_price = 200;

void print_array(string arr[], string phrase) {
    for (int i = 0; i < phrase.length(); i++) {
        cout << arr[i] << " ";
    }
}

int spin_outcome() {
    int paid_amount = 0;
    int randomValue = rand() % 5 + 1;
    switch (randomValue) {
    case 1:
        paid_amount = 100;
        cout << "Nice Spin! You get $100 for every correct consonant!" << endl;
        break;
    case 2:
        paid_amount = 200;
        cout << "Spectacular! You get $200 for every correct consonant!" << endl;
        break;
    case 3:
        paid_amount = 500;
        cout << "Awesome! You get $500 for every correct consonant!" << endl;
        break;
    case 4:
        paid_amount = 600;
        cout << "Fantastic! You get $600 for every correct consonant!" << endl;
        break;
    case 5:
        paid_amount = 1000;
        cout << "WOW! You get $1000 for every correct consonant!" << endl;
        break;
    default:
        paid_amount = 0;
        cout << "Error" << endl;
    }
    return paid_amount;
}

string pick_puzzle() {
    cout << "Here are the categories you can choose to play: " << endl;
    cout << "1. Movies" << endl;
    cout << "2. Food and Drinks" << endl;
    cout << "3. Phrases" << endl;
    cout << "4. Song Lyrics" << endl;

    int choice;
    cout << "Enter your choice (1,2,3, or 4): ";
    while (!(cin >> choice) || choice < 1 || choice > 4) {
        cout << "Invalid input. Please enter a number between 1 and 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    if (choice == 1) {
        vector<string> movies = {
            "Red, White, and Royal Blue",
            "Hidden Figures",
            "Jurassic Park",
            "The Whale",
            "The Greatest Showman",
            "A Beautiful Mind",
        };
        int randIndex = rand() % movies.size();
        puzzle = movies[randIndex];
    } else if (choice == 2) {
        vector<string> food_and_drinks = {
            "Boba Milk Tea", "Chocolate Chip Cookies", "Peking Duck",
            "Margherita Pizza", "Chicken Alfredo Pasta", "Butter Chicken",
            "Ice Cream Cake", "Fish and Chips",
        };
        int randIndex = rand() % food_and_drinks.size();
        puzzle = food_and_drinks[randIndex];
    } else if (choice == 3) {
        vector<string> phrases = {
            "A Piece of Cake", "In The Nick Of Time",
            "All's Well That Ends Well", "All That Glitters is Not Gold",
            "Only Time Will Tell", "The Early Bird Gets the Worm",
            "Time Heals All Wounds", "The Calm Before The Storm",
        };
        int randIndex = rand() % phrases.size();
        puzzle = phrases[randIndex];
    } else if (choice == 4) {
        vector<string> song_lyrics = {
            "Let it be", "Here comes the sun", "Hey Jude", "Bohemian Rhapsody"
        };
        int randIndex = rand() % song_lyrics.size();
        puzzle = song_lyrics[randIndex];
    }

    cout << "Great! You've picked the category: " << choice << ", and your puzzle is ready!" << endl;
    return puzzle;
}

bool is_vowel(char letter) {
    letter = tolower(letter);
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

void buy_vowel(string& puzzle, const string& phrase, int& money) {
    if (money >= vowel_price) {
        char vowel;
        cout << "Enter a vowel to buy: ";
        while (!(cin >> vowel) || !isalpha(vowel) || !is_vowel(tolower(vowel))) {
            cout << "Invalid input. Please enter a vowel (a, e, i, o, u): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        money -= vowel_price;
        int occurrences = 0;
        for (int i = 0; i < puzzle.size(); i++) {
            if (tolower(phrase[i]) == tolower(vowel) && puzzle[i] == '_') {
                puzzle[i] = phrase[i];
                occurrences++;
            }
        }
        if (occurrences > 0) {
            cout << "You bought the vowel '" << vowel << "' and revealed " << occurrences << " letters." << endl;
        } else {
            cout << "The vowel '" << vowel << "' is not in the puzzle." << endl;
        }
    } else {
        cout << "You don't have enough money to buy a vowel." << endl;
    }
}

void guess_consonant(string& puzzle, const string& phrase, char letter, int paid_amount, int& money) {
    letter = tolower(letter);
    if (!isalpha(letter) || is_vowel(letter)) {
        cout << "You must guess a consonant." << endl;
        return;
    }

    int occurrences = 0;
    for (int i = 0; i < puzzle.length(); i++) {
        if (tolower(phrase[i]) == letter && puzzle[i] == '_') {
            puzzle[i] = phrase[i];
            occurrences++;
        }
    }

    if (occurrences > 0) {
        money += paid_amount * occurrences;
        cout << "You guessed a consonant! You get $" << (paid_amount * occurrences)
             << " for " << occurrences << " occurrence(s)." << endl;
    } else {
        money -= consonant_price;
        cout << "Oops, the letter is not in the puzzle. You lost $" << consonant_price << "." << endl;
    }
}

string winning_prizes() {
    vector<string> prizes = {
        "Trip to Hawaii", "New Car", "Shopping Spree", "Luxury Cruise",
        "Big Screen TV", "Cash Prize", "Dream Vacation", "Home Theater System"
    };
    int index = rand() % prizes.size();
    string random_prize = prizes[index];
    return random_prize;
}

bool string_iequal(const string& first, const string& second) {
    if (first.length() != second.length()) {
        return false;
    }
    for (size_t i = 0; i < first.length(); i++) {
        if (tolower(first[i]) != tolower(second[i])) {
            return false;
        }
    }
    return true;
}

bool is_game_over(const string& phrase, const string& guess, bool& win) {
    if (string_iequal(phrase, guess)) {
        cout << "YOU WIN!" << endl;
        win = true;
        return true;
    } else {
        if (phrase == puzzle) {
            cout << "Congratulations! You've solved the puzzle!" << endl;
            win = true;
            return true;
        } else if (money <= 0) {
            cout << "You have run out of money. Game over." << endl;
            win = false;
            return true;
        } else {
            win = false;
            return false;
        }
    }
}

void initialize_puzzle(string& puzzle, const string& phrase) {
    puzzle = phrase;
    for (int i = 0; i < puzzle.length(); i++) {
        string symbols = " ,\'.!?;";
        if (symbols.find(puzzle[i]) == string::npos) {
            puzzle[i] = '_';
        }
    }
}

int main() {
    srand(time(0));

    int paid_amount = spin_outcome();

    while (phrase.empty()) {
        phrase = pick_puzzle();
    }

    initialize_puzzle(puzzle, phrase);

    while (true) {
        cout << "\nYou have $" << money << "." << endl;
        cout << "Puzzle: " << puzzle << endl;

        int guess_type;
        cout << "Do you want to:\n1) Guess a consonant\n2) Buy a vowel\n3) Solve the puzzle\nEnter your choice: ";
        while (!(cin >> guess_type) || guess_type < 1 || guess_type > 3) {
            cout << "Invalid input. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        string guess;

        if (guess_type == 1) {
            char letter;
            cout << "Guess a consonant: ";
            while (!(cin >> letter) || !isalpha(letter) || is_vowel(tolower(letter))) {
                cout << "Invalid input. Please enter a consonant: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

            guess_consonant(puzzle, phrase, letter, paid_amount, money);
            guess = puzzle;
        } else if (guess_type == 2) {
            buy_vowel(puzzle, phrase, money);
            guess = puzzle;
        } else if (guess_type == 3) {
            cout << "Enter your solution: ";
            getline(cin, guess);
            cout << "You entered: " << guess << endl;
        }

        bool win = false;
        if (is_game_over(phrase, guess, win)) {
            if (win) {
                cout << "Congrats! You've won: " << winning_prizes() << "." << endl;
            } else {
                cout << "You've lost." << endl;
            }
            break;
        }
    }
    return 0;
}
