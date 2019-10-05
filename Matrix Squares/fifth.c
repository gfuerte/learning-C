#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int** allocate(int n);
void free_matrix(int** matrix, int n);
bool magic(int** matrix, int n, int value);

int** allocate(int n) {
	int** arr = malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = malloc(n * sizeof(int));
	}

	return arr;
}

void free_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

bool magic(int** matrix, int n, int value) {
	bool result = true;
	
	int sum;
	for(int i = 0; i < n; i++) {
		sum = 0;       
		for(int j = 0; j < n; j++) {
			sum += matrix[i][j];
		}

		if (sum != value) {
			result = false;
		}
	}

	for(int k = 0; k < n; k++) {
		sum = 0;
		for(int l = 0; l < n; l++) {
			sum += matrix[l][k];
		}

		if (sum != value) {
			result = false;
		}
	}

	sum = 0;
	for(int m = 0; m < n; m++) {
		sum += matrix[m][m];
	}

	if (sum != value) {
		result = false;
	}

	sum = 0;
	int cols = n-1;
	for(int rows = 0; rows < n; rows++) {
		sum += matrix[rows][cols];
		cols--;
	}
	
	if (sum != value) {
		result = false;
	}


	return result;
}


int main(int argc, char** argv) {

	if (argc != 2) {
		printf("insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");

	if (fp == NULL)  {
		printf("error\n");
		exit(0);
	}

	int q = 0;
	if(fscanf(fp, "%d\n", &q) == EOF) {
		exit(0);
	}

	int n = q;

	if ((n % 2) == 0) {
		printf("not-magic");
		exit(0);
	}

	int** matrix;

	matrix = allocate(n);

	for (int i = 0; i < n; i++) { //initialize
		for (int j = 0; j < n; j++) {
			int value;
			fscanf(fp, "%d", &value);
			matrix[i][j] = value;
		}
	}
	
	int value = 0;
	for (int j = 0; j < n; j++) {
		value += matrix[0][j];
	}

	bool check = magic(matrix, n, value);
	if (check == true) {
		printf("magic");
	} else {
		printf("not-magic");
	}

	free_matrix(matrix, n);

	return 0;

}
