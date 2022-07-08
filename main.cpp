#include <iostream>
#include "game.h"

int main() {
    Deck deck;
    deck.fill();
    deck.shuffle();
    Game durak;
    int game_status = 1;
    durak.set_status(game_status);
    Player players[2];

    while(durak.get_status()) {
        for (auto p : players) {
            while(p.get_card_amount() < 6) {
                p.add_card(deck.give());
            }
        }
    }

    return 0;
}
