#include "DoubleLinkedList.h"

//Node Class
Node::Node() {
	next = nullptr;
	prev = nullptr;
}

Node::Node(FAString str) {
	next = nullptr;
	prev = nullptr;
	data = str;
}

//DoubleLinkedList Class
DoubleLinkedList::DoubleLinkedList() {
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& dll) {
	head = nullptr;
	tail = nullptr;
	it = nullptr;
	count = 0;
	dll.resetIteration();
	while (dll.hasMore()) {
		this->pushBack(dll.next());
	}
	dll.resetIteration();
}

DoubleLinkedList::~DoubleLinkedList() {
	this->clearList();
}

DoubleLinkedList& DoubleLinkedList::operator = (const DoubleLinkedList& dll) {
	this->clearList();
	while (dll.hasMore()) {
		this->pushBack(dll.next());
	}
	dll.resetIteration();
	return *this;
}

std::ostream& operator << (std::ostream& ostrm, const DoubleLinkedList& dll) {
	dll.resetIteration();
	while (dll.hasMore()) {
		ostrm << dll.it->data << ' ';
		dll.next();
	}
	return ostrm;
}

bool DoubleLinkedList::pushBack(const FAString& str) {
	if (!this->isUnique(str)) return false;
	if (count == 0) {
		it = new Node;
		it->data = str;
		head = it;
		tail = it;
		count++;
		return true;
	}
	tail->next = new Node;
	tail->next->prev = tail;
	tail = tail->next;
	tail->data = str;
	count++;
	return true;
}

bool DoubleLinkedList::insert(const FAString& str) { 
	if (!this->isUnique(str)) return false;
	if (count == 0) {
		it = new Node(str);
		head = it;
		tail = it;
		count++;
		return true;
	}
	if (str < head->data) { //if str is smallest in list
		head->prev = new Node(str);
		head->prev->next = head;
		head = head->prev;
		count++;
		return true;
	}
	this->resetIteration();
	while (this->hasMore()) {
		if (it->next == nullptr) { //if str is largest in list
			it->next = new Node(str);
			it->next->prev = it;
			tail = it->next;
			count++;
			this->resetIteration();
			return true;
		}
		if (str < it->next->data) { //if str goes between nodes
			Node* oldNext = it->next;
			it->next = new Node(str);
			it->next->prev = it;
			it->next->next = oldNext;
			oldNext->prev = it->next;
			count++;
			this->resetIteration();
			return true;
		}
		this->next();
	}
	return false;
}

bool DoubleLinkedList::remove(const FAString& str) {
	this->resetIteration();
	if (count == 0) return false;
	if (count == 1 && str == it->data) { //single node list
		delete it;
		it = nullptr;
		head = nullptr;
		tail = nullptr;
		count--;
		return true;
	}
	if (str == head->data) { //remove head
		head = it->next;
		it = it->next;
		delete it->prev;
		it->prev = nullptr;
		count--;
		return true;
	}
	this->next();
	while (this->hasMore()) {
		if (it->next == nullptr && str == it->data) { //remove tail
			it = it->prev;
			tail = it;
			delete it->next;
			it->next = nullptr;
			count--;
			this->resetIteration();
			return true;
		}
		if (str == it->data) { //remove between nodes
			it->prev->next = it->next;
			it->next->prev = it->prev;
			delete it;
			it = head;
			count--;
			return true;
		}
		this->next();
	}
	return false;
}

int DoubleLinkedList::getCount() const {
	return count;
}

void DoubleLinkedList::resetIteration() const {
	it = head;
}

FAString DoubleLinkedList::next() const {
	FAString returnStr;
	if (it == nullptr) return returnStr;
	returnStr = it->data;
	it = it->next;
	return returnStr;
}

bool DoubleLinkedList::hasMore() const {
	return (it != nullptr);
}

bool DoubleLinkedList::isUnique(const FAString& argStr) {
	this->resetIteration();
	while (this->hasMore()) {
		if (it->data == argStr) {
			this->resetIteration();
			return false;
		}
		this->next();
	}
	this->resetIteration();
	return true;
}

void DoubleLinkedList::clearList() {
	this->resetIteration();
	while (this->hasMore()) {
		if (it->next == nullptr) {
			delete it;
			it = nullptr;
		}
		else {
			this->next();
			delete it->prev;
		}
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}