/*
 * file_op.c
 *
 *  Created on: Oct 11, 2017
 *      Author: Jigar
 */

#include "file_op.h"

RET_STATUS openFile(FILE **fptr, char *file_name, char *mode)
{
	*fptr = fopen(file_name, mode);
	if(*fptr == NULL)
	{
		printf("No such file found in the directory. Please Try Again\n");
		return RETURN_FAIL;
	}
	else
		return RETURN_SUCCESS;
}

int64_t getFilesize(FILE *fptr)
{
	int64_t file_lenght = 0;

	long file_current_location = ftell(fptr);

	fseek(fptr,0, SEEK_SET);
	long file_start_ptr = ftell(fptr);
	fseek(fptr, 0, SEEK_END);
	file_lenght = (int64_t) (ftell(fptr) - file_start_ptr);
	fseek(fptr,file_current_location, SEEK_SET);
	return file_lenght;
}

int64_t fget_string(FILE **fptr, char *buff, int read_count)
{
	int64_t no_chars_read  = 0;

	long start_addr = ftell(*fptr);
	fgets(buff,read_count, *fptr);

	no_chars_read = (int64_t) (ftell(*fptr) - start_addr);

	return no_chars_read;
}
