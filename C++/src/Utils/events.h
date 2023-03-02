#pragma once

namespace events {

  bool checkBlackjack(Deck& deck, Hand& player, Hand& dealer);

  bool checkBust(Hand& player);

  bool hitOrStand(Deck& deck, Hand& player, Hand& dealer);

  void gameOver();

}
