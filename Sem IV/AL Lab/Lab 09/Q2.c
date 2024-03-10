// C program for the above approach
#include <stdio.h>
#include <stdlib.h>

struct HashNode {
	int key;
	int value;
};

const int capacity = 20;
int size = 0;
int comp=0;

struct HashNode** arr;

// Function to add key value pair
void insert(int key, int V)
{

	struct HashNode* temp= (struct HashNode*)malloc(sizeof(struct HashNode));
	temp->key = key;
	temp->value = V;

	int hashIndex = key % capacity;

	while (arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
		hashIndex++;
		hashIndex %= capacity;
	}
	if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
		size++;

	arr[hashIndex] = temp;
}

int find(int key)
{

	int hashIndex = (key % capacity);

	int counter = 0;

	while (arr[hashIndex] != NULL) {

		int counter = 0;
		comp++;
		if (counter++ > capacity)
			break;

		if (arr[hashIndex]->key == key)
			return arr[hashIndex]->value;

		hashIndex++;
		hashIndex %= capacity;
	}
	return -1;
}

int main()
{
	arr = (struct HashNode**)malloc(sizeof(struct HashNode*)* capacity);
	for (int i = 0; i < capacity; i++)
		arr[i] = NULL;

	insert(1, 5);
	insert(2, 15);
	insert(3, 20);
	insert(4, 7);
	insert(5, 25);

	if (find(5) != -1){
		printf("Value of Key 5: %d\n", find(5));
		printf("Total comparisons: %d", comp);
	}
	else
		printf("Key 5 does not exists\n");
}
