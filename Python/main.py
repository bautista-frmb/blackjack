from getpass import getpass
from time import sleep

from blackjack import Hand, Deck
from high_scores import HighScores

name = ''
points: int = 0
high_scores = HighScores('High Scores.txt')

def start_round(deck: Deck, player: Hand, dealer: Hand):
    deck.initial_deal(player, dealer)

def show_results(player: Hand, dealer: Hand):
    print('\nYour cards are:\n', ''.ljust(3, ' '), *player.cards)
    print('Dealer’s cards are:\n', ''.ljust(3, ' '), *dealer.cards, '\n')
    if player.value > dealer.value:
        global points
        points += 10
        print('You win 10 points!\n')
    elif player.value < dealer.value:
        points -= 10
        print('You lose 10 points!\n')
    else:
        print("It's a draw. No points gained or lost.\n")
    for i in [3, 2, 1]:
        print(f'Next round in {i}', end='', flush=True)
        sleep(.250)
        for i in range(3):
            print('.', end='', flush=True)
            sleep(.250)
        print('', end='\r', flush=True)

def game_over():
    global points
    print(f"\n{name}’s Final Score: ", points, '\n')
    high_scores.update(name, points)
    points = 0

def play(deck: Deck, player: Hand, dealer: Hand):
    for i in [3, 2, 1]:
        print(f'Game starts in {i}', end='', flush=True)
        sleep(.250)
        for i in range(3):
            print('.', end='', flush=True)
            sleep(.250)
        print('', end='\r', flush=True)
    start_round(deck, player, dealer)
    is_game_over = False
    round_num = 1
    while not is_game_over:
        print(f'\nRound {round_num}. Your cards are:\n', ''.ljust(3, ' '), *player.cards, '\n\n')
        # Blackjack!
        if player.value == 21 and len(player.cards) == 2:
            global points
            points += 21
            print('You hit blackjack! (21 points)')
            player, dealer = Hand(), Hand()
            start_round(deck, player, dealer)
            round_num += 1
            continue
        # Player Bust!
        if player.value > 21:
            is_game_over = True
            print('You exceeded 21. Game over!\n\n')
            game_over()
            break
        # Hit or Stand
        print('[1] Stand        [3] End Game\n[2] Hit')
        match(input('Eter Choice: ')):
            case '1':
                show_results(player, dealer)
                player, dealer = Hand(), Hand()
                start_round(deck, player, dealer)
                round_num += 1
            case '2':
                deck.deal(player)
            case '3':
                print('Do you really want to end the game?')
                if input('Press Y for Yes, any key for No: ').lower() == 'y':
                    game_over()
                    break
            case _:
                print('\nInvalid choice. Please choose either "[1] Stand" or "[2] Hit" or "[3] End Game"\n')
        if deck.size() < 10: 
            deck = Deck()

def show_high_scores():
    print('\nHigh Scores')
    high_scores.show()
    getpass('')

if __name__ == '__main__':
    while len(name := input('Enter player name: ')) > 15:
        print('\nPlease enter a maximum of 15 characters\n')
    while True:
        print(f'\nWelcome to the game, {name}!\n')
        print('[1] Play        [3] Exit\n[2] High Scores')
        match(input('Eter Choice: ')):
            case '1':
                player, dealer = Hand(), Hand()
                deck = Deck()
                play(deck, player, dealer)
            case '2':
                show_high_scores()
            case '3':
                print('Do you really want to Exit?')
                if input('Press Y for Yes, any key for No: ').lower() == 'y':
                    exit()
            case _:
                print('\nInvalid choice. Please choose either "[1] Play" or "[2] High Scores" or "[3] Exit"\n')
