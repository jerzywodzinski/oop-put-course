#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include "dr.h"


using namespace std;

Dice::Dice(int size){
    if (size < 2 || size>100)
        throw std::invalid_argument("Invalid dice size.");

    this->size = size;
}

int Dice::roll(){
    return rand() % size + 1;
}

Player::Player(const string& playerName) : name(playerName), score(0){}


string Player::Whatname() const {
    return name;
}

int Player::Whatscore() const{
    return score;
}

void Player::play(Dice& dice) {
    int rollResult = dice.roll();
    score += rollResult;
    cout <<name << " rolled: " << rollResult << endl;
}
Playerto15::Playerto15(const string& playerName) : Player(playerName){}

void Playerto15::play(Dice& dice) {
    if (score < 15) {
        Player::play(dice);
    }
    else {
        cout << name << " decides to skip the turn." << endl;
    }
}

Game::Game(const vector<Player*>& gamePlayers, int diceSize) : players(gamePlayers), dice(diceSize) {}

void Game::play() {
    for (int i = 1; i < 4; i++) {
        cout << "Round " << i << " begins" << endl;

        for (Player* player : players) {
            player->play(dice);
        }

        cout << "Round " << i << " ends" << endl << endl;
        _sleep(500);
    }

    int Maxscore = 0;
    vector<Player*> winners;
    for (Player* player : players) {
        if (player->Whatscore() > Maxscore) {
            Maxscore = player->Whatscore();
            winners.clear();
            winners.push_back(player);
        }
        else if (player->Whatscore() == Maxscore) {
            winners.push_back(player);
        }
    }

    if (winners.size() == 1) {
        cout << "The winner is: " << winners[0]->Whatname() << " with score: " << winners[0]->Whatscore() << endl;
    }
    else {
        cout << "It's a tie. The winners are:" << endl;
        for (Player* winner : winners)
        {
        cout << winner->Whatname() << " with score: " << winner->Whatscore() << endl;
        }
    }
}
