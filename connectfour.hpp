#ifndef CONNECTFOUR_HPP
#define CONNECTFOUR_HPP


#include <iostream>
#include <string>
#include <bitset>
#include <iterator>
#include <algorithm>

// NOTES:
// could be a bit more desriptive with names


using bitboard = uint64_t; // could be changed to bitmap

const unsigned int WIDTH = 7;
const unsigned int HEIGHT = 6; 

const bitboard bottomMask = 0;
const bitboard boardMask = bottomMask * ((1LL << HEIGHT) - 1);

class ConnectFour {
    // could put stuff in protected field instead
    public:
        unsigned int moveCounter;

        bitboard position = 0;
        bitboard mask = 0;
        
        bitboard yellow() const {
            if (moveCounter & 1 == 0) {
                return mask ^ position;
            } else {
                return position;
            }
        };

        bitboard red() const { 
            if (moveCounter & 1 == 1) {
                return mask ^ position;
            } else {
                return position;
            }
        };

        void play(bitboard move) {
            this -> position ^= this -> mask;
            this -> mask |= move;
            this -> moveCounter++;
        };

        void playColumn(int column) {
            this -> play(((this -> mask) + bottomColumnMask(column)) & columnMask(column));
        };

        bitboard possibleMask() const {
            return (this -> mask + bottomMask) & boardMask;
        };



        bool isAlignment() { // other name is checkAlignment or checkDraw
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

        bool isDraw() {
            return false;
        };

        void print() {
            std::string arrayboard[64] = {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
            std::string redBits = std::bitset<64>(this -> red()).to_string();
            std::string yellowBits = std::bitset<64>(this -> yellow()).to_string();

            for (int i = 0; i < redBits.length(); i++) {
                if (redBits[i] == '1') {
                    arrayboard[i] = "R";
                } 
            }

            for (int i = 0; i < yellowBits.length(); i++) {
                if (yellowBits[i] == '1') {
                    arrayboard[i] = "Y";
                } 
            }
            std::reverse(std::begin(arrayboard), std::end(arrayboard));

            std::cout << "|  " << arrayboard[5] << "  |  " << arrayboard[12] << "  |  " <<  arrayboard[19] << "  |  " <<  arrayboard[26] << "  |  " <<   arrayboard[33]   << "  |  " <<   arrayboard[40]   << "  |  " <<   arrayboard[47]   << "  |  \n-------------------------------------------\n|  " << arrayboard[4] << "  |  " <<   arrayboard[11]   << "  |  " << arrayboard[18] << "  |  " << arrayboard[25] << "  |  " << arrayboard[32] << "  |  " << arrayboard[39] << "  |  " << arrayboard[46] << "  |  \n-------------------------------------------\n|  " << arrayboard[3] << "  |  " << arrayboard[10] << "  |  " << arrayboard[17] << "  |  " << arrayboard[24] << "  |  " << arrayboard[31] << "  |  " << arrayboard[38] << "  |  " << arrayboard[45] << "  |  \n-------------------------------------------\n|  " << arrayboard[2] << "  |  " << arrayboard[9] << "  |  " << arrayboard[16] << "  |  " << arrayboard[23] << "  |  " << arrayboard[30] << "  |  " << arrayboard[37] << "  |  " <<  arrayboard[44]  << "  |  \n-------------------------------------------\n|  " <<  arrayboard[1] << "  |  " << arrayboard[8] << "  |  " << arrayboard[15] << "  |  " << arrayboard[22]  << "  |  " << arrayboard[29] << "  |  " << arrayboard[36] << "  |  " << arrayboard[43] << "  |  \n-------------------------------------------\n|  " << arrayboard[0] << "  |  " << arrayboard[7] << "  |  " << arrayboard[14] << "  |  " << arrayboard[21] << "  |  " << arrayboard[28] << "  |  " << arrayboard[35] << "  |  " << arrayboard[42] << "  |  \n-------------------------------------------\n|  " <<   0   << "  |  " <<   1   << "  |  " <<   2   << "  |  " <<   3   << "  |  " <<   4   << "  |  " <<   5   << "  |  " << 6 << "  |  " << std::endl;
        };   
        
        // Really hate this implementation maybe use recursive function
        template<int width, int height> struct bottom {static constexpr bitboard mask = bottom<width-1, height>::mask | bitboard(1) << (width - 1) * (height + 1);};
        template <int height> struct bottom<0, height> {static constexpr bitboard mask = 0;};
        
        static constexpr bitboard bottomMask = bottom<WIDTH, HEIGHT>::mask;
        static constexpr bitboard boardMask = bottomMask * ((1LL << HEIGHT) - 1);

        static constexpr bitboard columnMask(int column) {
            return ((UINT64_C(1) << 6) - 1) << column * (6 + 1);
        };

        static constexpr bitboard bottomColumnMask(int column) {
            return UINT64_C(1) << column * (HEIGHT + 1);
        };
};


#endif
