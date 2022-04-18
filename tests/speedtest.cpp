// include solver.hpp file
#include "../solver.hpp"
#include <chrono>
#include <ctime>
Solver solver = Solver();
unsigned int totalTests = 0;
clock_t totalRunTime = 0;
struct TestResult {
    unsigned int testNumber;
    unsigned int nodesExplored;
    clock_t timeRequired;
    int valueExpected;
    int valueGot;
    bool passed() const {return valueGot == valueExpected; };
    TestResult(unsigned int testNumber, unsigned int nodesExplored, clock_t timeRequired, int valueExpected, int valueGot) :
        testNumber(testNumber), nodesExplored(nodesExplored), timeRequired(timeRequired), valueExpected(valueExpected), valueGot(valueGot) {};

    void print() {
        std::cout << "Test " << testNumber << " " << (passed() ? "\u001b[32mPASSED\u001b[0m" : "\u001b[31mFAILED\u001b[0m");
        std::cout << "; ";
        // std::cout << "Expected " << valueExpected << ", " << "got " << valueGot; std::cout << "; ";
        std::cout << "nodesExplored: " << nodesExplored;
        std::cout << "; ";
        std::cout << "timeRequired: " << (float)timeRequired / CLOCKS_PER_SEC;

        std::cout << std::endl;
    }
};


template <size_t N>
TestResult timmingTest(const unsigned int (&movesPayer)[N], const int valueExpected) {
    totalTests++;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { 
        game.playColumn(column); 
    };

    solver.reset();
    clock_t timeRequired = clock();
    int value = solver.solve(game);
    timeRequired = clock() - timeRequired;
    totalRunTime += timeRequired;
    
    return TestResult(totalTests, solver.nodesExplored, timeRequired, valueExpected, value);
}

void speedTest() {

    //timmingTest({0, 2, 6, 0, 1}, 3).print();
    //timmingTest({6, 6, 1, 6, 6, 1}, 4).print();
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 1}, 4).print();
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4}, -2).print(); //
    timmingTest({5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 2, 1, 0}, 3).print();
    timmingTest({0, 2, 1, 6, 4, 6, 5, 0, 3, 6, 3, 4}, -1).print();
    timmingTest({3, 4, 6, 2, 6, 5, 0, 0, 3, 4, 6, 6, 0, 4}, -6).print();
    timmingTest({2, 5, 2, 0, 3, 6, 5, 1, 5, 5, 2, 0, 1}, -6).print();
    timmingTest({0, 0, 0, 3, 0, 0, 4, 1, 0, 1, 5, 2, 3}, 1).print();
    timmingTest({4, 3, 5, 3, 4, 6, 2, 1, 2, 3, 3, 0}, 7).print();
    timmingTest({0, 0, 5, 2, 0, 1, 2, 2, 3, 6, 2, 6, 0}, -5).print();
    timmingTest({1, 0, 1, 4, 3, 6, 2, 3, 4, 3, 3, 0, 2, 5}, 4).print();
    timmingTest({6, 2, 0, 0, 6, 1, 6, 6, 1, 0, 4, 2, 5}, 7).print();
    timmingTest({4, 6, 1, 4, 4, 3, 0, 3, 6, 3, 1, 1, 1, 5}, -4).print();
    timmingTest({3, 1, 0, 1, 6, 3, 4, 5, 5, 3, 3, 2, 0, 3}, -7).print();
    timmingTest({6, 4, 5, 0, 2, 3, 0, 1, 1, 5, 2, 4, 4}, 8).print();
    timmingTest({3, 2, 3, 2, 2, 3, 0, 0, 0, 3, 0, 4, 2, 5}, 5).print();
    timmingTest({2, 2, 3, 3}, 18).print();
    timmingTest({4, 5, 1, 1, 4, 4, 1, 3, 3, 0, 2, 6, 6, 1, 1, 3, 3, 5, 3, 2, 5, 0, 0, 1, 5, 4, 4, 3, 6, 6, 5, 2, 2, 6, 0, 2, 6, 5, 2}, 0).print();
    timmingTest({1, 2, 1, 1, 1, 2, 2, 2, 2, 1, 6, 2, 4, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 1, 5}, -1).print();
    

    std::cout << std::endl << "Total run time: " << (float)totalRunTime / CLOCKS_PER_SEC << " s" << std::endl;

    
}



int main() {  
    speedTest();
    return 0;
}
