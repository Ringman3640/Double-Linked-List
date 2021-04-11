////
//Name: Franz Alarcon
//Section: A
//Program Name: Program 4 Linked List
//
//Class Description: A doubley linked list class that allows for data 
//  to be inserted alphabetically or at the end of the list. Utilizes
//  the Node class and holds FAStrings.
//
//List of functions and their descriptions:
//  pushBack(const FAString& str) - creates a new node at the end of
//	  the list which holds str. Returns true if str is not already in
//	  the list
//  bool insert(const FAString & str) - creates a new node alphabetically
//	  sorted based on str. Returns true if str is not already in the 
//	  list
//  bool remove(const FAString & str) - searches for str within the list 
//	  and removes it if found. If removed, the function returns true
//  int getCount() const - returns the amount of nodes in the list
//  void resetIteration() const - resets the iterator pointer to point
//	  to the first node, the head node
//  FAString next() const; - increments the iterator and returns the previous
//	  node's data
//  bool hasMore() const - returns true if the iterator is pointing to 
//	  a node. Returns false if iterator points to nullptr
//
//Function overloads: 
//  = operator - sets the current list equal to another list. Returns the 
//	  current list.
//  << operator - outputs all the elements of the list to the ostream with
//	  spaces seperating each string
////

#ifndef DOUBLELINKEDLISK_H
#define DOUBLELINKEDLIST_H

#include "FAString.h"

class Node {
public: 
	FAString data;
	Node* next;
	Node* prev;

	Node();
	Node(FAString str);
};

class DoubleLinkedList {
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& dll);
	~DoubleLinkedList();

	DoubleLinkedList& operator = (const DoubleLinkedList& dll);
	friend std::ostream& operator << (std::ostream& ostrm, const DoubleLinkedList& dll);

	bool pushBack(const FAString& str);
	bool insert(const FAString& str);
	bool remove(const FAString& str);
	int getCount() const;
	void resetIteration() const;
	FAString next() const;
	bool hasMore() const;

private:
	Node* head;
	Node* tail;
	mutable Node* it;
	int count;
	bool isUnique(const FAString& argStr);
	void clearList();
};

#endif