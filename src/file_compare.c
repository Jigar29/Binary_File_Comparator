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
#include <stdint-gcc.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include "file_op.h"

// Last char not checked

#define FILE_READ_BUFFER_SIZE 1024

int main( int argc, char *argv[]) {

	// Variable declarations
	FILE *file1_ptr = NULL, *file2_ptr = NULL;
	int64_t global_file_index= 0;
	int64_t file1_length = 0, file2_length = 0;
	clock_t start_time;

	// Temp buffers to store the data fetched from the files
	char *temp_buffer1 = (char *)calloc(FILE_READ_BUFFER_SIZE, sizeof(char));
	char *temp_buffer2 = (char *)calloc(FILE_READ_BUFFER_SIZE, sizeof(char));

	// Error check for the file1 existance
	if(openFile(&file1_ptr,argv[1], "r") == RETURN_FAIL)
		return EXIT_FAILURE;
	if(openFile(&file2_ptr,argv[2], "r") == RETURN_FAIL)
		return EXIT_FAILURE;

	file1_length = getFilesize(file1_ptr);
	file2_length = getFilesize(file2_ptr);

	// Starting the clock to count number of seconds this routine take to perform comparision
	start_time = clock();

	if(file1_length != file2_length)
	{
		printf("File Size are not same;  File 1 length is : %I64d Bytes\n\t\t\t File 2 Length is : %I64d Bytes\n", file1_length, file2_length);
		return EXIT_FAILURE;
	}
	else
		printf("File Size is same;  File length is : %I64d Bytes\n", file1_length);

	// Actual implementation starts here
	while(global_file_index < file1_length)
	{
		int offset = 0;
		if((file1_length- global_file_index) >= FILE_READ_BUFFER_SIZE)
		{
			fgets(&temp_buffer1[0],FILE_READ_BUFFER_SIZE, file1_ptr);
			fgets(&temp_buffer2[0],FILE_READ_BUFFER_SIZE, file2_ptr);
			offset = FILE_READ_BUFFER_SIZE;
		}
		else
		{
			for(int i=0; i<(file1_length- global_file_index);i++)
			{
				temp_buffer1[i] = fgetc(file1_ptr);
				temp_buffer2[i] = fgetc(file2_ptr);
			}
			offset = file1_length- global_file_index;
		}
		for(int i= 0; i<offset; i++)
		{
			if(temp_buffer1[i] != temp_buffer2[i])
			{
				printf("Output : Files are not same, First most difference is at 0x%I64x position\n", global_file_index+i);
				printf("Reason : First Different character in both the files is \n\t file1 = '%x'%x, file2 = '%x'%x\n", temp_buffer1[i], temp_buffer1[i+1], temp_buffer2[i], temp_buffer2[i+1]);

				goto exit;
			}
		}
		global_file_index += offset;
	}
	printf("Output : Files are Exactly same\n\t File was scanned till 0x%I64x position\n", global_file_index);

exit:fclose(file1_ptr);		// Closing the files to make the files available for later use succesfully
	 fclose(file2_ptr);
	 // Freeing all the created memory to prevent stack overflow
	 free(temp_buffer1);
	 free(temp_buffer2);

	 printf("\n\nTotal Time taken for the computations is %lf seconds", ((double)(clock() - start_time)/ CLOCKS_PER_SEC));

	 return EXIT_SUCCESS;
}
