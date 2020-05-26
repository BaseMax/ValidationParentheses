// Max Base
// https://github.com/BaseMax/ValidationParentheses
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_SIZE 64
typedef enum {
	false,
	true,
} bool;
typedef struct {
	int *buffer;
	int refs;
	size_t buffer_size;
	size_t length;
} array;
