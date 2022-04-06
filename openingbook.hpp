#include "connectfour.hpp"
#include "transpositiontable.hpp"



#include <cstring>
#include <fstream>
#include <sstream>
class OpeningBook {
    public:
        unsigned int size;
        int8_t *entries;
        bitboard *keys;

        unsigned int index(bitboard key) {
            return key % size;
        }

        OpeningBook(const std::string filename) {
            size = closestPrime(10000000);
            entries = new int8_t[size];
            keys = new bitboard[size];
            reset();


            std::ifstream openingBookFile(filename);
            std::string line;
            while (std::getline(openingBookFile, line)) {
                std::istringstream iss(line);
                uint64_t key;
                int value;
                iss >> key >> value;
                insert(key, value);
            }
        }

        ~OpeningBook() {
            delete[] entries;
            delete[] keys;
        }

        void reset() {
            memset(entries, 0, sizeof(int8_t) * size);
            memset(keys, 0, sizeof(bitboard) * size);
        }

        void insert(bitboard key, int8_t entry) {
            unsigned int pos = index(key);
            keys[pos] = key;
            entries[pos] = entry;
        }

        int8_t lookup(bitboard key) {
            unsigned int pos = index(key);
            if (keys[pos] == key) {
                return entries[pos];
            } else {
                return 0;
            }
        }
};