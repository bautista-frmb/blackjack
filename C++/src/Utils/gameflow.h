# pragma once

namespace gameflow {

  void play(Deck& deck, Hand& player, Hand& dealer);

  void startRound(Deck& deck, Hand& player, Hand& dealer);

  void showResults(Hand& player, Hand& dealer);

  void showHighScores();
  
}
