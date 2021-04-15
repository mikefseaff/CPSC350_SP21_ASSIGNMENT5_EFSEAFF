#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
#include "LinkedList.h"
//template class linked list based Queue
template<class T>
class Queue{
    public:
        //default constructor
        Queue();
        //destructor
        ~Queue();

        //core functions

        //inserts a node to the back of the queue
        void insert(T node);
        //removes node from the front of the queue
        T remove();

        

        //aux functions

        //returns the front of the queue
        T peek();
        //returns the back of the queue
        T peekBack();
        //bool to check if the queue is empty
        bool isEmpty();
        //returns the size of the queue
        size_t getSize();


    private:
        //linked list inherited by queue
        LinkedList<T> *myList = new LinkedList<T>;



};
//default constructor
template<class T>
Queue<T>::Queue(){

}
//destructor
template<class T>
Queue<T>::~Queue(){
    delete myList;
}
//inserts a node to the back of the queue
template<class T>
void Queue<T>::insert(T node){
    //check if full first
    myList->insertBack(node);
}
//removes node from the front of the queue
template<class T>
T Queue<T>::remove(){

    return myList->removeFront();
}
 //returns the front of the queue
template<class T>
T Queue<T>::peek(){
    if(isEmpty()){
        return T();
    }
    return myList->getFront();
}
 //returns the back of the queue
template<class T>
T Queue<T>::peekBack(){
    return myList->getBack();
}
//bool to check if the queue is empty
template<class T>
bool Queue<T>::isEmpty(){
    return myList->isEmpty();
}
 //returns the size of the queue
template<class T>
size_t Queue<T>::getSize(){
    return myList->getSize();
}
#endif