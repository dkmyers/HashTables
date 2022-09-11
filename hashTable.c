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
	
	addBook("This is a test");
	addBook("This is a test");
	addBook("This is a test");
	addBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");
	decBook("Does My Dentist Want to Eat My Brain");

	printLibrary();

	printBook("You passed the test");
	printBook("This is a test");

	//free the memory used to store the hash table
	deleteHashTable();
	return 0;
}