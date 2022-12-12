#include <iostream>
#include <string>
#include <exception>
#include "DoublyLinkedList.h"

using namespace std;


int main()
{
	DoublyLinkedList obj;
	int option;
	int key1, k1, data1;

	do {
		obj.printList();
		cout << endl << endl;

		cout << "What do you want to do? Select an option # OR enter 0 (to exit)." << endl;
		cout << "1.  Append Node (insert at end)" << endl;
		cout << "2.  Prepend Node (insert at beginning)" << endl;
		cout << "3.  Insert Node (after key)" << endl;
		cout << "4.  Update Node (by key)" << endl;
		cout << "5.  Delete Node (by key)" << endl;
		cout << endl;

		cin >> option;
		Node* n1 = new Node();

		switch (option) {
		case 0:
			break;
		case 1:
			system("cls");
			cout << "Append Node - \nEnter key & data of the Node to be Appended." << endl << endl;
			cout << "Key: ";
			cin >> key1;
			cout << "Data: ";
			cin >> data1;
			system("cls");

			n1->key = key1;
			n1->data = data1;
			obj.appendNode(n1);

			break;
		case 2:
			system("cls");
			cout << "Prepend Node - \nEnter key & data of the Node to be Prepended." << endl << endl;
			cout << "Key: ";
			cin >> key1;
			cout << "Data: ";
			cin >> data1;
			system("cls");

			n1->key = key1;
			n1->data = data1;
			obj.prependNode(n1);

			break;
		case 3:
			system("cls");
			cout << "Insert Node After - \nEnter key of existing Node after which you want to Insert new Node." << endl << endl;
			cout << "Key: ";
			cin >> k1;
			cout << endl << "Enter key & data of the New Node." << endl << endl;
			cout << "Key: ";
			cin >> key1;
			cout << "Data: ";
			cin >> data1;
			system("cls");

			n1->key = key1;
			n1->data = data1;
			obj.insertNodeAfter(k1, n1);

			break;
		case 4:
			system("cls");
			cout << "Update Node By Key - \nEnter key & NEW data to be updated." << endl << endl;
			cout << "Key: ";
			cin >> key1;
			cout << "New Data: ";
			cin >> data1;
			system("cls");

			obj.updateNodeByKey(key1, data1);

			break;
		case 5:
			system("cls");
			cout << "Delete Node By Key - \nEnter key of the Node to be deleted." << endl << endl;
			cout << "Key: ";
			cin >> k1;
			system("cls");

			obj.deleteNodeByKey(k1);

			break;
		case 6:
			system("cls");
		default:
			system("cls");
			cout << "ERROR! Please enter a valid option #" << endl << endl;
		}

	} while (option != 0);

	return 0;
}