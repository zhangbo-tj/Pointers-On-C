#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define NUL '\0'


void reverse_string(char* string) {
	char *start_pointer = string;
	char *end_pointer = string;

	while (*end_pointer != NUL) {
		end_pointer++;
	}
	end_pointer--;

	while (start_pointer != end_pointer) {
		char temp = *start_pointer;
		*start_pointer = *end_pointer;
		*end_pointer = temp;
		start_pointer++;
		end_pointer--;
	}
}



int main() {
	char str[] = "abcdefg";
	
	reverse_string(str);

	printf("%s\n", str);

	system("pause");
	return 0;
}