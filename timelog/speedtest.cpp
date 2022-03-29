// include solver.hpp file
#include "../solver.hpp"
#include <chrono>

void speedTest() {
    std::cout << std::endl << "TimmingTest:" << std::endl;
    const unsigned int DEPTH = 20;
    ConnectFour game;
    int value;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(2);
    game.playColumn(6);
    game.playColumn(0);
    game.playColumn(1);         
    value = solve(game, DEPTH);
    std::cout << "02601: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(1);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(1);
    value = solve(game, DEPTH);
    std::cout << "661661: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(5);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(4);
    game.playColumn(5);
    game.playColumn(1);
    game.playColumn(6);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(2);
    game.playColumn(1);
    value = solve(game, DEPTH);
    std::cout << "5032045164421: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(2);
    game.playColumn(1);
    game.playColumn(6);
    game.playColumn(4);
    game.playColumn(6);
    game.playColumn(5);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(3);
    game.playColumn(4);
    value = solve(game, DEPTH);
    std::cout << "021646503634: " << value << std::endl;
    
    game = ConnectFour();
    game.playColumn(2);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(5);
    game.playColumn(1);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(1);
    value = solve(game, DEPTH);
    std::cout << "2520365155201: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(3);
    game.playColumn(4);
    game.playColumn(6);
    game.playColumn(2);
    game.playColumn(6);
    game.playColumn(5);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(4);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(0);
    game.playColumn(4);
    value = solve(game, DEPTH);
    std::cout << "34626500346604: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(4);
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(3);
    value = solve(game, DEPTH);
    std::cout << "0003004101523: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(4);
    game.playColumn(3);
    game.playColumn(5);
    game.playColumn(3);
    game.playColumn(4);
    game.playColumn(6);
    game.playColumn(2);
    game.playColumn(1);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(3);
    value = solve(game, DEPTH);
    std::cout << "43534621233: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(2);
    game.playColumn(6);
    game.playColumn(0);
    value = solve(game, DEPTH);
    std::cout << "0052012236260: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(4);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(4);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(2);
    game.playColumn(5);
    value = solve(game, DEPTH);
    std::cout << "10143623433025: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(6);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(6);
    game.playColumn(1);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(4);
    game.playColumn(2);
    game.playColumn(5);
    value = solve(game, DEPTH);
    std::cout << "6200616610425: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(4);
    game.playColumn(6);
    game.playColumn(1);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(3);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(5);
    value = solve(game, DEPTH);
    std::cout << "46144303631115: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(3);
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(6);
    game.playColumn(3);
    game.playColumn(4);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(0);
    game.playColumn(3);
    value = solve(game, DEPTH);
    std::cout << "31016345533203: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(6);
    game.playColumn(4);
    game.playColumn(5);
    game.playColumn(0);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(4);
    game.playColumn(4);
    value = solve(game, DEPTH);
    std::cout << "6450230115244: " << value << std::endl;

    game = ConnectFour();
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(3);
    game.playColumn(0);
    game.playColumn(4);
    game.playColumn(2);
    game.playColumn(5);
    value = solve(game, DEPTH);
    std::cout << "32322300030425: " << value << std::endl;
    
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();    
    std::cout << "Time: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000.0) << " seconds" << std::endl;
}



int main() {  
    speedTest();
    return 0;
}
