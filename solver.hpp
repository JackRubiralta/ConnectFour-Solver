#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "connectfour.hpp"

constexpr int columnOrder[ConnectFour::WIDTH] = {3, 2, 4, 1, 5, 0, 6};

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

int analyze(const ConnectFour &node, int alpha, int beta, int depth) {
    if (node.canWinNext()) {
        return (ConnectFour::WIDTH * ConnectFour::HEIGHT + 1 - node.moveCounter) / 2;
    }
    return negamax(node, alpha, beta, depth);
};

int MTDF(ConnectFour root, int f, unsigned int depth) {
    int guess = f;
    int upperBound = +2147483647;
    int  lowerBound = -2147483647;
    int beta;
    
    while (lowerBound < upperBound) {
        beta = std::max(guess, lowerBound + 1);
        guess = analyze(root, beta - 1, beta, depth);
        if (guess < beta) {
            upperBound = guess;
        } else {
            lowerBound = guess;
        }
    }
    return guess;
}

int analyze(const ConnectFour &node, int depth) {
    if (node.canWinNext()) {
        return (ConnectFour::WIDTH * ConnectFour::HEIGHT + 1 - node.moveCounter) / 2;
    }
    return negamax(node, -2147483647, 2147483647, depth);
};


// find the best move as a column for the current player
unsigned int solve(const ConnectFour &node, int depth) {};


#endif