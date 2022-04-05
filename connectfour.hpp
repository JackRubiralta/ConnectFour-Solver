#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP

#include <iostream>
#include <string>
#include <bitset>
#include <iterator>
#include <algorithm>

using bitboard = uint64_t; 

class ConnectFour {
    public:
        static constexpr unsigned int WIDTH = 7;  
        static constexpr unsigned int HEIGHT = 6; 

        unsigned int moveCounter;
        bitboard position;
        bitboard mask;

        void play(bitboard move) {
            position ^= mask;
            mask |= move;
            moveCounter++;
        };

        void playColumn(unsigned int column) {
            play((mask + bottomColumnMask(column)) & columnMask(column));
        }

        ConnectFour() : position{0}, mask{0}, moveCounter{0} {}

        ConnectFour(const ConnectFour& other) { 
            mask = other.mask;
            position = other.position;
            moveCounter = other.moveCounter;
        }

        bitboard possible() const {
            return (mask + bottomMask) & boardMask;
        }

        int currentPlayer() const {
            return moveCounter % 2;
        }

        bitboard yellow() const {
            if (moveCounter % 2 == 0) {
                return position ^ mask;
            } else {
                return position;
            }
        };

        bitboard red() const { 
            if (moveCounter % 2 == 0) {
                return position;
            } else {
                return position ^ mask;
            }
        };

        bitboard hash() const { return position + mask; }

        bool isWin() const { // other name is checkAlignment or checkDraw
            // horizontal 
            bitboard position = this -> position ^ this -> mask;

            bitboard m = position & (position >> (HEIGHT+1));
            if(m & (m >> (2*(HEIGHT+1)))) return true;

            // diagonal 1
            m = position & (position >> HEIGHT);
            if(m & (m >> (2*HEIGHT))) return true;

            // diagonal 2 
            m = position & (position >> (HEIGHT+2));
            if(m & (m >> (2*(HEIGHT+2)))) return true;

            // vertical;
            m = position & (position >> 1);
            if(m & (m >> 2)) return true;

            return false;
        };

        bool isDraw() const {
            if (this -> moveCounter >= HEIGHT * WIDTH) {
                return true;
            } else {
                return false;
            }
        };

