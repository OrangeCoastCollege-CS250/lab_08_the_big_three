#include "DoublyList.h"

DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

void DoublyList::insertBack(int elem)
{
	Node *newNode = new Node(elem, last, NULL);

	if (first == NULL)
		first = newNode;
	else
		last->setNext(newNode);

	last = newNode;
	++count;
}

void DoublyList::insertBack(const int a[], int numOfElem)
{
	for (int i = 0; i < numOfElem; ++i)
		insertBack(a[i]);
}

int DoublyList::getFirst() const
{
	if (first == nullptr)
		return 0;
	else
		return first->getData();
}

int DoublyList::getLast() const
{
	if (first == nullptr)
		return 0;
	else
		return last->getData();
}

int DoublyList::getNumOfElem() const
{
	return count;
}

Node* DoublyList::getPrevOfFirst() const
{
	if (first == nullptr)
		return 0;
	else
		return first->getPrev();
}

Node* DoublyList::getNextOfLast() const
{
	if (first == nullptr)
		return 0;
	else
		return last->getNext();
}

// getFirstNodeAddress
Node& DoublyList::getFirstNodeAddress() const
{
	return *first; // return the address of the node first is pointing to
}

// getLastNodeAddress
Node& DoublyList::getLastNodeAddress() const
{
	return *last; // return the address of the node last is pointing to
}

void DoublyList::reversePrint() const
{
	if (first == nullptr)
		cout << "List is empty.";
	else
	{
		Node *temp = last;

		while (temp != NULL)
		{
			cout << temp->getData() << " ";
			temp = temp->getPrev();
		}
	}
}

void DoublyList::destroyList()
{
	Node  *temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	last = nullptr;
	count = 0;
}

DoublyList::~DoublyList()
{
	destroyList();
}


