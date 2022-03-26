// include solver.hpp file
#include "../solver.hpp"
#include <chrono>
#include <string>

void speedTest() {
    std::cout << std::endl << "TimmingTest:" << std::endl;
    const int DEPTH = 22;
    ConnectFour game;
    int value;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    game = ConnectFour("02601");
    value = analyze(game, DEPTH);
    std::cout << "02601: " << value << std::endl;

    game = ConnectFour("661661");
    value = analyze(game, DEPTH);
    std::cout << "661661: " << value << std::endl;

    game = ConnectFour("5032045164421");
    value = analyze(game, DEPTH);
    std::cout << "5032045164421: " << value << std::endl;

    game = ConnectFour("021646503634");
    value = analyze(game, DEPTH);
    std::cout << "021646503634: " << value << std::endl;

    game = ConnectFour("2520365155201");
    value = analyze(game, DEPTH);
    std::cout << "2520365155201: " << value << std::endl;

    game = ConnectFour("2520365155201");
    value = analyze(game, DEPTH);
    std::cout << "2520365155201: " << value << std::endl;

    game = ConnectFour("34626500346604");
    value = analyze(game, DEPTH);
    std::cout << "34626500346604: " << value << std::endl;

    game = ConnectFour("0003004101523");
    value = analyze(game, DEPTH);
    std::cout << "0003004101523: " << value << std::endl;

    game = ConnectFour("43534621233");
    value = analyze(game, DEPTH);
    std::cout << "43534621233: " << value << std::endl;

    game = ConnectFour("0052012236260");
    value = analyze(game, DEPTH);
    std::cout << "0052012236260: " << value << std::endl;

    game = ConnectFour("10143623433025");
    value = analyze(game, DEPTH);
    std::cout << "10143623433025: " << value << std::endl;

    game = ConnectFour("6200616610425");
    value = analyze(game, DEPTH);
    std::cout << "6200616610425: " << value << std::endl;

    game = ConnectFour("46144303631115");
    value = analyze(game, DEPTH);
    std::cout << "46144303631115: " << value << std::endl;

    game = ConnectFour("31016345533203");
    value = analyze(game, DEPTH);
    std::cout << "31016345533203: " << value << std::endl;

    game = ConnectFour("6450230115244");
    value = analyze(game, DEPTH);
    std::cout << "6450230115244: " << value << std::endl;

    game = ConnectFour("32322300030425");
    value = analyze(game, DEPTH);
    std::cout << "32322300030425: " << value << std::endl;



    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();    
    std::cout << "Time: " << (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() / 1000.0) << " seconds" << std::endl;
}



int main() {  
    speedTest();
    return 0;
}