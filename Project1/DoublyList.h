#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), prev(NULL), next(NULL) {}
	Node(int newData, Node *newPrev, Node *newNext)
		: data(newData), prev(newPrev), next(newNext) {}
	int getData() const { return data; }
	Node *getPrev() const { return prev; }
	Node *getNext() const { return next; }
	void setData(const int& newData) { data = newData; }
	void setPrev(Node *newPrev) { prev = newPrev; }
	void setNext(Node *newNext) { next = newNext; }
	bool operator==(const Node& otherNode) { return (this == &otherNode); }
	~Node() {}
private:
	int data;
	Node *prev;
	Node *next;
};


class DoublyList
{
public:
	DoublyList(); 

	void insertBack(int numOfElem);
	void insertBack(const int a[], int numOfElem);

	int getFirst() const;
	int getLast() const;
	int getNumOfElem() const;
	Node* getPrevOfFirst() const;
	Node* getNextOfLast() const;	
	Node& getFirstNodeAddress() const;
	Node& getLastNodeAddress() const;
	
	void reversePrint() const;

	void destroyList();
	~DoublyList();

private:
    Node *first;	// pointer to the first node on the list
    Node *last;		// pointer to the last node on the list
	int count;		// number of nodes in the list
};

#endif