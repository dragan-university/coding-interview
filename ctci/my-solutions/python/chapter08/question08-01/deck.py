__author__ = 'dragan'

from random import randint


class Deck(object):
    def __init__(self, cards):
        self.cards = cards
        self._dealt_index = 0

    def shuffle(self):
        for i in range(len(self.cards)):
            j = randint(0, len(self.cards)-1)
        card1 = self.cards[i]
        card2 = self.cards[j]
        self.cards[i] = card2
        self.cards[j] = card1

    def remaining_cards(self):
        return len(self.cards) - self._dealt_index

    def deal_card(self):
        if self.remaining_cards() == 0:
            return None

        card = self.cards[self._dealt_index]
        card.mark_unavailable()
        self._dealt_index += 1

        return card

    def deal_hand(self, number):
        if self.remaining_cards() < number:
            return None

        hand = []
        count = 0
        while count < number:
            card = self.deal_card()

            if card:
                hand.append(card)
                count += 1

        return hand

    def show(self):
        for card in self.cards:
            card.show()
