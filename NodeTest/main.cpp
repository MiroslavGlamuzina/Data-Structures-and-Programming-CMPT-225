#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

int main() {
	node* n;
	n = new node;
	n->data = 1;
	node* t;
	t = n;

	n = new node;
	n->data = 2;
	t->next = n;

	t = t->next;

	n = new node;
	n->data = 3;
	t->next = n;

	n = new node;
	t = t->next;
	n->data = 4;

	t->next = n;

	n->next = NULL;

	cout << t->data << endl;
	cout << n->data << endl;

	std::cout << "test" << std::endl;
	return 0;
}

