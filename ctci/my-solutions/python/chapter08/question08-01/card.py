__author__ = 'dragan'

from enum import Enum


class Suit(Enum):
    Club = 0
    Diamond = 1
    Heart = 2
    Spade = 3

    @staticmethod
    def to_string(suit):
        if suit == Suit.Club:
            return "C"
        if suit == Suit.Diamond:
            return "D"
        if suit == Suit.Heart:
            return "H"
        if suit == Suit.Spade:
            return "S"

    @staticmethod
    def to_string(suit):
        if suit == Suit.Club:
            return "C"
        if suit == Suit.Diamond:
            return "D"
        if suit == Suit.Heart:
            return "H"
        if suit == Suit.Spade:
            return "S"

    @staticmethod
    def values():
        return [Suit.Club, Suit.Diamond, Suit.Heart, Suit.Spade]
        #return [0, 1, 2, 3]


class Card(object):
    def __init__(self, face_value, suit):
        self.face_value = face_value
        self.suit = suit
        self.is_available = True

    def __str__(self):
        return self.to_string()

    def value(self):
        raise NotImplementedError()

    def mark_available(self):
        self.is_available = True

    def mark_unavailable(self):
        self.is_available = False

    def show(self):
        face_value = ("A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K")
        print(self.to_string())

    def to_string(self):
        face_value = ("A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K")
        return "{}{}".format(face_value[self.face_value-1], Suit.to_string(self.suit))
