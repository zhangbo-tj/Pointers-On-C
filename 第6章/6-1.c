#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NUL '\0'

char const *find_char(char const *source, char const *chars) {
	char const *temp_source = source;

	while (*chars != NUL) {
		while (*temp_source != NUL) {
			if (*temp_source == *chars) {
				return temp_source;
			}
			temp_source++;
		}
		temp_source = source;
		chars++;
	}
	return NULL;
}

int main() {
	char *source = "ABCDEF";
	char *chars = "Def";
	char const *result = NULL;

	if ((result = (find_char(source, chars))) != NULL) {
		printf("%c\n", *result);
	}
	else {
		printf("NULL\n");
	}
	system("pause");
	return 0;
}