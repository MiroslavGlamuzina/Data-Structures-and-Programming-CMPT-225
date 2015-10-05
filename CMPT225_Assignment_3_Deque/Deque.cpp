#include "Deque.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////N O D E  C P P  S R C////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node::Node() {
	temp = NULL;
	head = NULL;
	curr = NULL;
}

void Node::AddNode(int data) {
	node* n = new node;
	n->next = NULL;
	n->data = data;

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	} else {
		head = n;
	}
}

void Node::deleteNode(int index) {
	node* delnode = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != index) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		std::cout << index << " was not in the list" << std::endl;
	} else {
		delnode = curr;
		curr = curr->next;
		temp->next = curr;
		if (delnode == head) {
			head = head->next;
			temp = NULL;
		}
		delete delnode;
		std::cout << "The value " << index << " was deleted" << std::endl;
	}
}

void Node::printList() {
	curr = head;
	while (curr != NULL) {
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////D E Q U E  C P P  S R C///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Deque::Deque() {
}

void Deque::insert_front(int item) {

}

void Deque::insert_back(int item) {
}
int Deque::remove_front() {

	return 0;
}
int Deque::remove_back() {

	return 0;
}

int Deque::peek_front() const {
	return 0;

}

int Deque::peek_back() const {
	return 0;
}
bool Deque::empty()const {
	return false;
}

int Deque::size()const {

}

void Deque::deepCopy(const Deque &deque) {

}
void Deque::deleteDeque() {

}

