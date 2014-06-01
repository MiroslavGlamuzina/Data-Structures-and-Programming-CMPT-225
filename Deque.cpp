#include "Deque.h"

//Constructor
Deque::Deque(): 
        front(NULL), 
        back(NULL), 
        count(0) 
{};
//Copy constructor
Deque::Deque(const Deque &deq): 
        front(deq.front), 
        back(deq.back),
        count(deq.count)
{};

Deque::~Deque()
{
    
}
//Overloaded assignment operator
Deque& Deque::operator=(const Deque &deq)
{
    if(this != &deq){
        front = deq.front;
        back = deq.back;
    }
    return *this;
}
//Inserts an element at the front of the deque.
//PARAM: item = data to be inserted at the front of the deque.
//PRE: deque must not be empty.
//POST: item is inserted at the front of the deque, count attribute is 
//      incremented.
void Deque::insert_front(int item)
{
    Node* temp = new Node(item);
    if(empty()){
        front = back = temp;
    }
    else {
        temp->next = front;
        front = temp;
    }
    count++;
}

//Inserts an element at the back of the deque.
//PARAM: item = data to be inserted at the back of the deque.
//PRE: deque must not be empty.
//POST: item is inserted at the back of the deque, count attribute is 
//      incremented.
void Deque::insert_back(int item)
{
    Node *temp = new Node(item);
    if(empty()){
        back = front = temp;
    }
    else {
        temp->next = back;
        back = temp;
    }
    count++;
}
//Removes and returns the data element at the front of the deque.
//PARAM:
//PRE: deque most not be empty.
//POST: returns and removes result, which is the data element at the front of 
//      the deque. Decrements count attribute.
int Deque::remove_front()
{
    int result = front->data;
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    front = front->next;
    count--;
    return result;
}

//Removes and returns the item at the back of the deque.
//PARAM:
//PRE: deque must not be empty.
//POST: returns and removes result, which is the data element at the back of 
//      the deque. Decrements count attribute. Operates in O(n) time.
int Deque::remove_back()
{
    //Add comments to explain what's happening here.
    int result = back->data;
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    else {
        Node *tempBack = back;
        if(front == back){
            front = NULL;
        }
        else {
            Node *temp = front;
            while(temp->next != back){
                temp = temp->next;
            }
            back = temp;
            back->next = NULL;
        }
        delete tempBack;
    }
    count--;
    return result;
}

//Returns the data element at the front of the deque without deletion.
//PARAM:
//PRE:
//POST: return front->data.
int Deque::peek_front()
{
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    int result = front->data;
    return result;
}

//Returns the data element at the back of the deque without deletion.
//PARAM:
//PRE:
//POST: returns back->data. 
int Deque::peek_back()
{
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    int result = back->data;
    return result;
}
//Checks to see if deque is empty.
//PARAM:
//PRE: size() must return an integer value.
//POST: True if size() == 0, false otherwise.
bool Deque::empty()
{
    return size() == 0;
}

//Returns the size of the deque.
//PARAM:
//PRE:
//POST: Returns the 'count' member attribute of the Deque class.
int Deque::size()
{
    //Doesn't work when remove_back method is used...
    return count;
}

//Testing functions for Deque class
void Deque::testPrint()
{
    Node* temp = front;
    while(temp != NULL){
        std::cout << temp -> data << std::endl;
        temp = temp->next;
    }
}
