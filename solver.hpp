#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "connectfour.hpp"

const int columnOrder[ConnectFour::WIDTH] = {3, 2, 4, 1, 5, 0, 6};

int negamax(const ConnectFour &node, int alpha, int beta, int depth) {
    if (depth <= 0 || node.isDraw()) { return 0; }
 
    // if we do move prediction, we can return a positive value    
    if (node.isAlignment()) {
        return -((ConnectFour::WIDTH * ConnectFour::HEIGHT + 1 - node.moveCounter) / 2);
    } 

    if (node.isAlignment()) { return -1; }

    int value = -100;

    bitboard possible = node.possible();
    ConnectFour child;
    for (int i : columnOrder) { // could loop through moves
        bitboard move = possible & ConnectFour::columnMask(i);
        if (move == 0) { continue; } // if there is no bit in the move skip

        child = ConnectFour(node);
        child.play(move);
        
        value = std::max(value, -negamax(child, -beta, -alpha, depth - 1));
        alpha = std::max(alpha, value);
        if (alpha >= beta) { break; }
    }
    return value;
};


int negamax(const ConnectFour &node, int depth) {
    return negamax(node, -100, 100, depth);
};

#endif