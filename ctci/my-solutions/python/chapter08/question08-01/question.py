__author__ = 'dragan'

from black_jack_automator import BlackJackAutomator


def play():
    num_hands = 5

    automator = BlackJackAutomator(num_hands)
    automator.initialize_deck()
    success = automator.deal_initial()

    if not success:
        print("Error. Out of cards.")
        return

    print("-- Initial --")
    automator.print_hands_and_score()
    black_jacks = automator.get_black_jacks()

    if len(black_jacks) > 0:
        print("Blackjack at ")

        for i in black_jacks:
            print("{},".format(i))

        print("")
        return

    success = automator.play_all_hands()

    if not success:
        print("Error. Out of cards.")
        return

    print("-- Completed Game --")
    automator.print_hands_and_score()
    winners = automator.get_winners()

    if len(winners) > 0:
        print("Winners: ")

        for i in winners:
            print("{},".format(i))

        print("")
        return

    print("Draw. All players have busted.")


play()
