#ifndef SOLVER_HPP
#define SOLVER_HPP
#include "connectfour.hpp"
#include "transpositiontable.hpp"
#include <vector>
#include <cmath>

class Solver {
    public:
        unsigned int nodesExplored;
        Solver() {
            reset();
        };

        void reset() {
            transpositionTable.reset();
            nodesExplored = 0;
        }

        int solve(const ConnectFour &root) { 
            if (root.canWinNext()) {
                return ((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT + (int)1 - (int)root.moveCounter) / (int)2;
            }

            int value = iterativeDeepening(root);
            return value;
        };




    private:
        TranspositionTable transpositionTable = TranspositionTable(1000000000);
        static constexpr int columnOrder[ConnectFour::WIDTH] = {3, 2, 4, 1, 5, 0, 6};

        int MTDF(const ConnectFour &root, unsigned int depth) {
            int g = 0;
            int upperbound = ((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT + (int)1 - (int)root.moveCounter) / (int)2;
            int lowerbound = -((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT - (int)root.moveCounter) / (int)2;

            while (lowerbound < upperbound) {
                int beta;	
                if (g == lowerbound) {
                    beta = g + 1;
                } else { 
                    beta = g;
                }

                g = negamax(root, beta - 1, beta, depth);
                if (g < beta) {
                    upperbound = g;
                } else {
                    lowerbound = g;
                }
            }
            return g;
        }

        int iterativeDeepening(const ConnectFour &root) {
            int f;
            for (unsigned int depth = 1; true; depth++) {
                f = MTDF(root, depth);
                if (f != 0) {
                    return f;
                } else if (root.moveCounter + depth >= ConnectFour::WIDTH * ConnectFour::HEIGHT) {
                    return 0;
                }
            }

            return f;
        }

        int negamax(const ConnectFour &node, int alpha, int beta, unsigned int depth) {
            if (depth <= 0) { return 0; }
            nodesExplored++;

            bitboard possible = node.possibleNonLosingMoves();
            if (possible == 0) { return -(((int)ConnectFour::WIDTH * (int)ConnectFour::HEIGHT -(int)node.moveCounter) / (int)2); }
            if (node.isDraw()) { return 0; }

            const int alphaOriginal = alpha;
            Entry entry = transpositionTable.lookup(node.hash());
            if (entry.flag != INVALID) {
                if ((entry.value != 0 || node.moveCounter + entry.depth >= ConnectFour::WIDTH * ConnectFour::HEIGHT) || entry.depth == depth) {
                    if (entry.flag == EXACT) {
                        return entry.value;
                    } else if (entry.flag == LOWERBOUND) {
                        alpha = std::max(alpha, int(entry.value));
                    } else if (entry.flag == UPPERBOUND) {
                        beta = std::min(beta, int(entry.value));
                    }

                    if (alpha >= beta) { return entry.value; }
                }
            }
            
            int bestValue = -2147483647;
            ConnectFour child;
            for (unsigned int column : columnOrder) { 
                bitboard move = possible & ConnectFour::columnMask(column);
                if (move == 0) { continue; } // if there is no bit in the move skip

                child = ConnectFour(node);
                child.playMove(move);
                
                int value = -negamax(child, -beta, -alpha, depth - 1);
                if (value >= bestValue) {
                    bestValue = value;
                    if (value >= alpha) alpha = value;
                    if (value >= beta) break;
                }
            }

            entry.value = bestValue;
            if (alpha <= alphaOriginal) {
                entry.flag = UPPERBOUND;
            } else if (bestValue >= beta) {
                entry.flag = LOWERBOUND;
            } else {
                entry.flag = EXACT;
            }
            entry.depth = depth;
            transpositionTable.insert(node.hash(), entry);
            return bestValue;
        };
};





// might return a array of scores 


#endif