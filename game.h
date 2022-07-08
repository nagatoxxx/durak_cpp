#pragma once

#include <vector>
#include <stack>

enum Suit {clubs, diamonds, spades, hearts};
// clubs - крести
// diamonds - буби
// spades - пики
// hearts - черви

class Card {
    private:
        unsigned value; // значение карты
        Suit suit; // масть
        bool trump; // козырь ли
    public:
        Card(unsigned int v, Suit s) : value(v), suit(s), trump(false) {}
        bool is_trump();
        void make_trump();
        Suit get_suit();
        unsigned get_value();
        void show();
        bool operator == (Card _c) {
            if (_c.get_value() == value && _c.get_suit() == suit && _c.is_trump() == is_trump()) {
                return true;
            }
            return false;
        }

};

class Deck {
    private:
        Suit trump_suit;
        int number_of_cards; 
        std::vector<Card> cards;
    public:
        void fill();
        void shuffle();
        Card give();
};

class Player {
    private:
        unsigned card_amount; // количество карт в руке
        std::vector<Card> hand; // карты в руке
        bool attacker; // ходит ли игрок
    public:
        unsigned get_card_amount();
        std::vector<Card> get_hand();
        void add_card(Card _c);
        void attack(Card _c);
        void set_attacker();
        void show_hand();
        bool is_attacker();
        void set_defender();
};

class Game {
    private:
        std::vector<Card> bito; // бито
        Player attacker; // кто ходит
        int status; // статус игры
    public:
        std::stack<Card> cards_on_table;
        void cards_to_bito(Card _c);
        void set_attacker(Player _p);
        void add_card(Card _c);
        int get_status();
        void set_status(int s);
};
