// include solver.hpp file
#include "../solver.hpp"
#include <chrono>


void speedTest() {
    std::cout << std::endl << "TimmingTest:" << std::endl;
    const int DEPTH = 15;

    ConnectFour game = ConnectFour();

    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    analyze(game, DEPTH);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();    
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms" << std::endl;
}



int main() {  
    speedTest();
    return 0;
}