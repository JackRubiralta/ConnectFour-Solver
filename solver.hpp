#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "connectfour.hpp"

const int columnOrder[ConnectFour::WIDTH] = {3, 2, 4, 1, 5, 0, 6};

int negamax(const ConnectFour &node, int alpha, int beta, int depth) {
    bitboard possible = node.possibleNonLosingMoves();

    if (possible == 0) { return -((ConnectFour::WIDTH * ConnectFour::HEIGHT - node.moveCounter) / 2); }
    if (depth <= 0 || node.isDraw()) { return 0; }

    int value = -2147483647;
    ConnectFour child;
    for (int i : columnOrder) { 
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


int analyze(const ConnectFour &node, int depth) {
    if (node.canWinNext()) {
        return (ConnectFour::WIDTH * ConnectFour::HEIGHT + 1 - node.moveCounter) / 2;
    }
    return negamax(node, -2147483647, 2147483647, depth);
};

// auto fil by github copilot to get the best move
int solve(const ConnectFour &node, int depth) {
    bitboard possible = node.possible();
    if (possible == 0) { return -((ConnectFour::WIDTH * ConnectFour::HEIGHT - node.moveCounter) / 2); }
    if (depth <= 0 || node.isDraw()) { return 0; }

    int value = -2147483647;
    ConnectFour child;
    for (int i : columnOrder) { 
        bitboard move = possible & ConnectFour::columnMask(i);

        child = ConnectFour(node);
        child.play(move);
        
        value = std::max(value, -solve(child, depth - 1));
    }
    return value;
};


#endif