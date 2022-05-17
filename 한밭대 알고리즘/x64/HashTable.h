#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>



typedef struct NODE {
	int key;
	int Value;
}node;

typedef struct HashTable {
	int tableSize;
	node* table;
}hashTable;

hashTable* CreateHashTable(int tableSize);
void set(hashTable* HT, int key, int value);
int get(hashTable* HT, int key);
void DestroyHashTable(hashTable* HT);
int HashFunction(int key, int tableSize);


#endif	SIMPLE_HASHTABLE_H