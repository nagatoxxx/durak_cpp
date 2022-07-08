#include "game.h"
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <map>

Suit suits[4] = {diamonds, clubs, spades, hearts};

// карты
bool Card::is_trump() {
    return trump;
}

void Card::make_trump() {
    trump = true;
}

Suit Card::get_suit() {
    return suit;
}

unsigned Card::get_value() {
    return value;
}

void Card::show() {
    std::string su;
    char val;
    switch (suit) {
        case 0:
            su = "\u2667";
            break;
        case 1:
            su = "\u2662";
            break;
        case 2:
            su = "\u2664";
            break;
        case 3:
            su = "\u2661";
            break;
    }
    if (value > 10) {
        switch(value) {
            case 11:
                val = 'J';
                break;
            case 12:
                val = 'Q';
                break;
            case 13:
                val = 'K';
                break;
            case 14:
                val = 'A';
                break;
        }
        std::cout << val << " " << su;
    }
    else {
        std::cout << value << " " << su;
    }
}

// колода
void Deck::fill() {
    for (auto s : suits) {
        for (int v = 6; v <= 14; v++) {
            cards.push_back(Card(v, s));
            if (s == trump_suit) {
                cards.back().make_trump();
            }
        }
    }
}

void Deck::shuffle() {
    std::srand(time(NULL));
    int k;
    for (int i = 0; i < 36; i++) {
        k = rand() % 36;
        Card temp = cards[i];
        cards[i] = cards[k];
        cards[k] = temp;
    }
}

Card Deck::give() {
    Card _c = cards.back();
    cards.pop_back();
    return _c;
}

// игрок
unsigned Player::get_card_amount() {
    return card_amount;
}

std::vector<Card> Player::get_hand() {
    return hand;
}

void Player::add_card(Card _c) {
    hand.push_back(_c);
}

void Player::attack(Card _c) {
    std::vector<Card>::iterator it = std::find(hand.begin(), hand.end(), _c);
    hand.erase(it);
}

void Player::set_attacker() {
    attacker = true;
}

bool Player::is_attacker() {
    return attacker;
}

void Player::set_defender() {
    attacker = false;
}

// игра
void Game::cards_to_bito(Card _c) {
    bito.push_back(_c);
}

void Game::set_attacker(Player _p) {
    _p.set_attack();
    attacker = _p;
}

void Game::add_card(Card _c) {
    cards_on_table.push(_c);
}

int Game::get_status() {
    return status;
}

void Game::set_status(int _s) {
    status = _s;
}

// ----------------------------- //

void change_attacker(Game g, Player p1, Player p2) {
    if (p1.is_attacker()) {
        p1.set_attacker();
        p2.set_defender();
        g.set_attacker(p1);
    } 
    else {
        p1.set_defender();
        p2.set_attacker();
        g.set_attacker(p2);
    }
}


