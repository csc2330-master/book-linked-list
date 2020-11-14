//
// Created by Arias Arevalo, Carlos on 11/13/20.
//

#ifndef BOOK_LINKED_LIST_BOOK_H
#define BOOK_LINKED_LIST_BOOK_H


#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Book {
	string _name;
	double _price;
public:
	Book(const string&, double);
	Book(const Book&);
	string ToString()const;
	void Write(ostream&)const;
	bool Read(istream&);
	double GetPrice()const;
	bool Equals(const Book&)const;
};


#endif //BOOK_LINKED_LIST_BOOK_H
