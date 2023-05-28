#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

class Dice{
    int size;

public:
    Dice(int size = 6);
    virtual int roll();
};

class Player {
protected:
    string name;
    int score;

public:
    Player(const string& playerName = "Player");

    string Whatname() const;
    int Whatscore() const;
    virtual void play(Dice& dice);
};

class Playerto15 : public Player {
public:
    Playerto15(const string& playerName = "Player");

    void play(Dice& dice) override;
};

class Game {
    vector<Player*> players;
    Dice dice;

public:
    Game(const vector<Player*>& gamePlayers, int diceSize = 6);
    void play();
};
