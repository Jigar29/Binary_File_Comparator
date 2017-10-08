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

	FILE* file1, *file2;
	char file1_path[50]= "", file2_path[50]="";
	int return_status = EXIT_SUCCESS;

	int64_t counter= 1;
	clock_t start_time;
	char *buff1 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));
	char *buff2 = (char *)calloc(FILE_READ_BUFFER_SIZE+1, sizeof(char));

	printf("Please Enter the first File\n");
	scanf("%s", &file1_path[0]);
	file1 = fopen(&file1_path[0],"r");
	if(file1 == NULL)
	{
		printf("No Such File Exist\n");
		return_status=  EXIT_FAILURE;
		goto forced_exit;
	}

	printf("Please Enter the Second File\n");
	scanf("%s", &file2_path[0]);
	printf("\n");

	file2 = fopen(&file2_path[0],"r");
	if(file2 == NULL)
	{
		printf("No Such File Exist\n");
		fclose(file1);
		return_status=  EXIT_FAILURE;
		goto forced_exit;
	}
	start_time = clock();
	printf("***************************************************REsult**************************************************\n");
	while((!feof(file1)) && (!feof(file2)))
	{
		fgets(&buff1[0],FILE_READ_BUFFER_SIZE, file1);
		fgets(&buff2[0],FILE_READ_BUFFER_SIZE, file2);
		for(int i =0; i<FILE_READ_BUFFER_SIZE; i++)
		{
			if(buff1[i] != buff2[i])
			{
				printf("Output : Files are not same, First most difference is at %I64d position\n", counter+i);
				if((buff1[i] != '\0') && (buff2[i] != '\0'))
					printf("Reason : First Different character in both the files is \n\t file1 = '%c'%c, file2 = '%c'%c\n", buff1[i], buff1[i+1], buff2[i], buff2[i+1]);
				else
					printf("Reason : File Size are not equal.\n");
				goto exit;
			}
		}
		counter = counter + FILE_READ_BUFFER_SIZE;
	}
	printf("Output : Files are Exactly same\n");

exit:fclose(file1);
	 fclose(file2);
	 free(buff1);
	 free(buff2);

	 printf("\n\nTotal Time taken for the computations is %lf seconds", ((double)(clock() - start_time)/ CLOCKS_PER_SEC));

forced_exit:	 getch();
	 	 	 	 return return_status;
}
