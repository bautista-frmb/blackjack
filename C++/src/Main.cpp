#include <iostream>

#include "utils.h"

using namespace std;

HighScores highScores("res/HighScores.txt");
string name;
int points = 0;
int roundNum = 1;

int main() {
  bool isNameValid = false;
  while (!isNameValid) {
    cout << "Enter a name: ";
    cin >> name;
    if (name.length() > 8) {
      cout << "Name is too long, max 8 characters";
    } else isNameValid = true;
  }

  bool exited = false;
  while (!exited) {
    Deck deck;
    Hand player, dealer;
    cout << endl << "Welcome to the game, " << name << "!" << endl;
    cout << "[1] Play        [3] Exit\n[2] High Scores" << endl;
    cout << "Enter Choice: ";
    char choice;
    cin >> choice;
    switch (choice) {
      case '1':
        deck.initialDeal(dealer, player);
        gameflow::play(deck, player, dealer);
        break;
      case '2':
        gameflow::showHighScores();
        break;
      case '3':
        char exitChoice;
        cout << "Do you really want to exit? [Y/n]: ";
        cin >> exitChoice;
        if (tolower(exitChoice) == 'y') exited = true;
        break;
      default: cout << "\nInvalid choice. Please choose either \"[1] Play\" or \"[2] High Scores\" or \"[3] Exit\"\n" << endl;
        break;
    }
  }

  return 0;
}
