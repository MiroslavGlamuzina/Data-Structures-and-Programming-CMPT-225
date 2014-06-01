
#ifndef _DEQUE_
#define	_DEQUE_

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <string>

//Node class (singly-linked)
class Node
{
public:
    //Member variables
    int data;
    Node *next;
    //Copy constructor
    Node(const Node &nodePtr): data(nodePtr.data), next(nodePtr.next) {};
    //Other constructors
    Node(int item): data(item), next(NULL) {};
    Node(int item, Node *np): data(item), next(np) {};
};

//Deque class for int types
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
    void insert_front(int item);   
    void insert_back(int item);  
    int remove_front();   
    int remove_back();    
    int peek_front();  
    int peek_back();   
    bool empty();
    int size();
    //Might put this in later
    void deepCopy(const Deque &deq);
    
    //Test functions
    void testPrint();
    
private:
    Node *front;
    Node *back;
    //Added count attribute to track the size of the deque.
    int count;
    const std::string errorMsg = "The deque is empty."; 
};

#endif	/* DEQUE_H */

