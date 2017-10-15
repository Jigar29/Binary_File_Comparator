/*
 * file_op.h
 *
 *  Created on: Oct 11, 2017
 *      Author: Jigar
 */

#ifndef FILE_OP_H_
#define FILE_OP_H_

#include "stdio.h"
#include <stdint-gcc.h>
#include <stdbool.h>
#include "general_defines.h"

RET_STATUS openFile(FILE **, char *, char *);
int64_t getFilesize(FILE *);
int64_t fget_string(FILE **, char *, int);

#endif /* FILE_OP_H_ */
