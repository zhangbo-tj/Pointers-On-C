#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


#define TRUE '1'
#define FALSE '0'

int main() {
	char num[1000];
	int index = 0;
	for (; index < 1000; index++) {
		num[index] = TRUE;
	}

	for (index = 1; index < 1000; index++) {
		if (num[index] == TRUE) {
			for (int temp_index = index + 1; temp_index < 1000; temp_index++) {
				if (num[temp_index] == TRUE && (2*temp_index+1)%(2*index+1) == 0) {
					num[temp_index] = false;
				}
			}
		}
	}

	int number = 1;
	printf("2   ");
	for (index = 1; index < 1000; index++) {
		if (num[index] == TRUE) {
			printf("%d    ", 2*index+1);
			number++;
			if (number % 5 == 0) {
				printf("\n");
			}
		}
	}

	system("pause");
	return 0;
}