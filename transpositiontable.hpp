#include "connectfour.hpp"
#include <cstring>

enum Flag { INVALID, EXACT, LOWERBOUND, UPPERBOUND };

struct Entry {
    int value;
    Flag flag;
    Entry() : value(0), flag(INVALID) {}
};

class TranspositionTable {
    public:
        // 10602547
        // 20602523
        // 40000001
        // 100000001
        const unsigned int size = 89999999;
        Entry *entries;
        bitboard *keys;

        unsigned int index(bitboard key) {
            return key % size;
        }

        // size = 89999999
        TranspositionTable() {
            entries = new Entry[size];
            keys = new bitboard[size];
            reset();
        }

        ~TranspositionTable() {
            delete[] entries;
            delete[] keys;
        }

        void reset() {
            memset(entries, 0, sizeof(Entry) * size);
            memset(keys, 0, sizeof(bitboard) * size);
        }

        void insert(bitboard key, Entry entry) {
            unsigned int pos = index(key);
            keys[pos] = key;
            entries[pos] = entry;
        }

        Entry lookup(bitboard key) {
            unsigned int pos = index(key);
            if (keys[pos] == key) {
                return entries[pos];
            } else {
                return Entry();
            }
        }

        unsigned int length() {
            unsigned int length = 0;
            for (unsigned int i = 0; i < size; i++) {
                if (keys[i] != 0) {
                    length++;
                }
            }
            return length;
        }
};