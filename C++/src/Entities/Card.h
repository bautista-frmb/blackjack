#pragma once

using namespace std;

class Card {
public:
  string rank, suit;

public:
  // Constructor
  Card(const string& rank, const string& suit) {
    this->rank = rank;
    this->suit = suit;
  }

  // Methods
  string toString() {
    return this->rank + this->suit;
  }
};
