//
// Created by Arias Arevalo, Carlos on 11/13/20.
//

#include "list.h"

List::List(const List &original) {
	// What is the time complexity of this implementation?
	// Can we do better?
	for (Node* tmp = original._head; tmp != nullptr; tmp = tmp->next)
		Insert(*tmp->book, _size);

}

const List &List::operator=(const List &rhs) {
	return *this;
}

List::List() {
	_head = nullptr;
	_size = 0;
}

List::~List() {

}

bool List::Insert(const Book &book, unsigned int position) {
	if (position > _size)
		return false;
	Node* neo = new Node;
	neo->book = new Book(book);
	neo->next = nullptr;
	if (_size == 0){ // Do we need to check position == 0?
		_head = neo;
	}else if (position == 0){ // Why is this correct?
		neo->next = _head;
		_head = neo;
	}else{ // Why don't we need a "insert at last" case? Does this one work for that case?
		Node* tmp = _head;
		for (unsigned int i=0; i < position - 1; i++){ // Are we sure position - 1 cannot be negative?
			tmp = tmp->next;
		}
		neo->next = tmp->next;
		tmp->next = neo;
	}
	_size++;
	return true;
}

bool List::Remove(unsigned int position) {
	if (position >= _size)
		return false;
	Book* bookToRemove = nullptr;
	Node* tmp = nullptr;
	if (position == 0){
		bookToRemove = _head->book;
		_head->book = nullptr;
		tmp = _head->next;
		_head->next = nullptr;
		delete _head;
		_head = tmp;
	}else{
		tmp = _head;
		for (unsigned int i = 0; i < position - 1; ++i) {
			tmp = tmp->next;
		}
		Node* nodeToRemove = tmp->next;
		bookToRemove =  nodeToRemove->book;
		tmp->next = nodeToRemove->next;
		nodeToRemove->next = nullptr;
		nodeToRemove->book = nullptr;
		delete nodeToRemove;
	}
	delete bookToRemove;
	_size--;
	return true;
}

int List::IndexOf(const Book &book) const {
	Node* tmp = _head;
	for (int i = 0; i < _size; ++i) {
		if (tmp->book->Equals(book))
			return i;
		tmp = tmp->next;
	}
	return -1;
}

Book *List::Get(unsigned int position) const {
	if (position >= _size)
		return nullptr;
	Node* tmp = _head;
	for (int i = 0; i < position; ++i) {
		tmp = tmp->next;
	}
	return tmp->book;
}

void List::Write(ostream &output) const {
	for (Node* tmp = _head; tmp != nullptr; tmp = tmp->next) {
		tmp->book->Write(output);
		output << "\n";
	}
}

size_t List::GetSize() const {
	return _size;
}
