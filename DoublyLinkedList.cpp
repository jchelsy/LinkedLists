#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;


Node* DoublyLinkedList::nodeExists(int k)
{
	Node* temp = NULL;
	Node* ptr = head;

	while (ptr != NULL) {
		if (ptr->key == k) {
			temp = ptr;
		}
		ptr = ptr->next;
	}

	return temp;
}


void DoublyLinkedList::appendNode(Node* n)
{
	// Check if a Node with the same key-value already exists:
	if (nodeExists(n->key) != NULL) {
		cout << "ERROR! Node already exists with key-value: " << n->key << ". Try again!" << endl;
	}
	// If it checks out:
	else {
		// If this is the 1st iteration (no nodes yet):
		if (head == NULL) {
			head = n;
			cout << "Node Appended as Head Node" << endl;
		}
		// Otherwise (if the list DOES have something in it):
		else {
			// Create pointer var
			Node* ptr = head;

			// Find the head
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			// Set next pointer from NULL to the one being added
			ptr->next = n;
			n->previous = ptr;

			cout << "Node Appended" << endl;
		}
		
	}
}


void DoublyLinkedList::prependNode(Node* n)
{
	// Check if a Node with the same key-value already exists:
	if (nodeExists(n->key) != NULL) {
		cout << "ERROR! Node already exists with key-value: " << n->key << ". Try again!" << endl;
	}
	// If it checks out:
	else {
		// If this is the 1st iteration (no nodes yet):
		if (head == NULL) {
			head = n;
			cout << "Node Prepended as Head Node" << endl;
		}
		// Otherwise (if the list DOES have something in it):
		else {
			head->previous = n;
			n->next = head;
			head = n;

			cout << "Node Prepended" << endl;
		}
	}
}


void DoublyLinkedList::insertNodeAfter(int k, Node* n)
{
	// Declare a temporary pointer if the Node exists
	Node* ptr = nodeExists(k);

	// Check if the key-value exists
	if (ptr == NULL) {
		cout << "ERROR! No node exists with key-value: " << k << endl;
	}
	// Otherwise (the value DOES exist):
	else {
		// Check if a Node with the same key-value already exists:
		if (nodeExists(n->key) != NULL) {
			cout << "ERROR! Node already exists with key-value: " << n->key << ". Try again!" << endl;
		}
		// If it checks out:
		else {
			Node* nextNode = ptr->next;

			// Inserting at the end of the List
			if (nextNode == NULL) {
				ptr->next = n;
				n->previous = ptr;

				cout << "Node inserted at the END" << endl;
			}

			// Inserting in-between the List
			else {
				n->next = nextNode;
				nextNode->previous = n;
				n->previous = ptr;
				ptr->next = n;

				cout << "Node inserted IN-BETWEEN" << endl;
			}
		}
	}
}


void DoublyLinkedList::deleteNodeByKey(int k)
{
	// Declare a temporary pointer if the Node exists
	Node* ptr = nodeExists(k);

	// Check if the key-value exists
	if (ptr == NULL) {
		cout << "ERROR! No node exists with key-value: " << k << endl;
	}
	// Otherwise (the value DOES exist):
	else {
		// Check if the value is the 1st in the List
		if (head->key == k) {
			head = head->next;
			cout << "Node UNLINKED with key-value: " << k << endl;
		}
		// Otherwise (if it's NOT 1st):
		else {
			// Initialize next/previous values
			Node* nextNode = ptr->next;
			Node* prevNode = ptr->previous;

			// Deleting at the end of the List
			if (nextNode == NULL) {
				prevNode->next = NULL;

				cout << "Node deleted at the END" << endl;
			}

			// Deleting in-between the List
			else {
				prevNode->next = nextNode;
				nextNode->previous = prevNode;

				cout << "Node deleted IN-BETWEEN" << endl;
			}
		}
	}
}


void DoublyLinkedList::updateNodeByKey(int k, int d)
{
	// Declare a temporary pointer if the Node exists
	Node* ptr = nodeExists(k);

	if (ptr != NULL) {
		ptr->data = d;

		cout << "Node data updated successfully" << endl;
	}
	else {
		cout << "ERROR! No node exists with key-value: " << k << endl;
	}
}


void DoublyLinkedList::printList()
{
	if (head == NULL) {
		cout << "No Nodes in Doubly-Linked List";
	}
	else {
		cout << endl << "Doubly-Linked List Values: ";
		Node* temp = head;

		while (temp != NULL) {
			cout << "(" << temp->key << "," << temp->data << ") <--> ";
			temp = temp->next;
		}
	}
}