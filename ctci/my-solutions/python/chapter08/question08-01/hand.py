__author__ = 'dragan'


class Hand:
    def __init__(self):
        self.cards = []

    def score(self):
        score = 0
        for card in self.cards:
            score += card.value()

        return score

    def add_card(self, card):
        self.cards.append(card)

    def to_string(self):
        hand_as_string = ""
        for card in self.cards:
            hand_as_string = "{} {}".format(hand_as_string, card.to_string())
        return hand_as_string
