#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP
#include <iostream>

#include <string.h>

struct ConnectFour { 
    private: 
        using bitboard = uint64_t; 

        static constexpr bitboard boardMask = 0b111111111111111111111111111111111111111111;
        static constexpr bitboard columnMask(unsigned int column) { return UINT64_C(0b111111) << ((column - 1) * HEIGHT); }        
        static constexpr bitboard bottomMask = 0b000001000001000001000001000001000001000001;
        static constexpr bitboard bottomColumnMask(unsigned int column) { return UINT64_C(1) << ((column - 1) * HEIGHT); }
        static constexpr bitboard topMask = 0b100000100000100000100000100000100000100000;
        static constexpr bitboard topColumnMask(unsigned int column) { return columnMask(column) & topMask; }

        bitboard red;
        bitboard yellow;

        bitboard mask() const { 
            return yellow | red; 
        };
        
        bitboard key() const { 
            if (currentPlayer() == 0) {
                return red + mask(); 
            } else {
                return yellow + mask();    
            }
        }

        void makeMove(bitboard move) {
            if (currentPlayer() == 0) { red ^= move; } else { yellow ^= move; }
            counter++;
        };

        bitboard possibleMoves() const {
            return ((mask() & (~topMask)) + bottomMask) & (~mask());
        };

        bitboard possibleWinningMoves() const {
            return computeWinningBits((currentPlayer() == 0) ? red : yellow, mask()) & possibleMoves();
        }

        bitboard opponentWinningMoves() const {
            return computeWinningBits((currentPlayer() == 1) ? red : yellow, mask()) & possibleMoves();
        }

