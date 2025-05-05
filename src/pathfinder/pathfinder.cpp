#include "pathfinder.h"
#include <queue>
#include <unordered_map>
#include <iostream>

std::vector<Location> Pathfinder::bfs(Grid& grid, const Location& start, const Location& dest) {
    std::queue<Location> queue;
    std::vector<std::vector<bool>> visited(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
    std::unordered_map<Location, Location> cameFrom;

    queue.push(start);
    visited[start.row][start.col] = true;

    bool found = false;

    while (!queue.empty()) {
        Location current = queue.front();
        queue.pop();

        if (current == dest) {
            found = true;
            break;
        }

        for (auto& neighbor : grid.getNeighbors(current)) {
            if (!visited[neighbor.row][neighbor.col] && grid.isValidLocation(neighbor)) {
                visited[neighbor.row][neighbor.col] = true;
                cameFrom[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    std::vector<Location> path;
    if (!found) return path; // Return empty path if no route

    Location current = dest;
    while (!(current == start)) {
        path.push_back(current);
        current = cameFrom[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}