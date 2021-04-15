#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student{
    public:
        //default constructor
        Student();
        //overloaded constructor
        Student(int windowTime, int timeEntered);
        //distructor
        ~Student();
        //returns the how long the student waited
        int getWaitTime();
        //returns how long the student needs at the window
        int getTimeNeeded();
        //returns the time the student entered the queue
        int getTimeEnteredQueue();
        //bool to check if the student waited for more than 10 min
        bool getHasWaitedTenMinutes();
        //function to check if student wait for 10 min 
        void WaitedTenMinutes();
        //increments the student wait time
        void incrementWaitTime();
        //sets the amount of time the student waited
        int setWaitTime(int totalTime);
        //overload for the == operator
        bool operator==(Student s);
        // overload for != operator
        bool operator!=(Student s);
        //bool to check if at window 
        bool atWindow;


    private:
        //time waited
        int waitTime;
        //time needed at window
        int timeNeeded;
        //time entered queue
        int timeEnteredQueue;
        //if waited 10 or more min
        bool hasWaitedTenMinutes;
        


};
#endif