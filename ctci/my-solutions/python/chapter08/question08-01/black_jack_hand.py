__author__ = 'dragan'

from hand import Hand


class BlackJackHand(Hand):
    def score(self):
        MIN_VALUE = -1000
        MAX_VALUE = 1000

        scores = self.possible_scores()

        max_under = MIN_VALUE
        min_over = MAX_VALUE

        for score in scores:
            if 21 < score < min_over:
                min_over = score
            elif max_under < score <= 21:
                max_under = score

        return min_over if max_under == MIN_VALUE else max_under

    def possible_scores(self):
        scores = []

        if len(self.cards) == 0:
            return scores

        for card in self.cards:
            self.add_card_to_score_list(card, scores)

        return scores

    @staticmethod
    def add_card_to_score_list(card, scores):
        if len(scores) == 0:
            scores.append(0)

        for i in range(len(scores)):
            score = scores[i]
            scores[i] = score + card.min_value()

            if card.min_value() != card.max_value():
                scores.append(score + card.max_value())

    def busted(self):
        return self.score() > 21

    def is21(self):
        return self.score == 21

    def is_black_jack(self):
        if len(self.cards) != 2:
            return False

        first = self.cards[0]
        second = self.cards[1]

        return (first.is_ace() and second.is_face_card()) or (second.is_ace() and first.is_face_card())
