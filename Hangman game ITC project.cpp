#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TRIES = 6;
const char word[] = "hangman"; // 7 letters
const int WORD_LENGTH = 7;     // Must match actual word length

char toLowerChar(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

int main() {
    char guessed[WORD_LENGTH + 1]; // Size must be a constant expression
    for (int i = 0; i < WORD_LENGTH; ++i) {
        guessed[i] = '_';
    }
    guessed[WORD_LENGTH] = '\0';

    char letter;
    int incorrectGuesses = 0;

    while (incorrectGuesses < MAX_TRIES) {
        cout << "Current State: " << guessed << endl;
        cout << "Incorrect Guesses Remaining: " << (MAX_TRIES - incorrectGuesses) << endl;
        cout << "------------------------------------" << endl;

        cout << "Enter a letter: ";
        cin >> letter;
        letter = toLowerChar(letter);

        bool found = false;
        bool alreadyGuessed = false;

        for (int i = 0; i < WORD_LENGTH; ++i) {
            if (word[i] == letter && guessed[i] == letter) {
                alreadyGuessed = true;
            }
            if (word[i] == letter && guessed[i] == '_') {
                guessed[i] = letter;
                found = true;
            }
        }

        if (alreadyGuessed) {
            cout << "You already guessed that letter correctly. Try a different one.\n";
        }
        else if (!found) {
            ++incorrectGuesses;
            cout << "Wrong guess!\n";
        }

        if (strcmp(word, guessed) == 0) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            break;
        }
    }

    if (incorrectGuesses == MAX_TRIES) {
        cout << "Sorry, you ran out of attempts. The word was: " << word << endl;
    }

    return 0;
}
