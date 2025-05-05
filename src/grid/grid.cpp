#include "grid.h"
#include <iostream>

// Constructor() : initializes class members
Grid::Grid(int width, int height): width(width), height(height) {
    // initialize grid: height rows, width elements per row init to Empty
    grid.resize(height, std::vector<Cell>(width));

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            grid[row][col].location = {row, col};
        }
    }
};

 // read-only: cannot modify internal state
bool Grid::isValidLocation(const Location& loc) const {
    return grid[loc.row][loc.col].content != CellContent::Obstacle;
};

bool Grid::isInBounds(const Location& loc) const {
    return loc.row >= 0 && loc.row < height && loc.col >= 0 && loc.col < width;
};

// returns read-only reference to Cell
const Cell& Grid::getCell(const Location& loc) const {
    return grid[loc.row][loc.col];
};

// returns modifiable reference to cell
Cell& Grid::getCell(const Location& loc) {
    return grid[loc.row][loc.col];
};

void Grid::setCellContent(const Location& loc, CellContent content) {
    grid[loc.row][loc.col].content = content;
};

// read-only printing util
void Grid::print() const {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; col++) {
            const Cell& cell = grid[row][col];
            switch (cell.content) {
                case CellContent::Empty:
                    std::cout << "⬜️";
                    break;
                case CellContent::Obstacle:
                    std::cout << "⛔️";
                    break;
                case CellContent::Restaurant:
                    std::cout << "🍲";
                    break;
                case CellContent::Customer:
                    std::cout << "⭐️";
                    break;
                case CellContent::Driver:
                    std::cout << "🚙";
                    break;
                default:
                    std::cout << "⬜️";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}; 

void Grid::printPath(const std::vector<Location>& path) const {
    std::vector<std::vector<std::string>> visualGrid(height, std::vector<std::string>(width, "⬜️"));
    for (const Location& step : path) {
        visualGrid[step.row][step.col] = "🚙";
    }
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            std::cout << visualGrid[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

std::vector<Location> Grid::getNeighbors(const Location& loc) const {
    std::vector<Location> neighbors;

    const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for (const auto& [dr, dc] : directions) {
        Location next{loc.row + dr, loc.col + dc};
        if (isInBounds(next) && isValidLocation(next)) {
            neighbors.push_back(next);
        }
    } 

    return neighbors;
};