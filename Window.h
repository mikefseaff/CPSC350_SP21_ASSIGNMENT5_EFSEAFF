#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
using namespace std;
#include "Student.h"

class Window{
    public:
        //constructor
        Window();
        //destructor
        ~Window();
        //returns window idle time
        int getIdleTime();
        //returns if windwo idled for more than 5 min
        bool getIdledFiveMinutes();
        //returns if window is occupied
        bool getIsOccupied();
        //method to change if idled 5 min
        void hasIdledFiveMinutes();
        //increments the idle time
        void incrementIdleTime();
        //removes the student pointer at the window
        void removeStudentAtWindow();
        //assigns the student to the window
        void setStudentAtWindow(Student *student);
        //sets the window as occupied
        void setIsOccupied();
        //returns the student at the window
        Student* getStudentAtWindow();

    private:
        //idle time
        int idleTime;
        //bool for if idled more than 5 min
        bool idledFiveMinutes;
        //student at the window
        Student *studentAtWindow;
        //bool for if the window is occupied
        bool isOccupied;


};
#endif