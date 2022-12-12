#pragma once
#include <cstddef>
#include "Node.h"


class DoublyLinkedList {
public:
	Node* head;

	DoublyLinkedList() { head = NULL; }
	DoublyLinkedList(Node* n) { head = n; }

	Node* nodeExists(int);
	void appendNode(Node*);
	void prependNode(Node*);
	void insertNodeAfter(int, Node*);
	void deleteNodeByKey(int);
	void updateNodeByKey(int, int);
	void printList(void);
};