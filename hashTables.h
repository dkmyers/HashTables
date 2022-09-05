#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define enumerators used in these libraries
enum {
	BOOK_NAME_LENGTH = 255,
	HASH_TABLE_SIZE = 10
};


struct book {
	int quantity;
	char* name;
};

int hashFunction(char* bookName);
struct book* addNewBook(char* bookName);
int incrementBook(struct book* givenBook);

//returns hash of book's name
int hashFunction(char* bookName) {
	int bookNameLength = strnlen_s(bookName, BOOK_NAME_LENGTH);
	int hashVal = 0;
	for (int i = 0; i < bookNameLength; i++) {
		hashVal += bookName[i];
		hashVal = hashVal * bookName[i] % HASH_TABLE_SIZE;
	}
	return hashVal;
}

struct book* addNewBook(char* bookName) {
	//allocated memory for new book
	struct book* newBook = (struct book*)malloc(sizeof(struct book));
	
	//check that new book exists, then assign values
	if (newBook) {
		//put value into variable
		newBook->name = bookName;
		newBook->quantity = 1;
	}
	return newBook;
}

//increases the quantity of a book in the library by 1
int incrementBook(struct book* givenBook) {
	givenBook->quantity += 1;
	return givenBook->quantity;	
}