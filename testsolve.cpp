#include <iostream>
#include "solver.hpp"
#include <ctime>

clock_t totalRunTime = 0;

template <size_t N>
void timmingTest(const unsigned int (&movesPlayed)[N], const int valueExpected) {
    static unsigned int totalTestsRun = 0;
    totalTestsRun++;

    ConnectFour game = ConnectFour();

    for (unsigned int column : movesPlayed) { 
        game.makeMove(column + 1); 
    };

    nodesExplored = 0;
    clock_t timeRequired = clock();
    int value = solve(game);
    timeRequired = clock() - timeRequired;
    totalRunTime += timeRequired;
    
    std::cout << "Test " << totalTestsRun << " " << (value == valueExpected ? "\u001b[32mPASSED\u001b[0m" : "\u001b[31mFAILED\u001b[0m");
    std::cout << "; ";
    std::cout << "Expected " << valueExpected << ", " << "got " << value; std::cout << "; ";
    std::cout << "nodesExplored: " << nodesExplored;
    std::cout << "; ";
    std::cout << "timeRequired: " << (float)timeRequired / CLOCKS_PER_SEC;
    std::cout << std::endl;
}

void speedTest() {
    timmingTest({0, 2, 6, 0, 1}, 3);
    timmingTest({6, 6, 1, 6, 6, 1}, 4);
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 1}, 4);
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4}, -2); //
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 2, 1, 0}, 3);
    timmingTest({0, 2, 1, 6, 4, 6, 5, 0, 3, 6, 3, 4}, -1);
    timmingTest({3, 4, 6, 2, 6, 5, 0, 0, 3, 4, 6, 6, 0, 4}, -6);
    timmingTest({2, 5, 2, 0, 3, 6, 5, 1, 5, 5, 2, 0, 1}, -6);
    timmingTest({0, 0, 0, 3, 0, 0, 4, 1, 0, 1, 5, 2, 3}, 1);
    timmingTest({4, 3, 5, 3, 4, 6, 2, 1, 2, 3, 3, 0}, 7);
    timmingTest({0, 0, 5, 2, 0, 1, 2, 2, 3, 6, 2, 6, 0}, -5);
    timmingTest({1, 0, 1, 4, 3, 6, 2, 3, 4, 3, 3, 0, 2, 5}, 4);
    timmingTest({6, 2, 0, 0, 6, 1, 6, 6, 1, 0, 4, 2, 5}, 7);
    timmingTest({4, 6, 1, 4, 4, 3, 0, 3, 6, 3, 1, 1, 1, 5}, -4);
    timmingTest({3, 1, 0, 1, 6, 3, 4, 5, 5, 3, 3, 2, 0, 3}, -7);
    timmingTest({6, 4, 5, 0, 2, 3, 0, 1, 1, 5, 2, 4, 4}, 8);
    timmingTest({3, 2, 3, 2, 2, 3, 0, 0, 0, 3, 0, 4, 2, 5}, 5);
    timmingTest({2, 2, 3, 3}, 18);
    timmingTest({4, 5, 1, 1, 4, 4, 1, 3, 3, 0, 2, 6, 6, 1, 1, 3, 3, 5, 3, 2, 5, 0, 0, 1, 5, 4, 4, 3, 6, 6, 5, 2, 2, 6, 0, 2, 6, 5, 2}, 0);
    timmingTest({1, 2, 1, 1, 1, 2, 2, 2, 2, 1, 6, 2, 4, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 1, 5}, -1);
    std::cout << std::endl << "Total run time: " << (float)totalRunTime / CLOCKS_PER_SEC << " s" << std::endl;
}

void finalTest() { // from the beggining of the game 
    int valueExpected = 1;
    ConnectFour game = ConnectFour();

    nodesExplored = 0;
    clock_t timeRequired = clock();
    int value = solve(game);
    timeRequired = clock() - timeRequired;
    totalRunTime += timeRequired;
    
    std::cout << "Test " << "final" << " " << (value == valueExpected ? "\u001b[32mPASSED\u001b[0m" : "\u001b[31mFAILED\u001b[0m");
    std::cout << "; ";
    std::cout << "Expected " << valueExpected << ", " << "got " << value; std::cout << "; ";
    std::cout << "nodesExplored: " << nodesExplored;
    std::cout << "; ";
    std::cout << "timeRequired: " << (float)timeRequired / CLOCKS_PER_SEC;
    std::cout << std::endl;
}

int main() {  
    //finalTest();
    //speedTest();
    return 0;
}
