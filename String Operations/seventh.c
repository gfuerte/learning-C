#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(int argc, char** argv) {
	
	if (argc < 2) {
		printf("Insufficient arguments\n");
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		int length = strlen(argv[i]);
		char temp[2] = { 0 };
		strncpy(temp, argv[i]+length-1, 1);
		if (i == (argc -1)) {
			printf("%s\n", temp);
		} else {
			printf("%s", temp);
		}
	}

	return 0;

}
