#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NUL '\0'

int is_substr(char const *str, char const *substr) {
	if (str != NULL  && substr != NULL) {
		while (*str != NUL && *substr != NUL) {
			if (*str++ != *substr++) {
				return 0;
			}
		}
		if (*substr == NUL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}
int del_substr(char* str, char const *substr) {
	if (substr == NULL) {
		return 1;
	}

	char *pstr = NULL;

	while (*str != NUL) {
		if (is_substr(str, substr) ){
			break;
		}
		str++;
	}

	if (*str != NUL) {
		pstr = str;

		while (*substr != NUL) {
			substr++;
			str++;
		}
	}
	else {
		return 0;
	}

	while (*pstr != NUL) {
		*pstr = *str;
		pstr++;
		str++;
	}
	return 1;

}



int main() {
	char str[] = "abcdefg";
	char *substr = "cde";

	if (del_substr(str, substr)) {
		printf("%s\n", str);
	}

	system("pause");
	return 0;
}