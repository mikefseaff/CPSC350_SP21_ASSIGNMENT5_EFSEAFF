#ifndef STATS_H
#define STATS_H
#include "LinkedList.h"
#include <algorithm>
//class used to calculated statistics of the simulation
class Stats{
    public:
        //default constructor
        Stats();
        //destructor
        ~Stats();
        //sets the arrays with information from the linked lists
        void setArrays();
        //calcs mean student wait time
        float calcMeanStudentWaitTime();
        //calc median student wait time
        int calcMedianStudentWaitTime();
        //calc longest student wait time
        int calcLongestStudentWaitTime();
        //calcs number of students who waited for over 10 minutes
        int calcNumStudentsOverTenMin();
        //calculates the mean window idle time
        float calcMeanWindowIdleTime();
        //calculated the longest idle time
        int calcLongestWindowIdleTime();
        //calculates the number of windows that idled over 5 minutes
        int calcNumWindowsOverFiveMin();
        //method to add a student wait time to the linked list
        void addStudentWaitTime(int waitTime);
        //method to add a window idle time to linekd list
        void addWindowIdleTime(int idleTime);
    private:
        //linked list representing the wait times of each student
        LinkedList<int> *StudentWaitTimes = new LinkedList<int>;
        //linked list representing the idle times of each window
        LinkedList<int> *WindowIdleTimes = new LinkedList<int>;
        //array of the wait times for easy sorting
        int* waitTimesArray;
        //array of the idle times for sorting
        int* idleTimesArray;
        //number of students in sim
        int waitTimesArraySize;
        //number of windows in sim
        int idleTimesArraySize;
        //number of students who waited over 10 min
        int NumStudentsOverTenMin;
        //number of students who waited over 5 mins
        int NumWindowsOverFiveMin;

};
#endif