import random
from blackjack import Card, Hand

suits = ['h', 'd', 'c', 's']
ranks = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']

class Deck():

    def __init__(self):
        self.deck = []
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit, rank))
        self.shuffle()

    def shuffle(self) -> list:
        random.shuffle(self.deck)
        return self.deck

    def initial_deal(self, player: Hand, dealer: Hand):
        player.add_card(self.deck.pop())
        # player.add_card(Card("s", "A"))
        dealer.add_card(self.deck.pop())
        player.add_card(self.deck.pop())
        # player.add_card(Card("c", "J"))
        dealer.add_card(self.deck.pop())
            
    def deal(self, player: Hand):
        player.add_card(self.deck.pop())

    def size(self) -> int:
        return len(self.deck)
