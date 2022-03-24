#include "../solver.hpp"
#include <chrono>

// some tests involving the negamax algorithm

void test1() {
    std::cout << std::endl << "Test 1:" << std::endl;
    ConnectFour game;

    game = ConnectFour();
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(3);

    if (negamax(game, 13) == 18) {
        std::cout << "Test 1.1 passed!" << std::endl;
    } else {
        std::cout << "Test 1.1 failed!" << negamax(game, 13) << std::endl;
    };

    game = ConnectFour();
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(1);
    game.playColumn(0);


    if (negamax(game, 13) == 18) {
        std::cout << "Test 1.1 passed!" << std::endl;
    } else {
        std::cout << "Test 1.1 failed!" << negamax(game, 13) << std::endl;
    };
}


int main() {  
    test1();
    return 0;
}
