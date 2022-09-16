#include "hashTables.h"

int main(void) {
	//Set up hash table and initialize values to NULL
	initializeHashTable();

	addBook("Does My Dentist Want to Eat My Brain");
	addBook("Does My Dentist Want to Eat My Brain");

	addBook("Tim");

	addBook("Castles and Sieges");
	addBook("Castles and Sieges");
	addBook("Castles and Sieges");
	addBook("Castles and Sieges");
	addBook("Castles and Sieges");
	addBook("Castles and Sieges");

	printLibrary();
	addBook("You passed the test");
	addBook("You passed the test");
	addBook("You passed the test");
	addBook("This is a test");
	addBook("Tim");
	addBook("Joe");
	addBook("J");
	addBook("K");
	addBook("ABC");
	addBook("ACD");
	addBook("This is a test");
	addBook("This is a test");
	addBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");
	decBook("You passed the test");
	decBook("This is a test");
	decBook("This is a test");
	printLibrary();
	
	//printf("%d | %d", hashFunction("You passed the test"), hashFunction("This is a test"));
	
	//printBook("This is a test");

	//free the memory used to store the hash table
	deleteHashTable();
	return 0;
}