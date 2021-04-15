#ifndef SIMULATION_H
#define SIMULATION_H
#include "Queue.h"
#include "Student.h"
#include "Window.h"
#include "Stats.h"
#include <fstream>
//simulation class that runs the simulation based on input file
class Simulation{
    public:
        //default constructor
        Simulation();
        //overloaded constructor 
        Simulation(string FileLocation);
        //destructor
        ~Simulation();
        //the main simulation body
        void simulate();
        //prints the results of the simulation
        void printSimulation();
    private:
        //number of windows in the sim
        int WindowArraySize;
        //array of windows in the sim
        Window* WindowArray;
        //array of students at windows in the sim
        Student* StudentArray;
        //queue of students in line
        Queue<Student> *studentQueue = new Queue<Student>;
        //stats object for calculating sim statistics
        Stats *stats = new Stats();

};
#endif