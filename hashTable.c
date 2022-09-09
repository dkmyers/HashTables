#include "hashTables.h"

int main(void) {
	//Set up hash table and initialize values to NULL
	initializeHashTable();

	printf("Does My Dentist Want to Eat My Brain -> %d\n", hashFunction("Does My Dentist Want to Eat My Brain"));
	printf("Of Ice and Ent -> %d\n", hashFunction("Of Ice and Ent"));
	printf("Does My Dentist Want to Eat My Brain -> %d\n", hashFunction("Does My Dentist Want to Eat My Brain"));


	//free the memory used to store the hash table
	deleteHashTable();
	return 0;
}