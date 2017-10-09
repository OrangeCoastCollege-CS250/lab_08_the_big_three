/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

#include <iostream>
using namespace std;

//pass by value to preserve original lists
void testCopyConstructor(DoublyList param, int n);
void testOverloadedAssignment(DoublyList calling, DoublyList param, int n);

int main()
{
	int a0[10];
	int a1[20] = { 45 };
	int a2[30] = { 64, 24 };
	int a4[40] = { 13, 54, 12, 34};
	int a7[10] = { 76, 36, 91, 93, 74, 58, 23 };

	DoublyList list0, list1, list2, list4, list7;

	list0.insertBack(a0, 0);
	list1.insertBack(a1, 1);
	list2.insertBack(a2, 2);
	list4.insertBack(a4, 4);
	list7.insertBack(a7, 7);

	cout << "TEST: COPY CONSTRUCTOR" << endl;
	// Copy constructor: calling (empty) - param (empty)
	testCopyConstructor(list0, 1);							// TEST 1
	// Copy constructor: calling (empty) - param (1)
	testCopyConstructor(list1, 2);							// TEST 2
	// Copy constructor: calling (empty) - param (2)
	testCopyConstructor(list2, 3);							// TEST 3
	// Copy constructor: calling (empty) - param (4)
	testCopyConstructor(list4, 4);							// TEST 4
	// Copy constructor: calling (empty) - param (7)
	testCopyConstructor(list7, 5);							// TEST 5

	cout << endl;

	cout << "TEST: OVERLAODED ASSIGNMENT OPERATOR" << endl;
	// Overloaded assignment operator: calling (empty) - param (empty)
	testOverloadedAssignment(list0, list0, 6);								// TEST 6
	// Overloaded assignment operator: calling (empty) - param (1)
	testOverloadedAssignment(list0, list1, 7);								// TEST 7
	// Overloaded assignment operator: calling (empty) - param (2)
	testOverloadedAssignment(list0, list2, 8);								// TEST 8
	// Overloaded assignment operator: calling (empty) - param (4)
	testOverloadedAssignment(list0, list4, 9);								// TEST 9
	// Overloaded assignment operator: calling (empty) - param (7)
	testOverloadedAssignment(list0, list7, 10);								// TEST 10
	// Overloaded assignment operator: calling (1) - param (empty)
	testOverloadedAssignment(list1, list0, 11);								// TEST 11
	// Overloaded assignment operator: calling (1) - param (1)
	testOverloadedAssignment(list1, list1, 12);								// TEST 12
	// Overloaded assignment operator: calling (1) - param (2)
	testOverloadedAssignment(list1, list2, 13);								// TEST 13
	// Overloaded assignment operator: calling (1) - param (4)
	testOverloadedAssignment(list1, list4, 14);								// TEST 14
	// Overloaded assignment operator: calling (1) - param (7)
	testOverloadedAssignment(list1, list7, 15);								// TEST 15
	// Overloaded assignment operator: calling (2) - param (empty)
	testOverloadedAssignment(list2, list0, 16);								// TEST 16
	// Overloaded assignment operator: calling (2) - param (1)
	testOverloadedAssignment(list2, list1, 17);								// TEST 17
	// Overloaded assignment operator: calling (2) - param (2)
	testOverloadedAssignment(list2, list2, 18);								// TEST 18
	// Overloaded assignment operator: calling (2) - param (4)
	testOverloadedAssignment(list2, list4, 19);								// TEST 19
	// Overloaded assignment operator: calling (2) - param (7)
	testOverloadedAssignment(list2, list7, 20);								// TEST 20
	// Overloaded assignment operator: calling (4) - param (empty)
	testOverloadedAssignment(list4, list0, 21);								// TEST 21
	// Overloaded assignment operator: calling (4) - param (1)
	testOverloadedAssignment(list4, list1, 22);								// TEST 22
	// Overloaded assignment operator: calling (4) - param (2)
	testOverloadedAssignment(list4, list2, 23);								// TEST 23
	// Overloaded assignment operator: calling (4) - param (4)
	testOverloadedAssignment(list4, list4, 24);								// TEST 24
	// Overloaded assignment operator: calling (4) - param (7)
	testOverloadedAssignment(list4, list7, 25);								// TEST 25
	// Overloaded assignment operator: calling (7) - param (empty)
	testOverloadedAssignment(list7, list0, 26);								// TEST 26
	// Overloaded assignment operator: calling (7) - param (1)
	testOverloadedAssignment(list7, list1, 27);								// TEST 27
	// Overloaded assignment operator: calling (7) - param (2)
	testOverloadedAssignment(list7, list2, 28);								// TEST 28
	// Overloaded assignment operator: calling (7) - param (4)
	testOverloadedAssignment(list7, list4, 29);								// TEST 29
	// Overloaded assignment operator: calling (7) - param (7)
	testOverloadedAssignment(list7, list7, 30);								// TEST 30

	cout << endl << endl;
	system("Pause");
	return 0;
}

