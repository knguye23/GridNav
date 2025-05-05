#include "simulationmanager.h"
#include <iostream>
#include "../pathfinder/pathfinder.h"

SimulationManager::SimulationManager(int width, int height): grid(width, height) {};

bool SimulationManager::placeDriver(const Location& position) {
    drivers.push_back(position);
    grid.setCellContent(position, CellContent::Driver);
    return true;
};

bool SimulationManager::placeRestaurant(const Location& position) {
    restaurant = position;
    grid.setCellContent(position, CellContent::Restaurant);
    return true;
};

bool SimulationManager::placeCustomer(const Location& position) {
    customer = position;
    grid.setCellContent(position, CellContent::Customer);
    return true;
};

bool SimulationManager::addObstacle(const Location& position) {
    obstacles.push_back(position);
    grid.setCellContent(position, CellContent::Obstacle);
    return true;
};

std::optional<std::vector<Location>> SimulationManager::planDeliveryRoute() {
    std::cout << "Planning delivery route..." << std::endl;
    // assign closest driver and get their path to restaurant
    Location assignedDriver;
    int shortestDistance = INT_MAX;
    std::vector<Location> toRestaurant;
    for (const Location& driver : drivers) {
        std::cout << "Evaluating driver at: (" << driver.row << ", " << driver.col << ")" << std::endl;
        std::vector<Location> currentPath = Pathfinder::bfs(grid, driver, restaurant);
        std::cout << "Distance: " << currentPath.size() << std::endl;
        
        if (!currentPath.empty() && currentPath.size() < shortestDistance) {
            shortestDistance = currentPath.size();
            assignedDriver = driver;
            toRestaurant = currentPath;
        }
    }
    if (toRestaurant.empty()) return std::nullopt;
    
    // find path to customer
    std::vector<Location> toCustomer = Pathfinder::bfs(grid, restaurant, customer);
    if (toCustomer.empty()) return std::nullopt;
    
    // remove toCustomer first element if it's the same as toRestaurant last element
    if (!toCustomer.empty() && toRestaurant.back() == toCustomer.front()) {
        toCustomer.erase(toCustomer.begin());
    }
    
    // combine paths to get full path
    std::vector<Location> fullPath = toRestaurant;
    fullPath.insert(fullPath.end(), toCustomer.begin(), toCustomer.end());
    
    std::cout << "Finished planning." << std::endl;
    return fullPath;
};

void SimulationManager::simulate() {
    grid.print();
    
    auto pathOpt = planDeliveryRoute();
    if (!pathOpt) {
        std::cout << "No valid delivery path found." << std::endl;
        return;
    }

    const std::vector<Location>& path = *pathOpt;
    grid.printPath(path);
}