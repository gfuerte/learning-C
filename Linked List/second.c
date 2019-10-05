#include<stdio.h>
#include<stdlib.h>


struct node {
	int value;
	struct node* next;
};

struct node* head = NULL;
void insert(int value);
void delete(int value);
void print_list();
int count();

void print_list() {
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d	", temp->value);
		temp = temp->next;
	}
}

int count() {
	struct node* temp = head;
	int n = 0;
	while (temp != NULL) {
		n++;
		temp = temp->next;
	}

	return n;
}

void insert(int value) {
	struct node* temp = malloc(sizeof(struct node));
	temp-> value = value;
	if (head == NULL) {
		head = temp;
		temp->next = NULL;
	} else {
		struct node* ptr = head;
		struct node* prev = NULL;
		while (ptr != NULL) {
	
			if (ptr->value == value){
				free(temp);
				break;
			}

			if(ptr->value > value) {
				if (prev != NULL) {
					prev->next = temp;
					temp->next = ptr;
					break;
				} else {
					temp->next = ptr;
					head = temp;
					break;
				}
			}

			if (ptr->next == NULL) {
				ptr->next = temp;
				temp->next = NULL;
				break;
			}

			prev = ptr;
			ptr = ptr->next;
		}
	}
}

void delete(int value){

	struct node* ptr = head;
	struct node* prev = NULL;
	
	while (ptr != NULL){
		if(ptr-> value == value && prev == NULL) {
			struct node* temp = ptr;
			ptr = ptr->next;
			head = ptr;
			free(temp);
			break;
		}	
		if(ptr->value == value && ptr->next == NULL){
			struct node* temp = ptr;
			prev->next = NULL;
			free(temp);
			break;
		}
		if(ptr->value == value) {
			struct node* temp = ptr;
			ptr = ptr->next;
			prev->next = ptr;
			free(temp);
			break;
		}

		prev = ptr;
		ptr = ptr->next;
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("error\n");
		exit(0);
	}

	int num = 0;
	if(fscanf(fp, "%d\n", &num) == EOF) {
		int error = 0;
		printf("%d\n", error);
		exit(0);
	}
	
	int val = 0;
	char letter;
	

	while(fscanf(fp, "%c" "%d", &letter, &val) != EOF) {
		
		if (letter == 'i') {
			insert(val);
		}

		if (letter == 'd') {
			delete(val);
		}
	
	}

	fclose(fp);
	int x = count();


	printf("%d\n", x);
	print_list();

	return 0;

}

