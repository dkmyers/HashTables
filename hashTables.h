#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
void incrementBookByObject(struct book* givenBook);
void decrementBookByObject(struct book* givenBook);
void addBook(char* bookName);
void decBook(char* bookName);
void deleteBook(struct book* givenBook);
void printLibrary(void);
void printBook(char* bookName);

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
		hashVal += (bookName[i] + i);
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
void incrementBookByObject(struct book* givenBook) {
	givenBook->quantity += 1;

}

void decrementBookByObject(struct book* givenBook) {
	givenBook->quantity -= 1;
}

void addBook(char* bookName) {
	//given the name of the book being searched, find its location in library array
	int hashResult = hashFunction(bookName);
	struct book* bookObj = library[hashResult];

	//check that this book has been initialized already
	if (!bookObj) {
		bookObj = addNewBook(bookName);
		library[hashResult] = bookObj;
	}
	else {
		incrementBookByObject(bookObj);
	}

}

void decBook(char* bookName) {
	//given the name of the book being searched, find its location in library array
	int hashResult = hashFunction(bookName);
	struct book* bookObj = library[hashResult];

	//check that this book has been initialized already
	if (bookObj) {
		decrementBookByObject(bookObj);
		//check if book is gone entirely, in which case its spot in library is removed
		if (bookObj->quantity < 1) {
			library[hashResult] = NULL;
		}
	}
	else {
		//Book was not found
	}
}

void printLibrary(void) {
	printf("\n________________Library Contents________________\n");
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (library[i]) {
			printf("Position: %d | Name: %s | Quantity: %d\n", i, library[i]->name, library[i]->quantity);
		}
	}
	printf("________________________________________________\n");
}

void printBook(char* bookName) {
	int hashResult = hashFunction(bookName);
	if (library[hashResult]) {
		printf("\nPosition: %d | Name: %s | Quantity: %d\n", hashResult, library[hashResult]->name, library[hashResult]->quantity);
	}
	else {
		//Book was not found
	}
}