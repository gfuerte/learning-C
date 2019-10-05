#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node* next;
};

struct node* hashtable[1000];
int getKey(int value);
void insert(int value, int key);
void search(int value, int key);

int getKey(int value) {
	int size = 1000;
	int key = value % size;
	return key;
}	

void insert(int value, int key){
	struct node* temp = malloc(sizeof(struct node));
	temp->value = value;

	if (hashtable[key] != NULL) {
		struct node* ptr = hashtable[key];
		struct node* prev = NULL;
		while (ptr != NULL) {
			
			if (ptr->value == value) {
				free(temp);
				printf("duplicate\n");
				break;
			}

			if(ptr->value > value) {
				if (prev != NULL) {
					prev->next = temp;
					temp->next = ptr;
					printf("inserted\n");
					break;
				} else {
					temp->next = ptr;
					hashtable[key] = temp;
					printf("inserted\n");
					break;
				}
			}

			if (ptr->next == NULL) {
				ptr->next = temp;
				temp->next = NULL;
				printf("inserted\n");
				break;
			}

			prev = ptr;
			ptr = ptr->next;
		}

	} else {

		hashtable[key] = temp;
		temp->next = NULL;
		printf("inserted\n");
		
	}

	
}

void search(int value, int key) {
	struct node* ptr = hashtable[key];
	int check = 0;

	if (hashtable[key] != NULL) {
		while (ptr != NULL) {
			if (ptr->value == value) {
				check = 1;
			}

			ptr = ptr->next;
		}
	}	

	if (check == 1) {
		printf("present\n");
	} else {
		printf("absent\n");
	}
}

int main(int argc, char** argv) {
	
	if (argc != 2) {
		printf("insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("error\n");
		exit(0);
	}

	int q = 0;
	if(fscanf(fp, "%d\n", &q) == EOF) {
		int error = 0;
		printf("%d\n", error);
		exit(0);
	} 

	int val;
	char letter;

	while(fscanf(fp, "%c" "%d", &letter, &val) != EOF) {

		int absolute = abs(val);
		int key = getKey(absolute);

		if (letter == 'i') {
			insert(val, key);
		}

		if (letter == 's') {
			search(val, key);
		}
	}
		

	return 0;

}
