// include solver.hpp file
#include "../solver.hpp"
#include <chrono>
#include <ctime>

clock_t timmingTest1() {
    const unsigned int movesPayer[5] = {0, 2, 6, 0, 1};
    const int valueExpected = 3;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    
    nodesExplored = 0;
    clock_t timeRequired = clock();
    int value = solve(game, 34);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 01 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}


clock_t timmingTest2() {
    const unsigned int movesPayer[6] = {6, 6, 1, 6, 6, 1};
    const int valueExpected = 4;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 29);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 02 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest3() {
    const unsigned int movesPayer[13] = {5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 1};
    const int valueExpected = 12;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 22);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 03 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest4() {
    const unsigned int movesPayer[14] = {5, 0, 3, 2, 0, 4, 5, 1, 6, 4, 4, 2, 1, 0};
    const int valueExpected = 3;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 27);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 04 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest5() {
    const unsigned int movesPayer[12] = {0, 2, 1, 6, 4, 6, 5, 0, 3, 6, 3, 4};
    const int valueExpected = -1;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 29);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 05 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest6() {
    const unsigned int movesPayer[14] = {3, 4, 6, 2, 6, 5, 0, 0, 3, 4, 6, 6, 0, 4};
    const int valueExpected = -6;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 06 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest7() {
    const unsigned int movesPayer[13] = {2, 5, 2, 0, 3, 6, 5, 1, 5, 5, 2, 0, 1};
    const int valueExpected = -6;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 07 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest8() {
    const unsigned int movesPayer[13] = {0, 0, 0, 3, 0, 0, 4, 1, 0, 1, 5, 2, 3};
    const int valueExpected = 1;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 28);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 08 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest9() {
    const unsigned int movesPayer[12] = {4, 3, 5, 3, 4, 6, 2, 1, 2, 3, 3, 0};
    const int valueExpected = 7;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;
    
    clock_t timeRequired = clock();
    int value = solve(game, 25);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 09 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "failed") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest10() {
    const unsigned int movesPayer[13] = {0, 0, 5, 2, 0, 1, 2, 2, 3, 6, 2, 6, 0};
    const int valueExpected = -5;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 10 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest11() {
    const unsigned int movesPayer[14] = {1, 0, 1, 4, 3, 6, 2, 3, 4, 3, 3, 0, 2, 5};
    const int valueExpected = 4;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 11 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}


clock_t timmingTest12() {
    const unsigned int movesPayer[13] = {6, 2, 0, 0, 6, 1, 6, 6, 1, 0, 4, 2, 5};
    const int valueExpected = 7;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 12 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}


clock_t timmingTest13() {
    const unsigned int movesPayer[14] = {4, 6, 1, 4, 4, 3, 0, 3, 6, 3, 1, 1, 1, 5};
    const int valueExpected = -4;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 25);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 13 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest14() {
    const unsigned int movesPayer[14] = {3, 1, 0, 1, 6, 3, 4, 5, 5, 3, 3, 2, 0, 3};
    const int valueExpected = -7;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 14 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest15() {
    const unsigned int movesPayer[13] = {6, 4, 5, 0, 2, 3, 0, 1, 1, 5, 2, 4, 4};
    const int valueExpected = 8;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 15 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest16() {
    const unsigned int movesPayer[14] = {3, 2, 3, 2, 2, 3, 0, 0, 0, 3, 0, 4, 2, 5};
    const int valueExpected = 5;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;
    
    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 16 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}

clock_t timmingTest17() {
    const unsigned int movesPayer[4] = {2, 2, 3, 3};
    const int valueExpected = 18;
    ConnectFour game = ConnectFour();
    for (unsigned int column : movesPayer) { game.playColumn(column); };
    nodesExplored = 0;

    clock_t timeRequired = clock();
    int value = solve(game, 20);
    timeRequired = clock() - timeRequired;
    std::cout << std::endl << "Timming Test 17 " << (value == valueExpected ? "\u001b[32mpassed\u001b[0m" : "\u001b[31mfailed\u001b[0m") << ": " << "expected " << valueExpected << ", " << "got " << value << std::endl << "Node Explored: " << nodesExplored << std::endl;
    return timeRequired;
}
void speedTest() {
    clock_t totalRunTime = 0;
    totalRunTime += timmingTest1();
    totalRunTime += timmingTest2();
    totalRunTime += timmingTest3();
    totalRunTime += timmingTest4();
    totalRunTime += timmingTest5();
    totalRunTime += timmingTest6();
    totalRunTime += timmingTest7();
    totalRunTime += timmingTest8();
    totalRunTime += timmingTest9();
    totalRunTime += timmingTest10();
    totalRunTime += timmingTest11();
    totalRunTime += timmingTest12();
    totalRunTime += timmingTest13();
    totalRunTime += timmingTest14();
    totalRunTime += timmingTest15();
    totalRunTime += timmingTest16();
    totalRunTime += timmingTest17();
    

    std::cout << std::endl << "Total run time: " << (float)totalRunTime / CLOCKS_PER_SEC << " s" << std::endl;

    
}



int main() {  
    speedTest();
    return 0;
}
