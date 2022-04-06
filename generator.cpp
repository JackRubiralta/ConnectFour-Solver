#include "solver.hpp"
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

std::unordered_set<uint64_t> visitedNodes;
std::ofstream openingBookFile("book.txt");



int generate(const ConnectFour &node, const unsigned int depth) {
    if (depth == 0) {
        return solve(node, 10); // have 30 when using friend computer
    }

    if (node.isWin()) {
        return -(((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT + (int)1 -(int) node.moveCounter) / (int)2);;
    }

    ConnectFour child;
    int bestValue = -2147483647;
    for (int column = 0; column < ConnectFour::WIDTH; column++) {
        if (node.canPlayColumn(column)) {
            child = ConnectFour(node);
            child.playColumn(column);

            int value = -generate(child, depth - 1);
            bestValue = std::max(bestValue, value);
            
            bitboard key = child.hash(); 
            if (value != 0 && (visitedNodes.insert(key).second)) { // moveCounter + depth < 42
                openingBookFile << key << " " << -value << std::endl;
                // std::cout << key << " " << -value << std::endl;
            }
        }
    }

    // save to opening book
    return bestValue;

}


int main(int argc, const char** argv) {
    ConnectFour game = ConnectFour();   

    std::cout << generate(game, 6) << std::endl;
    return 0;
}