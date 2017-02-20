/*********************************************************
* Daniel Bachler
* 4/26/16
* amalgum.c
* CS120
* Desc:
*	Takes a string and adds 0-infinte other strings to it
*	concatanated
**********************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void amalgamation(char *word, ...) {
	/*creates the array of strings*/
	va_list args;
	/*creates a string and sets its to word*/
	const char *next = word;
	int i;
	/*Sets the start of the array to word*/
	va_start(args, word);
	/*Sets word[0] to null char*/
	word[0] = 0;
	next = va_arg(args, const char *); /* Next string */
	while(next != NULL) {
		/*Concatenates two strings*/
		strcat(word, next);
		next = va_arg(args, const char *); /* Next string */
    }
	va_end(args);
}

int main(void) {
	char test[256];
	amalgamation(test, "herro", "test", NULL);
	printf("%s", test);
	return 0;
}