void testCopyConstructor(DoublyList param, int n)
{
	cout << "TEST: " << n << endl;
	cout << "Parameter list: " << param << endl;

	int param_first = param.getFirst();
	int param_last = param.getLast();
	int param_count = param.getNumOfElem();
	Node* param_getPrevOfFirst = param.getPrevOfFirst();
	Node* param_getNextOfLast = param.getNextOfLast();

	DoublyList temp(param);

	cout << "New list (print forward): " << temp << endl;
	cout << "New list (print reverse): ";
	temp.reversePrint();
	if (param_first != temp.getFirst()) cout 
		<< "*** ERROR ***  First node not storing correct value." << endl;
	if (param_last != temp.getLast()) cout 
		<< "*** ERROR ***  Last node not storing correct value. " << endl;
	if (param_count != temp.getNumOfElem()) cout 
		<< "*** ERROR ***  Number of elements is incorrect." << endl;
	if (param_getPrevOfFirst != temp.getPrevOfFirst()) cout 
		<< "*** ERROR ***  Pointer prev of first node is not NULL." << endl;
	if (param_getNextOfLast != temp.getNextOfLast()) cout 
		<< "*** ERROR ***  Pointer next of last node is not NULL." << endl;
	if (param.getNumOfElem() != 0)
	{
		if (param.getFirstNodeAddress() == temp.getFirstNodeAddress()) cout 
			<< "*** ERROR ***  Both lists are pointing to the same first node." << endl;
		if (param.getLastNodeAddress() == temp.getLastNodeAddress()) cout 
			<< "*** ERROR ***  Both lists are pointing to the same first node." << endl;
	}
	
	cout << endl;
}

void testOverloadedAssignment(DoublyList calling, DoublyList param, int n)
{
	cout << "TEST: " << n << endl;
	cout << "Calling list: " << calling << endl; 
	cout << "Parameter list: " << param << endl;

	int calling_first = calling.getFirst();
	int calling_last = calling.getLast();
	int calling_count = calling.getNumOfElem();
	Node* calling_getPrevOfFirst = calling.getPrevOfFirst();
	Node* calling_getNextOfLast = calling.getNextOfLast();

	int param_first = param.getFirst();
	int param_last = param.getLast();
	int param_count = param.getNumOfElem();
	Node* param_getPrevOfFirst = param.getPrevOfFirst();
	Node* param_getNextOfLast = param.getNextOfLast();

	calling = param;

	cout << "... Call overloaded assignment operator... calling = param" << endl;
	cout << "Calling list (print forward): " << calling << endl;
	cout << "Parameter list (print forward): " << param << endl;
	cout << "Calling list (print reverse): ";
	calling.reversePrint();
	cout << endl;
	cout << "Parameter list (print reverse): ";
	param.reversePrint();
	cout << endl;

	if (param_first != calling.getFirst()) cout 
		<< "*** ERROR ***  First node not storing correct value. (Test " << n << ")" << endl;
	if (param_last != calling.getLast()) cout 
		<< "*** ERROR ***  Last node not storing correct value. (Test " << n << ")" << endl;
	if (param_count != calling.getNumOfElem()) cout 
		<< "ERROR: Number of elements is incorrect. (Test " << n << ")" << endl;
	if (param_getPrevOfFirst != calling.getPrevOfFirst()) cout 
		<< "ERROR: Pointer prev of first node is not NULL. (Test " << n << ")" << endl;
	if (param_getNextOfLast != calling.getNextOfLast()) cout 
		<< "ERROR: Pointer next of last node is not NULL. (Test " << n << ")" << endl;
	if (param.getNumOfElem() != 0)
	{
		if (calling.getFirstNodeAddress() == param.getFirstNodeAddress()) cout 
			<< "ERROR: Both lists are pointing to the same first node. (Test " << n << ")" << endl;
		if (calling.getLastNodeAddress() == param.getLastNodeAddress()) cout 
			<< "ERROR: Both lists are pointing to the same first node. (Test " << n << ")" << endl;
	}

	cout << endl;
}