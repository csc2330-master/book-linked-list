#include "book.h"
#include "list.h"

#include <iostream>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::setw;
using std::stringstream;
using std::string;

void Message(const char* message, unsigned int number){
	cout << "Test " << setw(3) << number << " Passed: " << message << endl;
}

int main() {
	// Testing List only, not book.
	List myList;
	unsigned int testNumber = 0;
	assert(myList.GetSize() == 0);
	Message("Empty List", ++testNumber);
	assert(myList.Get(0) == nullptr);
	Message("No first element", ++testNumber);
	assert(myList.IndexOf(Book("No Book", 1.0)) == -1);
	Message("Not found book", ++testNumber);

	// Starting to Insert
	// Some temporary Variables
	Book* book = nullptr;
	assert(myList.Insert(Book("Void", 9.99), 1) == false);
	Message("Invalid Insert Position", ++testNumber);
	assert(myList.Insert(Book("Void", 9.99), 0) == true);
	Message("Insert on Empty List", ++testNumber);
	assert(myList.GetSize() == 1);
	Message("Size after Insert (1)", ++testNumber);
	book = myList.Get(0);
	assert(book != nullptr);
	Message("Retrieved first element", ++testNumber);
	assert(book->Equals(Book("Void", 9.99)));
	Message("Correct Element at Position 0", ++testNumber);
	book = myList.Get(1);
	assert(book == nullptr);
	Message("No second element", ++testNumber);
	assert(myList.Insert((Book("Scarlet", 1.65)), 1) == true);
	assert(myList.GetSize() == 2);
	Message("Size after Insert (2)", ++testNumber);
	book = myList.Get(0);
	assert(book != nullptr);
	Message("Retrieved first element", ++testNumber);
	assert(book->Equals(Book("Void", 9.99)));
	Message("Correct Element at Position 0", ++testNumber);
	book = myList.Get(1);
	assert(book != nullptr);
	Message("Retrieved second element", ++testNumber);
	assert(book->Equals(Book("Scarlet", 1.65)));
	Message("Correct Element at Position 1", ++testNumber);
	book = myList.Get(2);
	assert(book == nullptr);
	Message("No third element", ++testNumber);

	assert(myList.Insert((Book("Shotgun", 4.45)), 0) == true);
	assert(myList.GetSize() == 3);
	Message("Size after Insert (3)", ++testNumber);
	book = myList.Get(0);
	assert(book != nullptr);
	Message("Retrieved first element", ++testNumber);
	assert(book->Equals(Book("Shotgun", 4.45)));
	Message("Correct Element at Position 0", ++testNumber);
	book = myList.Get(1);
	assert(book != nullptr);
	Message("Retrieved second element", ++testNumber);
	assert(book->Equals(Book("Void", 9.99)));
	Message("Correct Element at Position 1", ++testNumber);
	book = myList.Get(2);
	assert(book != nullptr);
	Message("Retrieved third element", ++testNumber);
	assert(book->Equals(Book("Scarlet", 1.65)));
	Message("Correct Element at Position 2", ++testNumber);
	book = myList.Get(3);
	assert(book == nullptr);
	Message("No fourth element", ++testNumber);

	// Insert at beginning on empty and not empty list, and at the end works
	myList.Insert(Book("Naruto", 3.99), myList.GetSize());
	myList.Insert(Book("Fuu", 1.99), myList.GetSize());

	// Test insert in middle on a list with 5 elements
	assert(myList.Insert(Book("Inako", 7.12), 3) == true);
	Message("Insert at middle", ++testNumber);

	assert(myList.GetSize() == 6);
	Message("Size after Insert (6)", ++testNumber);
	book = myList.Get(0);
	assert(book != nullptr);
	Message("Retrieved first element", ++testNumber);
	assert(book->Equals(Book("Shotgun", 4.45)));
	Message("Correct Element at Position 0", ++testNumber);
	book = myList.Get(1);
	assert(book != nullptr);
	Message("Retrieved second element", ++testNumber);
	assert(book->Equals(Book("Void", 9.99)));
	Message("Correct Element at Position 1", ++testNumber);
	book = myList.Get(2);
	assert(book != nullptr);
	Message("Retrieved third element", ++testNumber);
	assert(book->Equals(Book("Scarlet", 1.65)));
	Message("Correct Element at Position 2", ++testNumber);
	book = myList.Get(3);
	assert(book != nullptr);
	Message("Retrieved fourth element", ++testNumber);
	assert(book->Equals(Book("Inako", 7.12)));
	Message("Correct Element at Position 3", ++testNumber);
	book = myList.Get(4);
	assert(book != nullptr);
	Message("Retrieved fifth element", ++testNumber);
	assert(book->Equals(Book("Naruto", 3.99)));
	Message("Correct Element at Position 4", ++testNumber);
	book = myList.Get(5);
	assert(book != nullptr);
	Message("Retrieved sixth element", ++testNumber);
	assert(book->Equals(Book("Fuu", 1.99)));
	Message("Correct Element at Position 5", ++testNumber);
	book = myList.Get(6);
	assert(book == nullptr);
	Message("No seventh element", ++testNumber);

	// All Insert cases tested.
	// Testing IndexOf
	assert(myList.IndexOf(Book("Shotgun", 4.45)) == 0);
	Message("IndexOf element 0", ++testNumber);
	assert(myList.IndexOf(Book("Void", 9.99)) == 1);
	Message("IndexOf element 1", ++testNumber);
	assert(myList.IndexOf(Book("Scarlet", 1.65)) == 2);
	Message("IndexOf element 2", ++testNumber);
	assert(myList.IndexOf(Book("Inako", 7.12)) == 3);
	Message("IndexOf element 3", ++testNumber);
	assert(myList.IndexOf(Book("Naruto", 3.99)) == 4);
	Message("IndexOf element 4", ++testNumber);
	assert(myList.IndexOf(Book("Fuu", 1.99)) == 5);
	Message("IndexOf element 5", ++testNumber);
	assert(myList.IndexOf(Book("None", 0.0)) == -1);
	Message("Index of not found", ++testNumber);

	// Testing Remove
	assert(myList.Remove(5) == true);
	Message("Removed from end", ++testNumber);
	assert(myList.GetSize() == 5);
	Message("Correct size after remove", ++testNumber);
	assert(myList.IndexOf(Book("Shotgun", 4.45)) == 0);
	Message("IndexOf element 0", ++testNumber);
	assert(myList.IndexOf(Book("Void", 9.99)) == 1);
	Message("IndexOf element 1", ++testNumber);
	assert(myList.IndexOf(Book("Scarlet", 1.65)) == 2);
	Message("IndexOf element 2", ++testNumber);
	assert(myList.IndexOf(Book("Inako", 7.12)) == 3);
	Message("IndexOf element 3", ++testNumber);
	assert(myList.IndexOf(Book("Naruto", 3.99)) == 4);
	Message("IndexOf element 4", ++testNumber);
	assert(myList.IndexOf(Book("Fuu", 1.99)) == -1);
	Message("Index not found)", ++testNumber);

	assert(myList.Remove(0) == true);
	Message("Removed from the beginning", ++testNumber);
	assert(myList.GetSize() == 4);
	Message("Correct size after remove", ++testNumber);
	assert(myList.IndexOf(Book("Void", 9.99)) == 0);
	Message("IndexOf element 0", ++testNumber);
	assert(myList.IndexOf(Book("Scarlet", 1.65)) == 1);
	Message("IndexOf element 1", ++testNumber);
	assert(myList.IndexOf(Book("Inako", 7.12)) == 2);
	Message("IndexOf element 2", ++testNumber);
	assert(myList.IndexOf(Book("Naruto", 3.99)) == 3);
	Message("IndexOf element 3", ++testNumber);

	assert(myList.Remove(2) == true);
	Message("Removed from the middle", ++testNumber);
	assert(myList.GetSize() == 3);
	Message("Correct size after remove", ++testNumber);
	assert(myList.IndexOf(Book("Void", 9.99)) == 0);
	Message("IndexOf element 0", ++testNumber);
	assert(myList.IndexOf(Book("Scarlet", 1.65)) == 1);
	Message("IndexOf element 1", ++testNumber);
	assert(myList.IndexOf(Book("Naruto", 3.99)) == 2);
	Message("IndexOf element 3", ++testNumber);

	stringstream output;
	string expected = "Void 9.99\nScarlet 1.65\nNaruto 3.99\n";
	myList.Write(output);
	assert(output.str() == expected);
	Message("Write outputs correctly", ++testNumber);

	return 0;
}
