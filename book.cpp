//
// Created by arias on 11/25/2019.
//

#include "book.h"

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::stringstream;

Book::Book(const string& name, double price): _name(name), _price(price){

}
Book::Book(const Book& book): _name(book._name), _price(book._price){

}
string Book::ToString()const{
	stringstream ss;
	ss << "Title: " << setw(20) << _name << ", Price: "
	   << setprecision(2) << fixed << setw(8) << _price;
	return ss.str();
}
void Book::Write(ostream& output)const{
	output << _name << " " << setprecision(2) << fixed << _price;
}
bool Book::Read(istream& input){
	input >> _name >> _price;
	return !input.fail();
}
double Book::GetPrice()const{
	return _price;
}
bool Book::Equals(const Book& book)const{
	return _name == book._name;
}
