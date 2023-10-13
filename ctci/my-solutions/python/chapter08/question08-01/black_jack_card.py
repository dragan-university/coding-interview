__author__ = 'dragan'

from card import Card


class BlackJackCard(Card):
    def __init__(self, face_value, suit):
        super(BlackJackCard, self).__init__(face_value, suit)

    def value(self):
        if self.is_ace():
            return 1
        elif self.is_face_card():
            return 10
        else:
            return self.face_value

    def is_ace(self):
        return self.face_value == 1

    def is_face_card(self):
        return (self.face_value >= 11) and (self.face_value <= 13)

    def min_value(self):
        if self.is_ace():
            return 1
        else:
            return self.value()

    def max_value(self):
        if self.is_ace():
            return 11
        else:
            return self.value()