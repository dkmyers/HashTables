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
int addBook(char* bookName);
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
		hashVal += (bookName[i]);
		hashVal = (hashVal*bookName[i]) % HASH_TABLE_SIZE;

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

int addBook(char* bookName) {
	if (!bookName) {
		return 0;
	}

	//given the name of the book being searched, find its location in library array
	int hashResult = hashFunction(bookName);
	struct book* bookObj = library[hashResult];

	//check that this book has been initialized already
	if (!bookObj) {
		bookObj = addNewBook(bookName);
		library[hashResult] = bookObj;
		return 0;
	}
	else {
		//If this book has been initialized already, check if it's the same book or if this is a collision
		if (strcmp(bookName, library[hashResult]->name) == 0) {
			//The given name is the same as the book already in this position, which means we just increment the quantity
			incrementBookByObject(bookObj);
		}
		else {
			int index = 0;
			//The names are different, so we have a collision
			//Iterate through the table until an open space is available
			for (int i = 0; i < HASH_TABLE_SIZE; i++) {
				index = (hashResult + i) % HASH_TABLE_SIZE;
				if (!library[index]) {
					//space is uninitialized
					//Create a new object for this position, rather than use the bookObj one previously
					library[index] = addNewBook(bookName);
					return 0;
				}

				if ((strcmp(bookName, library[index]->name)) == 0) {
					//space is initialized, but containing this book
					incrementBookByObject(library[index]);
					return 0;
				}
			}
			return -1;
		}
	}
	return -1;
}

void decBook(char* bookName) {
	//given the name of the book being searched, find its location in library array
	int hashResult = hashFunction(bookName);
	struct book* bookObj = library[hashResult];

	//check that this book has been initialized already
	if (bookObj && (strcmp(bookName, bookObj->name) == 0)) {
		decrementBookByObject(bookObj);
		//check if book is gone entirely, in which case its spot in library is removed
		if (bookObj->quantity < 1) {
			library[hashResult] = NULL;
		}
	}
	else {
		int index = 0;
		//Book was not found at hashResult
		//check rest of table, because it may have been included via collision
		for (int i = 0; i < HASH_TABLE_SIZE; i++) {
			index = (hashResult + i) % HASH_TABLE_SIZE;
			if (library[index]) {
				if ((strcmp(bookName, library[index]->name)) == 0) {
					//space is initialized, but containing this book
					decrementBookByObject(library[index]);
				}
			}
		}
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

	//check if the given name matches the library's name for this location
	if (strcmp(bookName, library[hashResult]) == 0) {
		if (library[hashResult]) {
			printf("\nPosition: %d | Name: %s | Quantity: %d\n", hashResult, library[hashResult]->name, library[hashResult]->quantity);
		}
		else {
			//Book was not found
			printf("\nBook not found: %s", bookName);
			return;
		}
	}
	else {
		int index = 0;
		for (int i = 0; i < HASH_TABLE_SIZE; i++) {
			//go through entire table until match is found
			index = (hashResult + i) % HASH_TABLE_SIZE;
			if (library[index] && (strcmp(bookName, library[index]) == 0)) {
				//match was found
				printf("\nPosition: %d | Name: %s | Quantity: %d\n", index, library[index]->name, library[index]->quantity);
			}
		}
	}
}