#include "book.h"
#include "list.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

List* CommonBooks(const List& a, const List& b);

int main(int argc, char* argv[]){
	List myList, yourList;
	myList.Insert(Book("Julia", 2.99), 0);
	myList.Insert(Book("Heroes", 1.45), 1);
	myList.Insert(Book("Mar", 1.11), 2);

	yourList.Insert(Book("Mar", 1.11), 0);
	yourList.Insert(Book("Life", 4.45), 1);
	yourList.Insert(Book("Warrior", 0.11), 2);

	List* hisBooks = CommonBooks(myList, yourList);
	hisBooks->Write(cout);
	delete hisBooks;

	return 0;
}

List* CommonBooks(const List& a, const List& b){
	Book* book1 = nullptr;
	Book* book2 = nullptr;
	List* retVal = new List();
	for (int i = 0; i < a.GetSize(); ++i) {
		book1 = a.Get(i);
		if (retVal->IndexOf(*book1) != -1)
			continue;
		for (int j = 0; j < b.GetSize(); ++j) {
			book2 = b.Get(j);
			if (book1->Equals(*book2)){
				retVal->Insert(*book1, retVal->GetSize());
				break;
			}
		}
	}
	return retVal;
}
