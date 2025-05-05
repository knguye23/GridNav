#pragma once

#include <string>
#include <vector>
#include <optional>
#include "../grid/cell.h"
#include "../grid/grid.h"
 
class SimulationManager {
public:
    // constructor
    SimulationManager(int width, int height);

    // set up
    bool placeDriver(const Location& position);
    bool placeRestaurant(const Location& position);
    bool placeCustomer(const Location& position);
    bool addObstacle(const Location& position);

    void simulate();
    
    private:
    std::vector<Location> drivers;
    std::vector<Location> obstacles;
    Location restaurant;
    Location customer;
    Grid grid;
    
    std::optional<std::vector<Location> > planDeliveryRoute();
};