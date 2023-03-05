#include <cstdlib>
#include <iostream>
#include "Connect4/Connect4.h"
#include "ML/ML.h"


bool play() {
    std::cout << "play() passed\n";
    int input=0,turn=1;
    Connect4 game;
    std::cout << "Connect4 game passed\n";
    ML MLAgents;
    std::cout << "ML MLAgents(game) passed\n";

    do {

        std::cout << "game loop passed\n";
        if (game.FullBoard() == false) {
            do {

                game.DisplayBoard();
                std::cout << ("Player 1 Select between 1-7>>");
                //std::cin >> input;
                //input = 1 + (rand() % 6);

                input = MLAgents.ML_main(game);

            } while (game.PlayerDrop(input, game.PLAYER1) != true);

            std::cout << "Player 1 Selected " << input << std::endl;
            if (game.WinCheck(game.PLAYER1) == true) {
                std::cout << "\nPlayer 1 won.\n";
                game.SetWinner(1);

                break;
            }

        }

        if (game.FullBoard() == false) {

            do {
                game.DisplayBoard();
                std::cout << ("Player 2 Select between 1-7>>");

              //  input = MLAgents.ML_main(game); //
            } while (game.PlayerDrop(input, game.PLAYER2) != true);

            std::cout << "Player 2 Selected " << input << std::endl;
            if (game.WinCheck(game.PLAYER2) == true) {
                std::cout << "\nPlayer 2 won.\n";
               game.SetWinner(2);

                break;
            }

        }

    } while (game.FullBoard() == false);
   // game.DisplayBoard();
    MLAgents.OutputCSV(game);

    std::cout << "GAME OVER.\n";
//    sleep(10);
    return true;
}

int main() {

    bool InfiniteLoop=true;
    std::cout << " main() passed\n";
    while (InfiniteLoop == true) {
       InfiniteLoop = play();
    }
    return 0;
}

