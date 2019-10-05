#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

	if (argc != 2) {
		printf("Insufficient arguments\n");
		exit(0);
	}

	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File does not exist\n");
		exit(0);
	}

	int num = 0;

	if(fscanf(fp, "%d\n", &num) == EOF) {
		printf("File is empty\n");
		exit(0);
	}

	for(int i = 0; i < num; i++) {
		int input;
		fscanf(fp, "%d\n", &input);
		int check = 0;
		while(input != 0) {
			for (int j = 2; j < input-1; j++) {
				if (input%j == 0) {
					check = 1;
					break;
				}		
			}

			if (check != 0) {
				break;
			}

			input = input/10;
			
		
		}

		
		if (check == 0) {
			printf("yes\n");
		} else {
			printf("no\n");
		} 
		
	}
	
	fclose(fp);


	return 0;
}
