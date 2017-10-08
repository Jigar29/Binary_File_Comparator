/*
 ============================================================================
 Name        : file_compare.c
 Author      : Jigar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FILE_READ_BUFFER_SIZE 1024

int main(void) {

	FILE* file1, *file2;
	long int counter= 1; // to be fixed
	clock_t start_time, end_time;
	char *buff1 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));
	char *buff2 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));

	file1 = fopen("C:/Users/Jigar/Desktop/file1.txt","r");
	file2 = fopen("C:/Users/Jigar/Desktop/file2.txt","r");

	start_time = clock();

	while((!feof(file1)) && (!feof(file2)))
	{
		fgets(&buff1[0],FILE_READ_BUFFER_SIZE, file1);
		fgets(&buff2[0],FILE_READ_BUFFER_SIZE, file2);
		for(int i =0; i<FILE_READ_BUFFER_SIZE; i++)
		{
			if(buff1[i] != buff2[i])
			{
				printf("->Difference file1 = %c%c, file2 = %c%c\n", buff1[i], buff1[i+1], buff2[i], buff2[i+1]);
				printf("->Files are not same, they defer at %ld position\n", counter+i);
				goto exit;
			}
		}
		counter = counter + FILE_READ_BUFFER_SIZE;
	}
	printf("->Files are Exactly same\n");

exit:	fclose(file1);
		fclose(file2);

	end_time = clock();
	printf("->Total Time taken for the computations is %lf seconds", ((double)(end_time - start_time)/ CLOCKS_PER_SEC));
	free(buff1);
	free(buff2);
	return EXIT_SUCCESS;
}