        void print() {
            std::string arrayboard[64] = {"\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m", "\u001b[34m-\u001b[0m"};
            std::string redBits = std::bitset<64>(this -> red()).to_string();
            std::string yellowBits = std::bitset<64>(this -> yellow()).to_string();
            
            for (int i = 0; i < redBits.length(); i++) {
                if (redBits[i] == '1') {
                    arrayboard[i] = "\u001b[31mR\u001b[0m";
                } 
            }

            for (int i = 0; i < yellowBits.length(); i++) {
                if (yellowBits[i] == '1') {
                    arrayboard[i] = "\u001b[33mY\u001b[0m";
                } 
            }
            std::reverse(std::begin(arrayboard), std::end(arrayboard));

            std::cout << "\u001b[34m|\u001b[0m  " << arrayboard[5] << "  \u001b[34m|\u001b[0m  " << arrayboard[12] << "  \u001b[34m|\u001b[0m  " <<  arrayboard[19] << "  \u001b[34m|\u001b[0m  " <<  arrayboard[26] << "  \u001b[34m|\u001b[0m  " <<   arrayboard[33]   << "  \u001b[34m|\u001b[0m  " <<   arrayboard[40]   << "  \u001b[34m|\u001b[0m  " <<   arrayboard[47]   << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " << arrayboard[4] << "  \u001b[34m|\u001b[0m  " <<   arrayboard[11]   << "  \u001b[34m|\u001b[0m  " << arrayboard[18] << "  \u001b[34m|\u001b[0m  " << arrayboard[25] << "  \u001b[34m|\u001b[0m  " << arrayboard[32] << "  \u001b[34m|\u001b[0m  " << arrayboard[39] << "  \u001b[34m|\u001b[0m  " << arrayboard[46] << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " << arrayboard[3] << "  \u001b[34m|\u001b[0m  " << arrayboard[10] << "  \u001b[34m|\u001b[0m  " << arrayboard[17] << "  \u001b[34m|\u001b[0m  " << arrayboard[24] << "  \u001b[34m|\u001b[0m  " << arrayboard[31] << "  \u001b[34m|\u001b[0m  " << arrayboard[38] << "  \u001b[34m|\u001b[0m  " << arrayboard[45] << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " << arrayboard[2] << "  \u001b[34m|\u001b[0m  " << arrayboard[9] << "  \u001b[34m|\u001b[0m  " << arrayboard[16] << "  \u001b[34m|\u001b[0m  " << arrayboard[23] << "  \u001b[34m|\u001b[0m  " << arrayboard[30] << "  \u001b[34m|\u001b[0m  " << arrayboard[37] << "  \u001b[34m|\u001b[0m  " <<  arrayboard[44]  << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " <<  arrayboard[1] << "  \u001b[34m|\u001b[0m  " << arrayboard[8] << "  \u001b[34m|\u001b[0m  " << arrayboard[15] << "  \u001b[34m|\u001b[0m  " << arrayboard[22]  << "  \u001b[34m|\u001b[0m  " << arrayboard[29] << "  \u001b[34m|\u001b[0m  " << arrayboard[36] << "  \u001b[34m|\u001b[0m  " << arrayboard[43] << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " << arrayboard[0] << "  \u001b[34m|\u001b[0m  " << arrayboard[7] << "  \u001b[34m|\u001b[0m  " << arrayboard[14] << "  \u001b[34m|\u001b[0m  " << arrayboard[21] << "  \u001b[34m|\u001b[0m  " << arrayboard[28] << "  \u001b[34m|\u001b[0m  " << arrayboard[35] << "  \u001b[34m|\u001b[0m  " << arrayboard[42] << "  \u001b[34m|\u001b[0m  \n\u001b[34m-------------------------------------------\u001b[0m\n\u001b[34m|\u001b[0m  " << "\u001b[36m0\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m1\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m2\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m3\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m4\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m5\u001b[0m" << "  \u001b[34m|\u001b[0m  " << "\u001b[36m6\u001b[0m" << "  \u001b[34m|\u001b[0m  " << std::endl;
        };  
        
        bitboard possibleNonLosingMoves() const {
            bitboard possibleMask = possible();
            bitboard opponentWin = opponentWinningPositions();
            bitboard forcedMoves = possibleMask & opponentWin;
            if (forcedMoves) {
                if (forcedMoves & (forcedMoves - 1)) {
                    return 0;      
                } else {
                    possibleMask = forcedMoves;
                }
            }
            return possibleMask & ~(opponentWin >> 1);  // avoid to play below an opponent winning spot
        }

        bool isGameOver() const {
            if (isDraw() || isWin()) {
                return true;
            }
            return false;
        }

        bool canWinNext() const {
            return winningPositions() & possible();
        }

        bitboard winningPositions() const {
            return computeWinningPositions(position, mask);
        }

        bitboard opponentWinningPositions() const {
            return computeWinningPositions(position ^ mask, mask);
        }

        static bitboard computeWinningPositions(bitboard position, bitboard mask) {
            // vertical;
            bitboard r = (position << 1) & (position << 2) & (position << 3);

            //horizontal
            bitboard p = (position << (HEIGHT+1)) & (position << 2*(HEIGHT+1));
            r |= p & (position << 3*(HEIGHT+1));
            r |= p & (position >> (HEIGHT+1));
            p >>= 3*(HEIGHT+1);
            r |= p & (position << (HEIGHT+1));
            r |= p & (position >> 3*(HEIGHT+1));

            //diagonal 1
            p = (position << HEIGHT) & (position << 2*HEIGHT);
            r |= p & (position << 3*HEIGHT);
            r |= p & (position >> HEIGHT);
            p >>= 3*HEIGHT;
            r |= p & (position << HEIGHT);
            r |= p & (position >> 3*HEIGHT);

            //diagonal 2
            p = (position << (HEIGHT+2)) & (position << 2*(HEIGHT+2));
            r |= p & (position << 3*(HEIGHT+2));
            r |= p & (position >> (HEIGHT+2));
            p >>= 3*(HEIGHT+2);
            r |= p & (position << (HEIGHT+2));
            r |= p & (position >> 3*(HEIGHT+2));

            return r & (boardMask ^ mask);
        }

        template<int width, int height> struct bottom {static constexpr bitboard mask = bottom<width-1, height>::mask | bitboard(1) << (width - 1) * (height + 1);};
        template <int height> struct bottom<0, height> {static constexpr bitboard mask = 0;};

        static constexpr bitboard bottomMask = bottom<WIDTH, HEIGHT>::mask;
        static constexpr bitboard boardMask = bottomMask * ((1LL << HEIGHT) - 1);

        static constexpr bitboard topColumnMask(int column) {
            return UINT64_C(1) << ((HEIGHT - 1) + column * (HEIGHT + 1));
        }

        static constexpr bitboard bottomColumnMask(int column) {
            return UINT64_C(1) << column * (HEIGHT + 1);
        }

        static constexpr bitboard columnMask(int column) {
            return ((UINT64_C(1) << HEIGHT) - 1) << column * (HEIGHT + 1);
        }
};

#endif
