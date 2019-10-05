#include<stdio.h>
#include<stdlib.h>

int** allocate_matrix(int rows, int cols);
void initialize_matrix(int** matrix_result, int** matrix1, int** matrix2, int rows1, int cols2, int same);
void print_matrix(int** matrix, int rows, int cols);
void free_matrix(int** matrix, int rows);

int** allocate_matrix(int rows, int cols) {
	int** arr = malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		arr[i] = malloc (cols * sizeof(int));
	}

	return arr;
}

void initialize_matrix(int** matrix_result, int** matrix1, int** matrix2, int rows1, int cols2, int same) {
	
	for(int i = 0; i < rows1; i++) {
		for(int j = 0; j < cols2; j++) {
			int sum = 0;
			for(int k = 0; k < same; k++) {
				sum += (matrix1[i][k] * matrix2[k][j]);
			}		
			matrix_result[i][j] = sum;
		}
	}
}

void print_matrix(int** matrix_result, int rows, int cols) {

	for(int i = 0; i < rows; i++) {
		if (i != 0) {
			printf("\n");
		}

		for(int j = 0; j < cols; j++) {
			printf("%d	", matrix_result[i][j]);
		}
	}
}

void free_matrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
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
	if (fscanf(fp, "%d\n", &q) == EOF) {
		exit(0);
	}
	


//------------------------------------------Matrix 1 ---------------------------------//	
	int rows1 = q;
	int cols1;
	int** matrix1;

	fscanf(fp, "%d", &cols1);

	matrix1 = allocate_matrix(rows1, cols1);
	
	for (int i = 0; i < rows1; i ++) {
		for (int j = 0; j < cols1; j++) {
			int value;
			fscanf(fp, "%d", &value);
			matrix1[i][j] = value;
		}
	}



//------------------------------------------Matrix 2 ---------------------------------//	

	int rows2;
	int cols2;
	int** matrix2;

	fscanf(fp, "%d", &rows2);
	fscanf(fp, "%d", &cols2);
	
	matrix2 = allocate_matrix(rows2, cols2);
	
	for (int i = 0; i < rows2; i ++) {
		for (int j = 0; j < cols2; j++) {
			int value;
			fscanf(fp, "%d", &value);
			matrix2[i][j] = value;
		}
	}


//------------------------------------------Main Cont.---------------------------------//
	
	if (cols1 != rows2) {
		printf("bad-matrices");		
		free_matrix(matrix1, rows1);
		free_matrix(matrix2, rows2);
		exit(0);
	}
	
	int** matrix_final;
	matrix_final = allocate_matrix(rows1, cols2);
	initialize_matrix(matrix_final, matrix1, matrix2, rows1, cols2, cols1);
	print_matrix(matrix_final, rows1, cols2);

	free_matrix(matrix1, rows1);
	free_matrix(matrix2, rows2);
	free_matrix(matrix_final, rows1);
	return 0;
}
