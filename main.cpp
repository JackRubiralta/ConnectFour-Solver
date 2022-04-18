#include "solver.hpp"
int main() {
    ConnectFour game = ConnectFour();
    const unsigned int DEPTH = 18; 

    auto startClock = clock(); 
    auto runTime = clock();
    unsigned int move;
    int value;
    
    
    while (!game.isGameOver()) {
        game.print();
        nodesExplored = 0;
        startClock = clock(); 
        std::cout << "Computer thinking..." << std::endl;
        value = solve(game, 20);
        runTime = clock() - startClock;
        std::cout << "Time: " << (runTime) / (double)CLOCKS_PER_SEC << "s" << std::endl; 
        std::cout << "Nodes explored: " << nodesExplored << std::endl;
        std::cout << "Nodes per second: " << nodesExplored / (int)(runTime) << std::endl;
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