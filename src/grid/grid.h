#pragma once

#include <vector>
#include "cell.h"

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Cell> > grid;

public:
    // constructor
    Grid(int width, int height);

    bool isValidLocation(const Location& loc) const; // read-only: cannot modify internal state
    bool isInBounds(const Location& loc) const; // read-only: cannot modify internal state

    const Cell& getCell(const Location& loc) const; // returns read-only reference to Cell
    Cell& getCell(const Location& loc); // returns modifiable reference to cell

    void setCellContent(const Location& loc, CellContent content);
    void print() const; // read-only printing util
    void printPath(const std::vector<Location>& path) const;

    std::vector<Location> getNeighbors(const Location& loc) const; // read-only

    // getters
    int getWidth() const { return width; };
    int getHeight() const { return height; };
};