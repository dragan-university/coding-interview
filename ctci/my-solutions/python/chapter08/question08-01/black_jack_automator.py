__author__ = 'dragan'

from card import Suit
from deck import Deck
from black_jack_card import BlackJackCard
from black_jack_hand import BlackJackHand


class BlackJackAutomator:
    HIT_UNTIL = 16

    def __init__(self, num_players):
        self._deck = None
        self.hands = []

        for i in range(num_players):
            self.hands.append(BlackJackHand())

    def deal_initial(self):
        for hand in self.hands:
            card1 = self._deck.deal_card()
            card2 = self._deck.deal_card()
            if card1 is None or card2 is None:
                return False

            hand.add_card(card1)
            hand.add_card(card2)

        return True

    def get_black_jacks(self):
        winners = []

        for i in range(len(self.hands)):
            if self.hands[i].is_black_jack():
                winners.append(i)

        return winners

    def play_hand(self, hand):
        while hand.score() < BlackJackAutomator.HIT_UNTIL:
            card = self._deck.deal_card()
            if card is None:
                return False

            hand.add_card(card)

        return True

    def play_all_hands(self):
        for hand in self.hands:
            if not self.play_hand(hand):
                return False

        return True

    def get_winners(self):
        winners = []
        winning_score = 0

        for i in range(len(self.hands)):
            hand = self.hands[i]
            if not hand.busted():
                if hand.score() > winning_score:
                    winning_score = hand.score()
                    winners = list()
                    winners.append(i)
                elif hand.score() == winning_score:
                    winners.append(i)

        return winners

    def initialize_deck(self):
        cards = []
        for i in range(1, 14):
            for j in Suit.values():
                card = BlackJackCard(i, j)
                cards.append(card)

        self._deck = Deck(cards)
        self._deck.shuffle()

    def print_hands_and_score(self):
        for i in range(len(self.hands)):
            print("Hand {} ({}-{}):".format(i, self.hands[i].score(), len(self.hands[i].cards)))
            print(self.hands[i].to_string())
            print("")
