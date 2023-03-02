#include "utils.h"

using namespace std;

namespace events {

  bool checkBlackjack(Deck& deck, Hand& player, Hand& dealer) {
    if (player.value == 21 && player.getSize() == 2) {
      cout << "You hit blackjack! (21 points)" << endl;
      points += 21;
      gameflow::startRound(deck, player, dealer);
      roundNum++;
      return true;
    }
    return false;
  }

  bool checkBust(Hand& player) {
    if (player.value > 21) {
      cout << "You exceeded 21. Game over!" << endl;
      events::gameOver();
      return true;
    }
    return false;
  }

  bool hitOrStand(Deck& deck, Hand& player, Hand& dealer) {
    cout << "[1] Stand        [3] End Game\n[2] Hit" << endl;
    cout << "Enter Choice: ";
    char choice;
    cin >> choice;
    switch (choice) {
      case '1':
        gameflow::showResults(player, dealer);
        gameflow::startRound(deck, player, dealer);
        roundNum++;
        break;

      case '2':
        deck.deal(player);
        break;

      case '3':
        char exitChoice;
        cout << "Do you really want to end the game? [Y/n]: ";
        cin >> exitChoice;
        if (tolower(exitChoice) == 'y') {
          events::gameOver();
          return true;
        }
        break;

      default: cout << "\nInvalid choice. Please choose either \"[1] Stand\" or \"[2] Hit\" or \"[3] End Game\"\n" << endl;
        break;
    }
    return false;
  }

  void gameOver() {
    cout << name << "'s final score: " << points << endl;
    highScores.update(name, points);
    points = 0;
    roundNum = 0;
  }
  
}
