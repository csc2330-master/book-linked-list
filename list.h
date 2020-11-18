//
// Created by Arias Arevalo, Carlos on 11/13/20.
//

#ifndef BOOK_LINKED_LIST_LIST_H
#define BOOK_LINKED_LIST_LIST_H


#include "book.h"

#include <iostream>
using std::ostream;

class List{
private:
	struct Node{
		Book* book;
		Node* next;
	};
	Node* _head;
	size_t _size;
	List(const List& original);
	const List& operator=(const List& rhs);
public:
	List();
	~List();
	bool Insert(const Book& book, unsigned int position);
	void InsertSorted(const Book& book);
	bool Remove(unsigned int position);
	int IndexOf(const Book& book)const;
	Book* Get(unsigned int position)const;
	void Write(ostream& output)const;
	size_t GetSize()const;
};


#endif //BOOK_LINKED_LIST_LIST_H
