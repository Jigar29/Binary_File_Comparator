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

int main(void) {

	FILE* file1, *file2;

	clock_t start_time, end_time;
	char *buff1 = (char *)calloc(1025, sizeof(char));
	char *buff2 = (char *)calloc(1025, sizeof(char));

	file1 = fopen("C:/Users/Jigar/Desktop/file1.txt","r");
	file2 = fopen("C:/Users/Jigar/Desktop/file2.txt","r");

	start_time = clock();

	while((!feof(file1)) && (!feof(file2)))
	{
		fgets(buff1,1024, file1);
		fgets(buff2,1024, file2);
		if(strcmp(buff1,buff2) != 0)
		{
			printf("Files are not same\n");
			goto exit;
		}
	}
	printf("Files are Exactly same\n");

exit:	fclose(file1);
		fclose(file2);

	end_time = clock();
	printf("Total Time taken for the computations is %lf seconds", ((double)(end_time - start_time)/ CLOCKS_PER_SEC));
	free(buff1);
	free(buff2);
	return EXIT_SUCCESS;
}
