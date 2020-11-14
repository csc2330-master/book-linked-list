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

}

List::~List() {

}

bool List::Insert(const Book &book, unsigned int position) {
	return false;
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
