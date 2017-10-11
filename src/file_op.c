/*
 * file_op.c
 *
 *  Created on: Oct 11, 2017
 *      Author: Jigar
 */

#include "file_op.h"

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

