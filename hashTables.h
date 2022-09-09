#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define constants and data structures used in these files
enum {
	BOOK_NAME_LENGTH = 255,
	HASH_TABLE_SIZE = 2048
};

struct book {
	int quantity;
	char* name;
};

static struct book* library[HASH_TABLE_SIZE];

//declare functions used in these files
int hashFunction(char* bookName);
struct book* addNewBook(char* bookName);
int incrementBook(struct book* givenBook);

//define functions used in these files
void initializeHashTable() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		library[i] = NULL;
	}
}

void deleteHashTable() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		deleteBook(library[i]);
	}
}

//returns hash of book's name
int hashFunction(char* bookName) {
	int bookNameLength = strnlen_s(bookName, BOOK_NAME_LENGTH);
	int hashVal = 0;
	for (int i = 0; i < bookNameLength; i++) {
		hashVal += bookName[i] * i;
		hashVal = hashVal % HASH_TABLE_SIZE;
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

void deleteBook(struct book* givenBook) {
	if (givenBook) {
		free(givenBook);
	}
}

//increases the quantity of a book in the library by 1
int incrementBook(struct book* givenBook) {
	givenBook->quantity += 1;
	return givenBook->quantity;	
}