#include "Simulation.h"
//defualt constructor
Simulation::Simulation(){
    WindowArray = new Window[1];

}
//overloaded constructor
Simulation::Simulation(string FileLocation){
    ifstream inputFile (FileLocation);
    string numWindows; 
    string timeStudentsArrive;
    string numStudents;
    string studentTimeNeededAtWindow;
    int totalStudents = 0;
    //checks if can open file
    if(inputFile.is_open()){
        getline(inputFile,numWindows);
        WindowArray = new Window[stoi(numWindows)];
        StudentArray = new Student[stoi(numWindows)];
        WindowArraySize = stoi(numWindows);
        //inserting the students and their details into the queue 
        while(getline(inputFile,timeStudentsArrive)){
            getline(inputFile,numStudents);
            totalStudents += stoi(numStudents);
            for (int i = 0; i < stoi(numStudents); ++i){
                getline(inputFile,studentTimeNeededAtWindow);
                Student tempStudent(stoi(studentTimeNeededAtWindow), stoi(timeStudentsArrive));
                studentQueue->insert(tempStudent);
            }
        }
    }
    //error check if file cant be openned
    else{
        cout << "invalid file name or path" << endl;
        exit(0);
    }  
    //light check if the file doesnt have the right amount of lines (doesnt really work 100% of the time)
    if(totalStudents != studentQueue->getSize()){
        cout << "File has incorrect number of lines in file for information given" << endl;
        exit(0);
    }
    inputFile.close();
}
//destructor
Simulation::~Simulation(){
    delete[] WindowArray;
    delete[] StudentArray;
    delete studentQueue;
    delete stats;
}
//simulation method
void Simulation::simulate(){
    //time over the simulation
    int globalTime = 0;
    //bool for if all windows are open for ending sim
    bool allWindowsOpen = true;
    //number of windows open
    int numWindowsOpen = 0;
    //window for the student to go to
    int windowToGoTo = 0;
    //run time loop
    while(true){
        windowToGoTo = 0;
        for (int i = 0; i < WindowArraySize; ++i){
            //check if window is occupied and student has been their the required time
            if(WindowArray[i].getIsOccupied()){
                int totalStudentTime = 0;
                totalStudentTime += WindowArray[i].getStudentAtWindow()->getTimeEnteredQueue();
                totalStudentTime += WindowArray[i].getStudentAtWindow()->getTimeNeeded();
                totalStudentTime += WindowArray[i].getStudentAtWindow()->getWaitTime();
                if (totalStudentTime == globalTime){
                    //pushes students wait time to the stats object and removes the student from the window
                    stats->addStudentWaitTime(WindowArray[i].getStudentAtWindow()->getWaitTime());
                    WindowArray[i].removeStudentAtWindow();
                    StudentArray[i].atWindow = false;

                }
            }
            
        }
        //logic for adding students to windows 
        
        for(int i = 0; i < WindowArraySize; ++i){
            if(studentQueue->isEmpty()){
                break;
            }
            
            if (!studentQueue->isEmpty() &&  studentQueue->peek().setWaitTime(globalTime) >= 0){
                //finds and open space in the studentarray for the student to go into
                for (int i = 0; i < WindowArraySize; ++i){
                    if(StudentArray[i].atWindow == false){
                        windowToGoTo = i;
                        break; 
                    }
                }
                //removes student from queue and adds to the array, then assigns an avaliable window to it
                if(!WindowArray[i].getIsOccupied()){
                    StudentArray[windowToGoTo] = studentQueue->remove();
                    StudentArray[windowToGoTo].atWindow = true;
                    StudentArray[windowToGoTo].setWaitTime(globalTime);
                    WindowArray[i].setStudentAtWindow(&StudentArray[windowToGoTo]);  
                }
                
            }
        }
        //if all windows are un occupied make boolean true
        for (int i = 0; i < WindowArraySize; ++i){
            if (!WindowArray[i].getIsOccupied()){
                numWindowsOpen++;
            }
            if(numWindowsOpen == WindowArraySize && globalTime != 0){
                
                allWindowsOpen = true;
            }
            else{
                
                
                allWindowsOpen = false;
            }
        }
        //if the queue is empty and the windows are open then there are no more students so end simulation
        if(studentQueue->isEmpty() && allWindowsOpen){
            for(int i = 0; i < WindowArraySize; ++i){
                //add window idle time infor to stats
                stats->addWindowIdleTime(WindowArray[i].getIdleTime());
            }
            //establish info arrays in stats
            stats->setArrays();
            break;
        }

        

        //re checks for if the windows are occupied after logic
        for (int i = 0; i < WindowArraySize; ++i){
            WindowArray[i].setIsOccupied();
            if(!WindowArray[i].getIsOccupied()){                
                WindowArray[i].incrementIdleTime();
                
            }
            
        }

   
        numWindowsOpen = 0;
        globalTime++;
        
    }

}

//prints the simulaition after it ends
void Simulation::printSimulation(){
    cout << "Mean student wait time: " << stats->calcMeanStudentWaitTime() << endl;
    cout << "Median student wait time: " << stats->calcMedianStudentWaitTime() << endl;
    cout << "Longest student wait time: " << stats->calcLongestStudentWaitTime() << endl;
    cout << "Number of students waiting over 10 minutes: " << stats->calcNumStudentsOverTenMin() << endl;
    cout << "Mean window idle time: " << stats->calcMeanWindowIdleTime() << endl;
    cout << "Longest window idle time: " << stats->calcLongestWindowIdleTime() << endl;
    cout << "Windows idle over five minutes: " << stats->calcNumWindowsOverFiveMin() << endl;
}