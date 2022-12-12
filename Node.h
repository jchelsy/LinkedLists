#pragma once

class Node {
public:
	int key;
	int data;
	Node* next;
	Node* previous;

	Node() {
		key = 0;
		data = 0;
		next = NULL;
		previous = NULL;
	}
	Node(int k, int d) {
		key = k;
		data = d;
	}
};


/*
class Node {
public:
	double data;	// data value
	Node* next;		// pointer to the next value
};
*/
