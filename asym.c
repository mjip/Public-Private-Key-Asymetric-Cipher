#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Marie Payne, ID# 260686859 */

void check(int w, int v, int u);
void cipher(char *filename, int key);

int main(int argc, char *argv[]){
	/* Checks to see if any command line arguments were run */
	if(argc == 1){
		printf("\nNo command line options were passed.\n\n");
		return 0;
	}
	
	/* If the option was check, convert the arguments to ints and send to the check function */
	if(strcmp(argv[1], "-CHECK")==0){
		int w = atoi(argv[2]);
		int v = atoi(argv[3]);
		int u = atoi(argv[4]);
		check(w, v, u);
		return 0;
	}
	/* If the option was to cipher, pass the arguments to the cipher function */
	else if(strcmp(argv[1], "-CIPHER")==0){
		char *filename = argv[2];
		int key = atoi(argv[3]);
		cipher(filename, key);
		return 0;
	}

	printf("\nThere was an unexpected error, check your syntax.\n\n");	
	return 0;	
}

void check(int w, int v, int u){
	/* Basic algorithm to check gcd */
	int temp;
	int uCOPY = u;
	int wCOPY = w;
	while(wCOPY != 0){
		temp = uCOPY % wCOPY;
		uCOPY = wCOPY;
		wCOPY = temp;
	}
	if (uCOPY == 1){
	/* If gcd is 1, check if inverse exists */
		if(((w*v)%u) == 1){
		/* If inverse exists, check if modulo is greater than public key */
			if(u>w){
				/*Check for prime */
				int i, c;
				i = c = 0;
				for(i=1; i<=w; i++){
					if(w%i == 0){
						c++;
					}
				}
				if(c == 2){
					printf("\nVALID KEYS\n\n");
					return;
				}
			}
		}
	}
	printf("\nINVALID KEYS\n\n");
	return;
}

void cipher(char *filename, int key){
	/* Open file of text to read, file to write to */
	FILE *message;
	message = fopen(filename, "r");
	FILE *ciphertxt;
	ciphertxt = fopen(strcat(filename, ".cipher"), "w");
	/* Feed characters one by one while encrypting/decrypting them with key */
	int ch;
	int cipherch;
	while((ch = fgetc(message)) !=EOF){
		cipherch = (key * ch) % 256;
		fputc(cipherch, ciphertxt);
	}
	fclose(message);
	fclose(ciphertxt); 
	return;
}
