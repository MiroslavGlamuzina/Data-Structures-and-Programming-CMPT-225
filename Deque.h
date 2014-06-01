
#ifndef _DEQUE_
#define	_DEQUE_

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <string>

//Node class (singly-linked)
template <class T>
class Node
{
public:
    //Member variables
    T data;
    Node *next;
    //Copy constructor
    Node(const Node &nodePtr): data(nodePtr.data), next(nodePtr.next) {};
    //Other constructors
    Node(T item): data(item), next(NULL) {};
    Node(T item, Node *np): data(item), next(np) {};
};

//Deque class for all types
template<class T>
class Deque
{
public:
    //Constructor
    Deque();
    //Copy constructor
    Deque(const Deque &deq);
    //Destructor
    ~Deque();
    //Assignment operator overload
    Deque &operator=(const Deque &deq);
    //Member functions
    void insert_front(T item);   
    void insert_back(T item);  
    T remove_front();   
    T remove_back();    
    T peek_front();  
    T peek_back();   
    bool empty();
    //Size returns an int because size is a number.
    int size();
    //Might put these in later
    void deepCopy(const Deque &deq);
    void deleteDeque();
    
    //Test functions
    void testPrint();
    
private:
    Node<T> *front;
    Node<T> *back;
    //Added count attribute to track the size of the deque.
    int count;
    const std::string errorMsg = "The deque is empty."; 
};

#include "Deque.cpp"

#endif	//_DEQUE_

