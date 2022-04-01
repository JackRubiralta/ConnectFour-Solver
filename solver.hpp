#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "connectfour.hpp"
#include <time.h>

// https://www.ics.uci.edu/~eppstein/180a/990202b.html
constexpr int columnOrder[ConnectFour::WIDTH] = {3, 2, 4, 1, 5, 0, 6};
unsigned int nodesExplored;

unsigned int bestDepth(unsigned int moveCounter) {
    const unsigned int counterToDepth[42] = {15, 15, 18, 18, 19, 19, 20, 20, 22, 22, 24, 24, 25, 25, 27, 27, 30, 30, 33, 33, 35, 37, 37, 40, 40, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    return counterToDepth[moveCounter];
};

// might have max and min values for value = -42 ect
int negamax(const ConnectFour &node, int alpha, int beta, unsigned int depth) {
    if (depth <= 0) { return 0; }
    nodesExplored++;

    bitboard possible = node.possibleNonLosingMoves();
    if (possible == 0) { return -(((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT -(int) node.moveCounter) / (int)2); }
    if (node.isDraw()) { return 0; }

    const int min = -((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT - (int)2 - (int)node.moveCounter) / (int)2;	// lower bound of score as opponent cannot win next move
    if (alpha < min) {
        alpha = min;                     // there is no need to keep alpha below our max possible score.
        if(alpha >= beta) return alpha;  // prune the exploration if the [alpha;beta] window is empty.
    }

    const int max = ((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT - (int)1 - (int)node.moveCounter) / (int)2;	// upper bound of our score as we cannot win immediately
    if (beta > max) {
        beta = max;                     // there is no need to keep beta above our max possible score.
        if (alpha >= beta) return beta;  // prune the exploration if the [alpha;beta] window is empty.
    }
    
    int value = -2147483647;
    ConnectFour child;
    for (int column : columnOrder) { 
        bitboard move = possible & ConnectFour::columnMask(column);
        if (move == 0) { continue; } // if there is no bit in the move skip

        child = ConnectFour(node);
        child.play(move);
        
        value = std::max(value, -negamax(child, -beta, -alpha, depth - 1));
        alpha = std::max(alpha, value);
        if (alpha >= beta) { break; }
    }
    return value;
};

int solve(const ConnectFour &root, unsigned int depth) {
    if (root.canWinNext()) {
        return ((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT + (int)1 - (int)root.moveCounter) / (int)2;
    }
  
    int value = negamax(root, -2147483647, 2147483647, depth);
    return value;
};


// might return a array of scores 
unsigned int analyze(ConnectFour &root, unsigned int depth) {
    bitboard possible = root.possible();
    int bestValue = -2147483647;
    int value;
    unsigned int bestColumn;
    ConnectFour node;
    
    for (int column : columnOrder) { 
        bitboard move = possible & ConnectFour::columnMask(column);
        if (move == 0) { continue; } // if there is no bit in the move skip
        
        node = ConnectFour(root);
        node.play(move);
        if (node.isWin()) { return column; }
        value = -solve(node, depth - 1);
        
        if (value > bestValue) {
            bestValue = value;
            bestColumn = column;
        }
    }
    std::cout << "bestValue: " << bestValue << std::endl; 
    return bestColumn;
};

#endif