#ifndef LIST_H
#define LIST_H
//virtual class used as a base for the linked list class
template<class T>
class List{
    public:
        //virtual method that inserts a node to front of list
        virtual void insertFront(T data)=0;
        //virtual method that inserts node to back of list
        virtual void insertBack(T data)=0;
        //virtual method that removes node from front of list
        virtual T removeFront()=0;
        //virtual method that removes node from back of list
        virtual T removeBack()=0;
        //virtual method that removes a node given a specific key
        virtual T remove(T key)=0;
        //virtual method that returns size of the list
        virtual size_t getSize()=0;
        //virtual method that returns the front node of the list
        virtual T getFront()=0;
        //virtual method that returns if the list is empty or not
        virtual bool isEmpty()=0;
};
#endif