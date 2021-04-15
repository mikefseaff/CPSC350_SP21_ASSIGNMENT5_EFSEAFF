#include "Stats.h"
//default constructor
Stats::Stats(){
    NumStudentsOverTenMin = 0;
    NumWindowsOverFiveMin = 0;
}
//destructor
Stats::~Stats(){
    delete StudentWaitTimes;
    delete WindowIdleTimes;
    delete [] waitTimesArray;
    delete [] idleTimesArray;
}
//sets the arrays with information from the linked lists
void Stats::setArrays(){
    waitTimesArray = new int[StudentWaitTimes->getSize()];
    waitTimesArraySize = StudentWaitTimes->getSize();
    for (int i = 0; i < waitTimesArraySize; ++i){
        waitTimesArray[i] = StudentWaitTimes->removeFront();
    }
    idleTimesArray = new int[WindowIdleTimes->getSize()];
    idleTimesArraySize = WindowIdleTimes->getSize();
    for (int i = 0; i < idleTimesArraySize; ++i){
        idleTimesArray[i] = WindowIdleTimes->removeFront();
    }
    sort(waitTimesArray, waitTimesArray + waitTimesArraySize);
    sort(idleTimesArray, idleTimesArray + idleTimesArraySize);
}
//calcs mean student wait time
float Stats::calcMeanStudentWaitTime(){
    float sum = 0;
    for (int i = 0; i < waitTimesArraySize; ++i){
        sum += waitTimesArray[i];
        
    }
    return (sum/waitTimesArraySize);

}
 //calc median student wait time
int Stats::calcMedianStudentWaitTime(){
    int index = (waitTimesArraySize-1)/2;
    if (waitTimesArraySize%2 == 1){
        return waitTimesArray[index];

    }
    else{
        return (waitTimesArray[index] + waitTimesArray[index+1])/2;
    }
}
//calc longest student wait time
int Stats::calcLongestStudentWaitTime(){
    return waitTimesArray[waitTimesArraySize-1];
}
//calcs number of students who waited for over 10 minutes
int Stats::calcNumStudentsOverTenMin(){
    return NumStudentsOverTenMin;
}
//calculates the mean window idle time
float Stats::calcMeanWindowIdleTime(){
    float sum = 0;
    for (int i = 0; i < idleTimesArraySize; ++i){
        sum += idleTimesArray[i];
        
    }
    return (sum/idleTimesArraySize);
}
//calculated the longest idle time
int Stats::calcLongestWindowIdleTime(){
    return idleTimesArray[idleTimesArraySize-1];
}
//calculates the number of windows that idled over 5 minutes
int Stats::calcNumWindowsOverFiveMin(){
    return NumWindowsOverFiveMin;
}
//method to add a student wait time to the linked list
void Stats::addStudentWaitTime(int waitTime){
    StudentWaitTimes->insertBack(waitTime);
    if (waitTime > 10){
        NumStudentsOverTenMin++;
    }
}
//method to add a window idle time to linekd list
void Stats::addWindowIdleTime(int idleTime){
    WindowIdleTimes->insertBack(idleTime);
    if(idleTime > 5){
        NumWindowsOverFiveMin++;
    }
}