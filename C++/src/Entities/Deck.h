#pragma once

#include <algorithm>
#include <random>

using namespace std;

class Deck {
private:
  string ranks[13] = { "A", "2" ,"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
  string suits[4] = { "h", "d", "s", "c"};
  vector<Card> cards;

private:
  Card getTopOfDeck() {
    Card top = this->cards.back();
    this->cards.pop_back();
    return top;
  }

public:
  // Constructor
  Deck() {
    for (string rank : this->ranks) {
      for (string suit : this->suits) {
        this->cards.push_back(Card(rank, suit));
      }
    }
    this->shuffle();
  }

  // Methods
  void shuffle() {
    random_device rand;
    mt19937 engine(rand());
    std::shuffle(this->cards.begin(), this->cards.end(), engine);
  }

  void initialDeal(Hand& dealer, Hand& player) {
    player.addCard(this->getTopOfDeck());
    // player.addCard(Card("A", "h"));
    dealer.addCard(this->getTopOfDeck());
    player.addCard(this->getTopOfDeck());
    // player.addCard(Card("K", "s"));
    dealer.addCard(this->getTopOfDeck());
  }

  void deal(Hand& player) {
    player.addCard(this->getTopOfDeck());
  }

  int getSize() const {
    return this->cards.size();
  }

  string toString() {
    string result = "";
    for (int i = 0; i < this->cards.size(); i++) {
      result += this->cards[i].toString();
      if (i != this->cards.size() - 1) result += " ";
    }
    return result;
  }
};
