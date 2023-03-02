from blackjack import Card

values = { 'A':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, '10':10, 'J':10,'Q':10, 'K':10}

class Hand():
    
    def __init__(self):
        self.cards = []
        self.value = 0
        self.aces = 0

    def add_card(self, card: Card):
        self.cards.append(card)
        self.value += values[card.rank]
        # adjusting for ace
        if card.rank == 'A':
            self.aces += 1
        if self.aces == 1 and self.value == 11 and len(self.cards) == 2:
            self.value += 10

    def __str__(self) -> str:
        return f'{str(self.cards)}'

    def __sizeof__(self) -> int:
        return len(self.cards)
