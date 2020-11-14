//
// Created by Arias Arevalo, Carlos on 11/13/20.
//

#include "list.h"

List::List(const List &original) {

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
	return false;
}

int List::IndexOf(const Book &book) const {
	return 0;
}

Book *List::Get(unsigned int position) const {
	return nullptr;
}

void List::Write(ostream &output) const {

}

size_t List::GetSize() const {
	return 0;
}
