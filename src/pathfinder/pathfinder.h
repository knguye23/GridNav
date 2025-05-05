#pragma once

#include "../grid/grid.h"
#include <vector>

namespace Pathfinder {
    std::vector<Location> bfs(Grid& grid, const Location& start, const Location& dest);
};