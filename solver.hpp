#ifndef SOLVER_HPP
#define SOLVER_HPP

// From https://stackoverflow.com/a/10602957 and https://stackoverflow.com/q/27778908
#define private public
#include "connectfour.hpp"
#undef private

enum Flag : uint8_t { INVALID, EXACT, LOWERBOUND, UPPERBOUND };
struct Entry {
    int8_t value;
    Flag flag;
    Entry() : value(0), flag(INVALID) {}
    Entry(int8_t value, Flag flag) : value(value), flag(flag) {}
};
struct {
    unsigned int size = 100000000;
    Entry *entries = new Entry[size];
    ConnectFour::bitboard *keys = new ConnectFour::bitboard[size];
    unsigned int index(ConnectFour::bitboard key) { return key % size; }
    void insert(ConnectFour::bitboard key, Entry entry) {
        unsigned int pos = index(key);
        keys[pos] = key; entries[pos] = entry;
    }
    Entry lookup(ConnectFour::bitboard key) {
        unsigned int pos = index(key);
        if (keys[pos] == key) { return entries[pos];
        } else { return Entry(); }
    }
} table;

const unsigned int columnOrder[ConnectFour::WIDTH] = {4, 3, 5, 2, 6, 1, 7}; 

unsigned int nodesExplored = 0;

int negamax(const ConnectFour &node, int alpha, int beta) {
    nodesExplored++;

    // generate all of the possible non losing moves
    // might have return a array pointer just bc I am like that
    ConnectFour::bitboard possible = node.possibleNonLosingMoves();

    // if there are no possible moves, return the value of the node
    if (possible == 0) { return -(((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT -(int)node.counter) / (int)2); }
    
    // check if there is a draw and if so, return 0
    if (node.isDraw()) { return 0; }

    // save the original alpha value to be used later
    const int alphaOriginal = alpha;
    
    // lookup the value of the node in the table
    const ConnectFour::bitboard key = node.key();
    Entry entry = table.lookup(key);
    if (entry.flag != INVALID) { // check if node has already been explored
        if (entry.flag == EXACT) { 
            return entry.value;
        } else if (entry.flag == LOWERBOUND) {
            alpha = std::max(alpha, int(entry.value));
        } else if (entry.flag == UPPERBOUND) {
            beta = std::min(beta, int(entry.value));
        }

        if (alpha >= beta) { return entry.value; }
    }

    int bestValue = -2147483647;
    for (unsigned int column : columnOrder) { 
        ConnectFour::bitboard move = possible & ConnectFour::columnMask(column);
        if (move == 0) { continue; } // if there is no bit in the move skip

        ConnectFour child = ConnectFour(node);
        child.makeMove(move);
        
        int value = -negamax(child, -beta, -alpha);
        if (value >= bestValue) {
            bestValue = value;
            if (value >= alpha) alpha = value;
            if (value >= beta) break;
        }
    }

    if (alpha <= alphaOriginal) {
        table.insert(key, Entry(bestValue, UPPERBOUND));
    } else if (bestValue >= beta) {
        table.insert(key, Entry(bestValue, LOWERBOUND));
    } else {
        table.insert(key, Entry(bestValue, EXACT));
    }
    return bestValue;
};
    
int solve(const ConnectFour &root) { 
    if (root.canWinNext()) {
        return ((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT + (int)1 - (int)root.counter) / (int)2;
    }

    int value = negamax(root, -2147483647, 2147483647);
    return value;
};

#endif