        bitboard possibleNonLosingMoves() const {
            bitboard possibleMask = possibleMoves();
            bitboard opponentWin = computeWinningBits((currentPlayer() == 0) ? yellow : red, mask());
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

        static bitboard computeWinningBits(bitboard position, bitboard mask) {
            position = ((position & ConnectFour::columnMask(1)) << 0) | ((position & ConnectFour::columnMask(2)) << 1) | ((position & ConnectFour::columnMask(3)) << 2) | ((position & ConnectFour::columnMask(4)) << 3) | ((position & ConnectFour::columnMask(5)) << 4) | ((position & ConnectFour::columnMask(6)) << 5) | ((position & ConnectFour::columnMask(7)) << 6);
            mask = ((mask & ConnectFour::columnMask(1)) << 0) | ((mask & ConnectFour::columnMask(2)) << 1) | ((mask & ConnectFour::columnMask(3)) << 2) | ((mask & ConnectFour::columnMask(4)) << 3) | ((mask & ConnectFour::columnMask(5)) << 4) | ((mask & ConnectFour::columnMask(6)) << 5) | ((mask & ConnectFour::columnMask(7)) << 6);
            
            // vertical;
            bitboard r = (position << 1) & (position << 2) & (position << 3);

            // horizontal
            bitboard p = (position << (HEIGHT + 1)) & (position << 2 * (HEIGHT + 1));
            r |= p & (position << 3 * (HEIGHT + 1));
            r |= p & (position >> (HEIGHT + 1));
            p >>= 3 * (HEIGHT + 1);
            r |= p & (position << (HEIGHT + 1));
            r |= p & (position >> 3 * (HEIGHT + 1));

            // diagonal 1
            p = (position << HEIGHT) & (position << 2 * HEIGHT);
            r |= p & (position << 3 * HEIGHT);
            r |= p & (position >> HEIGHT);
            p >>= 3 * HEIGHT;
            r |= p & (position << HEIGHT);
            r |= p & (position >> 3 * HEIGHT);

            // diagonal 2
            p = (position << (HEIGHT + 2)) & (position << 2 * (HEIGHT + 2));
            r |= p & (position << 3 * (HEIGHT + 2));
            r |= p & (position >> (HEIGHT + 2));
            p >>= 3 * (HEIGHT + 2);
            r |= p & (position << (HEIGHT + 2));
            r |= p & (position >> 3 * (HEIGHT + 2));

            bitboard f = r & (0b1111111111111111111111111111111111111111111111111 ^ mask);
            return ((f & (0b111111 << (0 * (ConnectFour::HEIGHT + 1)))) >> 0) | ((f & (UINT64_C(0b111111) << (1 * (ConnectFour::HEIGHT + 1)))) >> 1) | ((f & (UINT64_C(0b111111) << (2 * (ConnectFour::HEIGHT + 1)))) >> 2) | ((f & (UINT64_C(0b111111) << (3 * (ConnectFour::HEIGHT + 1)))) >> 3) | ((f & (UINT64_C(0b111111) << (4 * (ConnectFour::HEIGHT + 1)))) >> 4) | ((f & (UINT64_C(0b111111) << (5 * (ConnectFour::HEIGHT + 1)))) >> 5) | ((f & (UINT64_C(0b111111) << (6 * (ConnectFour::HEIGHT + 1)))) >> 6);
        }

    public:
        static constexpr unsigned int WIDTH = 7;  
        static constexpr unsigned int HEIGHT = 6;
        
        ConnectFour() : red{0}, yellow{0}, counter{0} {};
        ConnectFour(const ConnectFour& other) : red{other.red}, yellow{other.yellow}, counter{other.counter} {}

        unsigned int counter = 0;

        unsigned int currentPlayer() const {
            return counter & 1;
        };

        bool isPlayable(unsigned int column) const {             
            if ((mask() & topColumnMask(column)) == 0 && column <= 7 && column != 0) {
                return true;
            } else {
                return false;    
            }
            
        };

        void makeMove(unsigned int column) {
            makeMove((mask() + bottomColumnMask(column) & columnMask(column)));
        };

        bool isWin() const {
            // Based on: https://spin.atomicobject.com/2017/07/08/game-playing-ai-bitboards/

            bitboard position;
            if (currentPlayer() == 0) { position = yellow; } else { position = red; }


            bitboard m;
            m = position & (position >> 1) & (position >> 2) & (position >> 3);
            if ((m & 0b000011000011000011000011000011000011) != 0) {
                return true;
            }

            m = position & (position >> HEIGHT) & (position >> (HEIGHT * 2)) & (position >> (HEIGHT * 3));
            if ((m & 0b00000000000000011111111111111) != 0) {
                return true;
            }

            m = position & (position >> ((HEIGHT + 1) * 1)) & (position >> ((HEIGHT + 1) * 2)) & (position >> ((HEIGHT + 1) * 3));
            if ((m & 0b00000110000011) != 0) {
                return true;
            }

            m = position & (position >> ((HEIGHT - 1) * 1)) & (position >> ((HEIGHT - 1) * 2)) & (position >> ((HEIGHT - 1) * 3));
            if ((m & 0b11000001100000) != 0) {
                return true;
            }
            return false;
        }

        bool isDraw() const {
            if (counter >= HEIGHT * WIDTH) {
                return true;
            } else {
                return false;
            }
        };
        
        bool canWinNext() const {
            if (possibleWinningMoves() == 0) {
                return false;
            } else {
                return true;
            }
        }

        void print() const {
            static char verticalSeperator[11] = "\u001b[34m|\u001b[0m";
            static char horizontalSeperator[53] = "\u001b[34m-------------------------------------------\u001b[0m";
            char arrayboard[42][13] = {"\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m", "\u001b[37m - \u001b[0m"};
            
            for (unsigned int i = 0; i < 42; i++) {
                if ((((bitboard)1 << i) & yellow) != 0) {
                    arrayboard[i][3] = '3'; // change color to yellow 
                    arrayboard[i][6] = 'Y'; // set char to Y
                } else if ((((bitboard)1 << i) & red) != 0) {
                    arrayboard[i][3] = '1'; // change color to red 
                    arrayboard[i][6] = 'R'; // set char to R
                }
            }
            
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[5] << ' ' << verticalSeperator << ' ' << arrayboard[11] << ' ' << verticalSeperator << ' ' << arrayboard[17] << ' ' << verticalSeperator << ' ' << arrayboard[23] << ' ' << verticalSeperator << ' ' << arrayboard[29] << ' ' << verticalSeperator << ' ' << arrayboard[35] << ' ' << verticalSeperator << ' ' << arrayboard[41] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[4] << ' ' << verticalSeperator << ' ' << arrayboard[10] << ' ' << verticalSeperator << ' ' << arrayboard[16] << ' ' << verticalSeperator << ' ' << arrayboard[22] << ' ' << verticalSeperator << ' ' << arrayboard[28] << ' ' << verticalSeperator << ' ' << arrayboard[34] << ' ' << verticalSeperator << ' ' << arrayboard[40] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[3] << ' ' << verticalSeperator << ' ' << arrayboard[9] << ' ' << verticalSeperator << ' ' << arrayboard[15] << ' ' << verticalSeperator << ' ' << arrayboard[21] << ' ' << verticalSeperator << ' ' << arrayboard[27] << ' ' << verticalSeperator << ' ' << arrayboard[33] << ' ' << verticalSeperator << ' ' << arrayboard[39] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[2] << ' ' << verticalSeperator << ' ' << arrayboard[8] << ' ' << verticalSeperator << ' ' << arrayboard[14] << ' ' << verticalSeperator << ' ' << arrayboard[20] << ' ' << verticalSeperator << ' ' << arrayboard[26] << ' ' << verticalSeperator << ' ' << arrayboard[32] << ' ' << verticalSeperator << ' ' << arrayboard[38] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[1] << ' ' << verticalSeperator << ' ' << arrayboard[7] << ' ' << verticalSeperator << ' ' << arrayboard[13] << ' ' << verticalSeperator << ' ' << arrayboard[19] << ' ' << verticalSeperator << ' ' << arrayboard[25] << ' ' << verticalSeperator << ' ' << arrayboard[31] << ' ' << verticalSeperator << ' ' << arrayboard[37] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << arrayboard[0] << ' ' << verticalSeperator << ' ' << arrayboard[6] << ' ' << verticalSeperator << ' ' << arrayboard[12] << ' ' << verticalSeperator << ' ' << arrayboard[18] << ' ' << verticalSeperator << ' ' << arrayboard[24] << ' ' << verticalSeperator << ' ' << arrayboard[30] << ' ' << verticalSeperator << ' ' << arrayboard[36] << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << '\n';
            std::cout << verticalSeperator << ' ' << "\u001b[34m 1 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 2 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 3 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 4 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 5 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 6 \u001b[0m" << ' ' << verticalSeperator << ' ' << "\u001b[34m 7 \u001b[0m" << ' ' << verticalSeperator << '\n';
            std::cout << horizontalSeperator << std::endl;      
        };  
};

#endif