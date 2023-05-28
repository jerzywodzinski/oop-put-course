#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include "dr.h"

using namespace std;

int main()
{

    srand(time(NULL));

    try{
        Player player1("John");
        Playerto15 player2("Frank");
        Player player3("Alice");
        vector <Player*> players = {&player1, &player2, &player3};
        Game game(players, 10);
        game.play();
    } catch (const std::exception& e){
        std::cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
