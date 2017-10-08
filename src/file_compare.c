/*
 ============================================================================
 Name        : file_compare.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	FILE* file1, *file2;

	file1 = fopen("C:/Users/Jigar/Desktop/file1.txt","r");
	file2 = fopen("C:/Users/Jigar/Desktop/file2.txt","r");

	{
		if(fgetc(file1) != fgetc(file2))
		{
			printf("Files are not same\n");
			return EXIT_SUCCESS;
		}
		printf("Files are exacclty same\n");
	}
	return EXIT_SUCCESS;
}
