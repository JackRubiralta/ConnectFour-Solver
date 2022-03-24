#include "connectfour.hpp"

void test1() {
    std::cout << std::endl << "Test 1:" << std::endl;

    ConnectFour game;
    
    // Test 1.1
    game = ConnectFour();
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(4);
    if (game.yellow() == 2130176 && game.red() == 268452480) {
        std::cout << "Test 1.1 passed!" << std::endl;
    } else {
        std::cout << "Test 1.1 failed!" << std::endl;
    }

    // Test 1.2
    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(6);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(5);
    game.playColumn(4);
    game.playColumn(5);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    if (game.yellow() == 272974210 && game.red() == 4501128511493) {
        std::cout << "Test 1.2 passed!" << std::endl;
    } else {
        std::cout << "Test 1.2 failed!" << std::endl;
    }
    
    // Test 1.3
    ConnectFour game1 = ConnectFour();
    game1.playColumn(0);
    game1.playColumn(0);
    game1.playColumn(0);
    game1.playColumn(0);
    game1.playColumn(0);
    game1.playColumn(0);

    if (game1.yellow() == 42 && game1.red() == 21) {
        std::cout << "Test 1.3 passed!" << std::endl;
    } else {
        std::cout << "Test 1.3 failed!" << std::endl;
        std::cout << "red bitboard: " << game1.red() << std::endl;
        std::cout << "yellow bitboard: " << game1.yellow() << std::endl;
    }
}


void test2() {
    std::cout << std::endl << "Test 2:" << std::endl;
    
    ConnectFour game = ConnectFour();
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(0);

    if (!game.isAlignment()) {
        std::cout << "Test 2.1 passed!" << std::endl;
    } else {
        std::cout << "Test 2.1 failed!" << std::endl;
    };

    game.playColumn(1);
    if (game.isAlignment()) {
        std::cout << "Test 2.2 passed!" << std::endl;
    } else {
        std::cout << "Test 2.2 failed!" << std::endl;
    };

    
    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(2);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(5);
    game.playColumn(3);

    if (game.isAlignment()) {
        std::cout << "Test 2.3 passed!" << std::endl;
    } else {
        std::cout << "Test 2.3 failed!" << std::endl;
    };
}


void test3() {
    std::cout << std::endl << "Test 3:" << std::endl;

    if (ConnectFour::bottomMask == 0b0000001000000100000010000001000000100000010000001) {
        std::cout << "Test 3.1 passed!" << std::endl;
    } else {
        std::cout << "Test 3.1 failed!" << std::endl;
    };

    if (ConnectFour::boardMask == 0b0111111011111101111110111111011111101111110111111) {
        std::cout << "Test 3.2 passed!" << std::endl;
    } else {
        std::cout << "Test 3.2 failed!" << std::endl;
    };


    if (ConnectFour::columnMask(0) == 0b111111 && ConnectFour::columnMask(1) == 0b1111110000000 && ConnectFour::columnMask(2) == 0b11111100000000000000 && ConnectFour::columnMask(3) == 0b111111000000000000000000000 && ConnectFour::columnMask(4) == 0b1111110000000000000000000000000000 && ConnectFour::columnMask(5) == 0b11111100000000000000000000000000000000000 && ConnectFour::columnMask(6) == 0b111111000000000000000000000000000000000000000000) {
        std::cout << "Test 3.3 passed!" << std::endl;
    } else {
        std::cout << "Test 3.3 failed!" << std::endl;
    };
    
    if (ConnectFour::bottomColumnMask(0) == 0b000001) {
        std::cout << "Test 3.4 passed!" << std::endl;
    } else {
        std::cout << "Test 3.4 failed!" << std::endl;
    };
    
}


void test4() {
    std::cout << std::endl << "Test 4:" << std::endl;
    ConnectFour game;

    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
}

void test5() {
    std::cout << std::endl << "Test 5:" << std::endl;
    ConnectFour game;
    
    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(1);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(4);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(6);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(3);
    game.playColumn(6);

    if (game.isDraw()) {
        std::cout << "Test 5.1 passed!" << std::endl;
    } else {
        std::cout << "Test 5.1 failed!" << std::endl;
    };

    game = ConnectFour();
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(1);
    game.playColumn(5);
    if (!game.isDraw()) {
        std::cout << "Test 5.2 passed!" << std::endl;
    } else {
        std::cout << "Test 5.2 failed!" << std::endl;
    };
};

void test6() {
    std::cout << std::endl << "Test 6:" << std::endl;
    ConnectFour game;

    game = ConnectFour();
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);
    game.playColumn(5);

    game.playColumn(2);
    game.playColumn(2);
    game.playColumn(2);

    game.playColumn(3);

    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);
    game.playColumn(0);

    game.playColumn(1);
    game.playColumn(1);

    game.playColumn(4);
    game.playColumn(4);


    if (game.possible() == 4399124578848) {
        std::cout << "Test 6.1 passed!" << std::endl;
    } else {
        std::cout << "Test 6.1 failed!" << std::endl;
    };
}

int main() {  
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
};