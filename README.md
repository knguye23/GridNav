# GridNav
Simulates food delivery routing on a grid using pathfinding algorithms (BFS), with support for obstacles, driver assignment based on proximity, and distance tracking.

## Setup & Usage

### Prerequisites
- C++17 compatible compiler (e.g., `g++`, `clang++`)
- CMake (version 3.10 or above)

### Build Steps
In your terminal, navigate to the project directory and run:

```bash
mkdir build
cd build
cmake ..
make
```

### Run the simulation
```bash
./simulation
```

### Modify the Simulation
To customize the grid, driver, or destination locations, edit main.cpp:

```cpp
int main() {
    // Create the simulation manager & pass in the grid dimensions you want to simulate.
    SimulationManager sim(10, 10);

    // Place your drivers at any {row, col}.
    sim.placeDriver({0, 0});

    // Place your destinations (restaurant and customer) at any {row, col}.
    sim.placeRestaurant({8, 9});
    sim.placeCustomer({4, 2});

    // Add obstacles at any {row, col}.
    sim.addObstacle({1, 4});

    // The simulation will be printed to your console.
    sim.simulate();

    return 0;
}
```
