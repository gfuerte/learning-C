#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct treenode {
	int value;
	struct treenode* left;
	struct treenode* right;
};

struct treenode* insert(struct treenode* root, struct treenode* temp, int value, int height);
void search(struct treenode* root, int value, int height);
void free_tree(struct treenode* root);

struct treenode* insert(struct treenode* root, struct treenode* temp, int value, int height) {
	temp->value = value;
		
	if (root == NULL) {
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
		printf("inserted %d\n", height);
	} else {
		if (root->value == value) {
			printf("duplicate\n");
			free(temp);
		} else {
			if (temp->value > root->value) {
				root->right = insert(root->right, temp, value, height+1);
			} else if (temp->value < root->value) {
				root->left = insert(root->left, temp, value, height+1);
			}
		}
	}
		
	return root;
}

void search(struct treenode* root, int value, int height) {
	if (root == NULL) {
		printf("absent\n");
	} else {
		if(root->value == value) {
			printf("present %d\n", height);
		} else {
			if (value > root->value) {
				search(root->right, value, height+1);
			} else if (value < root->value) {
				search(root->left, value, height+1);
			}
		}	
	}
}

void free_tree(struct treenode* root) {
	if(root == NULL) {
		return;
	}

	free_tree(root->left);
	free_tree(root->right);
	free(root);
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
		exit(0);
	}

	struct treenode* root = NULL;

	int val;
	char letter;

	while(fscanf(fp, "%c" "%d", &letter, &val) != EOF) {
		int height = 1;	
		if (letter == 'i') {
			struct treenode* temp = malloc(sizeof(struct treenode));
			root = insert(root, temp, val, height);
		}
	
		if (letter == 's') {
			search(root, val, height);
		}
		
	}
	
	free_tree(root);
	return 0;

}
