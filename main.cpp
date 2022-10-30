#include <iostream>
#include "connectfour.hpp"

ConnectFour game = ConnectFour();

int main() {
    while (true) {
        unsigned int move;
        system("CLS"); // clear terminal
        game.print();

        if (game.isDraw()) {
            std::cout << "Game is a draw!" << std::endl;
            break;
        }        

        if (game.isWin()) {
            std::cout << (game.currentPlayer() == 1 ? "\u001b[31mRed\u001b[0m" : "\u001b[33mYellow\u001b[0m") << " player won!" << std::endl;
            break;
        }

        while (true) {
            std::cout << (game.currentPlayer() == 0 ? "\u001b[31mRed\u001b[0m" : "\u001b[33mYellow\u001b[0m") << " player enter move: ";
            std::cin >> move;
            if (game.isPlayable(move)) {
                game.makeMove(move);
                break;
            } else {
                std::cout << "\033[A" << "\33[2K"; // moves up a line and then deletes that line
                std::cout << "Move is not playable!" << '\n';
            }
        }
    }
    return 0;
}