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


#define FILE_READ_BUFFER_SIZE 1024

int main( int argc, char *argv[]) {

	// Variable declarations
	FILE* file1_ptr, *file2_ptr;
	char file1_path[50]= "", file2_path[50]="";
	int return_status = EXIT_SUCCESS;
	//This variable is used to declare
	int64_t global_file_index= 1;

	clock_t start_time;

	// Temp buffers to store the data fetched from the files
	char *temp_buffer1 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));
	char *temp_buffer2 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));

	// Error check for the file1 existance
	printf("Please Enter the first File\n");
	scanf("%s", &file1_path[0]);
	file1_ptr = fopen(&file1_path[0],"r");
	if(file1_ptr == NULL)
	{
		printf("No such file found in the directory. Please close the console and try again.\n");
		return_status=  EXIT_FAILURE;
		goto forced_exit;
	}
	// Error check for the file2 existance
	printf("Please Enter the Second File\n");
	scanf("%s", &file2_path[0]);
	printf("\n");

	file2_ptr = fopen(&file2_path[0],"r");
	if(file2_ptr == NULL)
	{
		printf("No such file found in the directory. Please close the console and try again.\n");
		fclose(file1_ptr);
		return_status=  EXIT_FAILURE;
		goto forced_exit;
	}

	// Starting the clock to count number of seconds this routine take to perform comparision
	start_time = clock();
	printf("***************************************************REsult**************************************************\n");

	// Actual implementation starts here
	while((!feof(file1_ptr)) && (!feof(file2_ptr)))
	{
		fgets(&temp_buffer1[0],FILE_READ_BUFFER_SIZE, file1_ptr);
		fgets(&temp_buffer2[0],FILE_READ_BUFFER_SIZE, file2_ptr);
		for(int i =0; i<FILE_READ_BUFFER_SIZE; i++)
		{
			if(temp_buffer1[i] != temp_buffer2[i])
			{
				printf("Output : Files are not same, First most difference is at %I64d position\n", global_file_index+i);
				if((temp_buffer1[i] != '\0') && (temp_buffer2[i] != '\0'))
					printf("Reason : First Different character in both the files is \n\t file1 = '%c'%c, file2 = '%c'%c\n", temp_buffer1[i], temp_buffer1[i+1], temp_buffer2[i], temp_buffer2[i+1]);
				else
					printf("Reason : File Size are not equal.\n");
				goto exit;
			}
		}
		global_file_index = global_file_index + FILE_READ_BUFFER_SIZE;
	}
	printf("Output : Files are Exactly same\n");

exit:fclose(file1_ptr);		// Closing the files to make the files available for later use succesfully
	 fclose(file2_ptr);
	 // Freeing all the created memory to prevent stack overflow
	 free(temp_buffer1);
	 free(temp_buffer2);

	 printf("\n\nTotal Time taken for the computations is %lf seconds", ((double)(clock() - start_time)/ CLOCKS_PER_SEC));

forced_exit:	 getch();
	 	 	 	 return return_status;
}
