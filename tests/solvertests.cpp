#include "../solver.hpp"
#include <chrono>

// some tests involving the solver algorithms

void test1() {
    std::cout << std::endl << "Test 1:" << std::endl;
    ConnectFour game;

    game = ConnectFour();
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(3);

    if (solve(game, 13) == 18) {
        std::cout << "Test 1.1 passed!" << std::endl;
    } else {
        std::cout << "Test 1.1 failed!" << solve(game, 13) << std::endl;
    };
}


int main() {  
    test1();
    return 0;
}
