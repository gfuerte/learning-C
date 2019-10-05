#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(int argc, char** argv) {
	
	if (argc < 2) {
		printf("Insufficient arguments\n");
		exit(0);
	}

//	char consonant[] = "ay";
	char vowel[] = "yay";



	for (int i = 1; i < argc; i++) {
	
		int length = strlen(argv[i]);

		if(argv[i][0] != 'a' && argv[i][0] != 'e' && argv[i][0] != 'i' && argv[i][0] != 'o' && argv[i][0] != 'u'
		&& argv[i][0] != 'A' && argv[i][0] != 'E' && argv[i][0] != 'I' && argv[i][0] != 'O' && argv[i][0] != 'U') {
			
			for (int j = 0; j < length; j++) {	

				if(argv[i][j] == 'a' || argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'o' || argv[i][j] == 'u'
				|| argv[i][j] == 'A' || argv[i][j] == 'E' || argv[i][j] == 'I' || argv[i][j] == 'O' || argv[i][j] == 'U') {
				//	char temp[10000] = { 0 };
					char* temp = malloc(sizeof(char*j));
				//	char temp2[10000] = { 0 };
				//	char* temp2 = malloc(length-j);
					strncpy(temp, argv[i], j);
				//	strncpy(temp2, argv[i]+j, length-j);
				//	printf("%s", temp2);
					printf("%s", temp);
			/*	
					if (i == (argc - 1)) {
						printf("%s", temp2);
						printf("%s", temp);
						printf("%s\n", consonant);
					} else {
						printf("%s", temp2);
						printf("%s", temp);
						printf("%s ", consonant);
					}
				
					free(temp);
					free(temp2);
					break;
				*/	
				}
			}
			
		} else {
			if (i == (argc - 1)) {
				printf("%s%s\n", argv[i], vowel);
			} else {
				printf("%s%s ", argv[i], vowel);
			}
		}	
	}
	return 0;

}


		/*-----------------NOTES-----------------------------
		 
		printf("%s\n", argv[i]);	//string
		printf("%c\n", argv[i][0]);	//first char of string
		int length = 0;
		length = strlen(argv[i]);	//length of string
		printf("%d\n", length);
		char temp[3] = { 0 };
		strncpy(temp, argv[i], 2);	//substring
		printf("%s\n", temp);

		printf("%s\n", consonant);	//prints ay
		printf("%s\n", vowel);		//prints yay

		printf("%c\n", consonant[0]);	//prints 'a' the first letter in consonant

		if (consonant[0] == 'a') {	//given a condition, prints the sentence + tag
			printf("the first letter in consonant is an a and %s\n", consonant);
		}
	
		*/
