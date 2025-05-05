#pragma once

#include "../location.h"

enum class CellContent {
    Empty,
    Driver,
    Restaurant,
    Customer,
    Obstacle
};

struct Cell {
    Location location;
    CellContent content;

    Cell() : location{-1, -1}, content(CellContent::Empty) {}
    Cell(int row, int col, CellContent content = CellContent::Empty) : location{row, col}, content(content) {};
};