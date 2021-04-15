#include "Student.h"
//default constructor
Student::Student(){
    waitTime = 0;
    timeNeeded = 0;
    hasWaitedTenMinutes = false;
    timeEnteredQueue = 0;
    atWindow = false;
}
//overloaded consturctor
Student::Student(int windowTime, int timeEntered){
    waitTime = 0;
    timeNeeded = windowTime;
    hasWaitedTenMinutes = false;
    timeEnteredQueue = timeEntered;
    atWindow = false;
}
//destructor
Student::~Student(){

}
//returns the how long the student waited
int Student::getWaitTime(){
    return waitTime;
}
//returns how long the student needs at the window
int Student::getTimeNeeded(){
    return timeNeeded;
}
//returns the time the student entered the queue
int Student::getTimeEnteredQueue(){
    return timeEnteredQueue;
}
//function to check if student wait for 10 min 
bool Student::getHasWaitedTenMinutes(){
    return hasWaitedTenMinutes;
}

//bool to check if the student waited for more than 10 min
void Student::WaitedTenMinutes(){
    if (waitTime > 10){
        hasWaitedTenMinutes = true;
    }

}
//increments the student wait time
void Student::incrementWaitTime(){
    waitTime++;
}
//sets the amount of time the student waited
int Student::setWaitTime(int totalTime){
  waitTime = totalTime - timeEnteredQueue;
   return waitTime;
}
//overload for the == operator
bool Student::operator==(Student s){
  return (this->timeEnteredQueue == s.timeEnteredQueue && this->waitTime == s.waitTime);
}
// overload for != operator
bool Student::operator!=(Student s){
  return (this->timeEnteredQueue != s.timeEnteredQueue && this->waitTime != s.waitTime);
}