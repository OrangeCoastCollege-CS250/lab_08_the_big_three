/*
	Name header
*/

/*
	After you completed the implementation, answer the following questions.

	1) Why are the parameter lists in the testCopyConstructor and 
	   testOverloadedAssignment functions passed by VALUE and not reference?
	   
	   Answer:


	2) When the function testOverloadedAssignment is called, why is being 
	   re-directed to the copy constructor? 

	   Answer:


	3) When the function testOverloadedAssignment is called, why is the list on
	   the right of the assignment operator being checked before the list 
	   on the left?

	   Answer:


	4) The first testing case for the overloaded assignment operator compares 
	   a list to itself (line 6). Shouldn't an error message be displayed? 
	   Why is it not displaying?

	   Answer:


*/

#include "DoublyList.h"

// Overloaded insertion operator
ostream& operator<<(ostream& out, const DoublyList& d) {
	if (d.count > 0)
	{
		Node * curr = d.first;
		while (curr != nullptr) 
		{
			out << curr->getData() << " "; 
			curr = curr->getNext();
		}
	}
	else
	{
		cerr << "List is empty.";
	}
	return out;
}

// Copy constructor
DoublyList::DoublyList(const DoublyList& other) {
	first = nullptr;
	last = nullptr;
	count = other.count;
	Node * curr = other.first;
	while(curr != nullptr) {
		insertBack(curr->getData());
		curr = curr->getNext();
	}
}

// Overloaded Assignment operator
DoublyList& DoublyList::operator=(const DoublyList& rightSide) {
	if (&rightSide != this)
	{
		Node * rightCurr = rightSide.first;
		Node * curr = first;
		if (count == 0) {
			while (curr != nullptr) {
				insertBack(rightCurr->getData());
				rightCurr = rightCurr->getNext();
			}
		}
		else if (rightSide.count == 0) destroyList();
		else if (rightSide.count < count) 
		{
			while (rightCurr != nullptr)
			{
				curr->setData(rightCurr->getData());
				rightCurr = rightCurr->getNext();
				curr = curr->getNext();
			}
			last = curr->getPrev();
			last->setNext(nullptr);
			Node * temp = curr;
			curr = curr->getNext();
			while (curr != nullptr)
			{
				delete temp;
				temp = curr;
				curr = curr->getNext();
			}
			count = rightSide.count;
		}
		else if (rightSide.count > count) {
			first->setData(rightCurr->getData());
			curr = curr->getNext();
			rightCurr = rightCurr->getNext();
			while (curr != nullptr) {
				curr->setData(rightCurr->getData());
				rightCurr = rightCurr->getNext();
				curr = curr->getNext();
			}
			while (rightCurr != nullptr) {
				insertBack(rightCurr->getData());
				rightCurr = rightCurr->getNext();
			}
		}
		count = rightSide.count;
	}
	else
		cerr << "Attempted assignment to itself" << endl;
	
	return *this;
}
