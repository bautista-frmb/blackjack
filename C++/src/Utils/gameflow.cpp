#include "utils.h"

using namespace std;

namespace {
  string getWinner(Hand& player, Hand& dealer) {
    if (player.value > dealer.value) {
      points += 10;
      return "You win! (10 points)";
    }
    else if (player.value < dealer.value) {
      points -= 10;
      return "You lose! (-10 points)";
    }
    else {
      return "It's a draw. No points gained or lost.";
    }
  }
}

namespace gameflow {
  void play(Deck& deck, Hand& player, Hand& dealer) {
    while (true) {
      cout << endl << "Round " << roundNum << ". Your cards are: " << player.toString() <<endl;
      if (events::checkBlackjack(deck, player, dealer)) continue;
      if (events::checkBust(player)) break;
      if (events::hitOrStand(deck, player, dealer)) break;
      if (deck.getSize() < 10) {
        deck = Deck();
      }
    }
  }

  void startRound(Deck& deck, Hand& player, Hand& dealer) {
    player = Hand();
    dealer = Hand();
    deck.initialDeal(dealer, player);
  }

  void showResults(Hand& player, Hand& dealer) {
    cout << "Your cards are:" << endl << player.toString() << endl;
    cout << "Dealer's cards are:" << endl << dealer.toString() << endl;
    cout << getWinner(player, dealer) << endl;
  }

  void showHighScores() {
    highScores.show();
  }
}
