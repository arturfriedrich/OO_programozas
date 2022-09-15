// OOP-2021-osz-gyak-02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Node {
	int value;
	Node* next;
public:
	Node(int v) : value(v), next(nullptr) {}
	void setNext(Node* n) { next = n; }
	void setValue(int v) { value = v; }
	int getValue() { return value; }
	Node* getNext() { return next; }
};

class IntLinkedList {
	//std::vector<Node> nodevec;
	Node* head;
	Node* last;
public:
	IntLinkedList() : head(nullptr), last(nullptr) {}
	~IntLinkedList() {
		std::cout << "Destructor called" << std::endl;
		Node* toDelete = head;
		while (toDelete != nullptr) {
			Node* temp = toDelete;
			toDelete = toDelete->getNext();
			std::cout << "Delete node w/ value " << temp->getValue() << std::endl;
			delete temp;
			
		}
	}
	IntLinkedList& addNode(int val) {
		if (last != nullptr) {
			last->setNext(new Node(val));
			last = last->getNext();
		}
		else {
			head = new Node(val);
			last = head;
		}
		return *this;
	}
	void print() {
		std::cout << "IntLinkedList: ";
		Node* currentNode = head;
		while (currentNode != nullptr) {
			if (currentNode->getNext()) {
				std::cout << currentNode->getValue() << ", ";
			}
			else {
				std::cout << currentNode->getValue() << std::endl;
			}
			currentNode = currentNode->getNext();
		}
	}
	Node& operator[](int inx) {
		// itt meg foglalkozni kell azzal az esettel, ha a lista ures...
		Node* currentNode = head;
		int currentInx = 0;
		//Node& retval = *head;
		Node* retval = head;
		while (currentInx <= inx && currentNode != nullptr) {
			// hiba! nem valtoztathato meg, hogy referencia mire hivatkozik!
			//retval = *currentNode;
			retval = currentNode; // ha pointer, akkor igen!
			currentNode = currentNode->getNext();
			currentInx++;
		}
		return *retval; // a vegen *retval, mert vegul most is referenciat adunk vissza
	}
};

void func() {
	IntLinkedList mylist;
	Node testNode(10);
	mylist.addNode(10).addNode(15).addNode(18).addNode(19);
	mylist.print(); // IntLinkedList: 10, 15, 18
	//std::cout << "Value of element 1 =" << mylist[1] << std::endl;
	//std::cout << "Value of element 20 =" << mylist[20] << std::endl;
	mylist.print();
	std::cout << "Value of element 0 =" << mylist[0].getValue() << std::endl;
	mylist.print();
	std::cout << "Value of element 1 =" << mylist[1].getValue() << std::endl;
	mylist.print();
	std::cout << "Value of element 20 =" << mylist[20].getValue() << std::endl;
	mylist.print();
	mylist[1].setValue(18);
	std::cout << mylist[1].getValue() << std::endl;
	mylist.print();
}

int main()
{
	char c;
	for (int i = 0; i < 5; i++) {
		func();
		std::cout << "====" << std::endl;
	}
}

