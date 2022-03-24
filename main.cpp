#include "solver.hpp"

int main() {
    ConnectFour game = ConnectFour();
    const int DEPTH = 13; 

    int move;
    while (true) {
        game.print();
        int value = negamax(game, DEPTH);
        std::cout << "Value: " << value << std::endl;
        std::string currentPlayer = game.currentPlayer() == 0 ? "Red" : "Yellow";
        std::cout << (game.currentPlayer() == 0 ? "Red player" : "Yellow player") << " enter move: ";
        std::cin >> move;
        game.playColumn(move);
    }
    
    return 0;
}