#include "Simulation.h"
//main file of the program that runs the simulation based on command line input
int main(int argc, char const *argv[])
{
    string fileName = argv[1];
    Simulation sim(fileName);
    sim.simulate();
    sim.printSimulation();

    
    return 0;
}
