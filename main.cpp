#include "solver.hpp"

int main() {
    ConnectFour game = ConnectFour();
    const int DEPTH = 18; 

    int move;
    while (!game.isGameOver()) {
        game.print();
        int value = analyze(game, DEPTH);
        std::cout << "Value: " << value << std::endl;
        std::string currentPlayer = game.currentPlayer() == 0 ? "Red" : "Yellow";
        std::cout << (game.currentPlayer() == 0 ? "Red player" : "Yellow player") << " enter move: ";
        std::cin >> move;
        game.playColumn(move);
    }
    game.print();
    std::cout << "Game over!" << std::endl;
    
    return 0;
}