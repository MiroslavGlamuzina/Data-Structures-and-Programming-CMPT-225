#ifdef _DEQUE_

//Constructor
//PARAM:
//PRE:
//POST: New Deque object is created.
template <class T>
Deque<T>::Deque(): 
        front(NULL), 
        back(NULL) 
{};
//Copy constructor
//PARAM: const reference to a Deque object
//PRE: same as deepCopy()
//POST: same as deepCopy()
template <class T>
Deque<T>::Deque(const Deque &deq)
{
    deepCopy(deq);
}
//Destructor
//PARAM:
//PRE:
//POST: Deque object is destroyed.
template <class T>
Deque<T>::~Deque()
{
    deleteDeque();
}
//Overloaded assignment operator.
//Copies parameter into the calling object if the references are equal.
//PARAM: const reference to a Deque object
//PRE: 
//POST: Returns a dereference this pointer to the calling object.
template <class T>
Deque<T>& Deque<T>::operator=(const Deque<T> &deq)
{
    if(this != &deq){
        deleteDeque();
        deepCopy(deq);
    }
    return *this;
}
//Inserts an element at the front of the deque.
//PARAM: item = data to be inserted at the front of the deque.
//PRE: deque must not be empty.
//POST: item is inserted at the front of the deque.
template <class T>
void Deque<T>::insert_front(T item)
{
    Node<T>* temp = new Node<T>(item);
    if(empty()){
        front = back = temp;
    }
    else {
        temp->next = front;
        front = temp;
    }
}

//Inserts an element at the back of the deque.
//PARAM: item = data to be inserted at the back of the deque.
//PRE: deque must not be empty.
//POST: item is inserted at the back of the deque.
template <class T>
void Deque<T>::insert_back(T item)
{
    Node<T> *temp = new Node<T>(item);
    if(empty()){
        back = front = temp;
    }
    else {
        temp->next = back;
        back = temp;
    }
}
//Removes and returns the data element at the front of the deque.
//PARAM:
//PRE: deque most not be empty.
//POST: returns and removes result, which is the data element at the front of 
//      the deque.
template <class T>
T Deque<T>::remove_front()
{
    T result = front->data;
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    front = front->next;
    return result;
}

//Removes and returns the item at the back of the deque.
//PARAM:
//PRE: deque must not be empty.
//POST: returns and removes result, which is the data element at the back of 
//      the deque. Operates in O(n) time.
template <class T>
T Deque<T>::remove_back()
{
    T result = back->data;
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    else {
        //If front == back, that means that the Deque is empty
        Node<T> *tempBack = back;
        if(front == back){
            front = NULL;
        }
        else {
            Node<T> *temp = front;
            while(temp->next != back){
                temp = temp->next;
            }
            back = temp;
            back->next = NULL;
        }
        delete tempBack;
    }
    return result;
}

//Returns the data element at the front of the deque without deletion.
//PARAM:
//PRE:
//POST: return front->data.
template <class T>
T Deque<T>::peek_front()
{
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    T result = front->data;
    return result;
}

//Returns the data element at the back of the deque without deletion.
//PARAM:
//PRE:
//POST: returns back->data. 
template <class T>
T Deque<T>::peek_back()
{
    if(empty()){
        throw std::runtime_error(errorMsg);
    }
    T result = back->data;
    return result;
}
//Checks to see if the deque is empty.
//PARAM:
//PRE: size() returns an integer value.
//POST: True if size() == 0, false otherwise.
template <class T>
bool Deque<T>::empty()
{
    return size() == 0;
}

//Returns the size of the deque.
//PARAM:
//PRE:
//POST: Increments count until temp == NULL, then returns count.
template <class T>
int Deque<T>::size()
{
    int count = 0;
    Node<T>* temp = front;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
//Removes all the items from the Deque and deallocates dynamic memory 
//associated with nodes
//PARAM: 
//PRE:
//POST: Deque is empty
template <class T>
void Deque<T>::deleteDeque()
{
    Node<T>* temp = front;
    // Traverse list
    while(temp != NULL){
        temp = front->next;	    
        delete front;	
	front = temp;	
    }	     
    front = NULL;
}

// Makes a deep copy of a Deque object
// PARAM: deq is the deque to copied
// PRE: Calling object is empty
// POST: Deque contents are identical to deq
template <class T>
void Deque<T>::deepCopy(const Deque & deq)
{
	
    front = NULL;		
    // Only copy if ls is non-empty	
    if(deq.front != NULL){
        Node<T>* original = deq.front;
        Node<T>* copy;
        // Copy the front
        copy = new Node<T>(original->data, NULL);
        front = copy;
        original = original->next;       
        // Traverse the original copying each node	
	while(original != NULL){
            copy->next = new Node<T>(original->data, NULL);	         
            copy = copy->next;                                 
            original = original->next;
	}
    }
}
#endif //_DEQUE_

