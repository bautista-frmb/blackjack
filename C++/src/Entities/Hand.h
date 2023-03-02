#pragma once

#include <map>

using namespace std;

class Hand {
private:
  map<string, int> values = { {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 10}, {"Q", 10}, {"K", 10} };
  int aces = 0;
  vector<Card> cards;

public:
  int value = 0;

public:
  // Methods
  void addCard(Card card) {
    this->cards.insert(cards.end(), card);
    this->value += values[card.rank];

    // adjust for ace
    if (card.rank == "A") this->aces += 1;
    if (this->aces == 1 && this->value == 11 && this->cards.size() == 2) {
      this->value += 10;
    }
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

