#include "Window.h"
//default constructor
Window::Window(){
    idleTime = 0;
    idledFiveMinutes = false;
    studentAtWindow = NULL;
    isOccupied = false;
}
//destructor
Window::~Window(){
    studentAtWindow = NULL;
}
////returns window idle time
int Window::getIdleTime(){
    return idleTime;
}
//returns if windwo idled for more than 5 min
bool Window::getIdledFiveMinutes(){
    return idledFiveMinutes;
}
//returns if window is occupied
bool Window::getIsOccupied(){
    return isOccupied;
}
//method to change if idled 5 min
void Window::hasIdledFiveMinutes(){
    if(idleTime > 5){
        idledFiveMinutes = true;
    }
}
//increments the idle time
void Window::incrementIdleTime(){
    ++idleTime;
}
//removes the student pointer at the window
void Window::setStudentAtWindow(Student *student){

    studentAtWindow = student;
}
//assigns the student to the window
void Window::removeStudentAtWindow(){
    studentAtWindow = NULL;
    setIsOccupied();
}
//sets the window as occupied
void Window::setIsOccupied(){
    if (studentAtWindow != NULL){
        isOccupied = true;
    }
    else{
        isOccupied = false;
    }
}
//returns the student at the window
Student* Window::getStudentAtWindow(){
    return studentAtWindow;
}