#pragma once

#include <unordered_map>

struct Location {
    int row;
    int col;

    Location() : row(-1), col(-1) {}
    Location(int r, int c) : row(r), col(c) {}

    // second const: ensures *this won't be modified
    bool operator==(const Location& other) const {
        return row == other.row && col == other.col;
    };
};

namespace std {
    template <>
    struct hash<Location> {
        // hashing operation that returns unsigned int
        // used by calling -- std::hash<Location>()(any location)
        // noexcept = guarantees not to throw exception
        std::size_t operator()(const Location& loc) const noexcept {
            // hash(row) xor (hash(col) shift left by 1 bit)
            return std::hash<int>()(loc.row) ^ (std::hash<int>()(loc.col) << 1);
        }
    };
}