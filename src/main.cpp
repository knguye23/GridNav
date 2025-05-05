#include "simulationManager/simulationmanager.h"

int main() {
    SimulationManager sim(10, 10);
    // drivers
    sim.placeDriver({0, 0});
    sim.placeDriver({1, 6});
    sim.placeDriver({4, 5});
    sim.placeDriver({8, 3});
    sim.placeDriver({5, 9});

    // destinations
    sim.placeRestaurant({8, 9});
    sim.placeCustomer({4, 2});

    // obstacles
    sim.addObstacle({1, 4});
    sim.addObstacle({2, 4});
    sim.addObstacle({3, 4});
    sim.addObstacle({3, 3});
    sim.addObstacle({3, 2});
    sim.addObstacle({4, 1});
    sim.addObstacle({5, 2});
    sim.addObstacle({6, 0});
    sim.addObstacle({7, 1});
    sim.addObstacle({6, 3});
    sim.addObstacle({6, 4});
    sim.addObstacle({5, 5});
    sim.addObstacle({4, 6});
    sim.addObstacle({3, 6});
    sim.addObstacle({3, 7});
    sim.addObstacle({3, 8});
    sim.addObstacle({7, 6});
    sim.addObstacle({7, 7});
    sim.addObstacle({7, 8});
    sim.addObstacle({7, 9});
    sim.addObstacle({8, 4});
    sim.addObstacle({8, 6});
    sim.addObstacle({9, 4});
    sim.addObstacle({9, 8});

    sim.simulate();

    return 0;
}