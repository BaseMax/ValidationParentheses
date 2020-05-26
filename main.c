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
#define length(self) self->length
static void resize(array *self, size_t size) {
	self->buffer = realloc(self->buffer, size * sizeof(int));
	self->buffer_size = size;
}
array *init_with_size(size_t size) {
	array *self = malloc(sizeof(array));
	self->refs = 1;
	self->length = 0;
	self->buffer_size = size;
	self->buffer = malloc(size * sizeof(int));
	return self;
}
array *init() {
	return init_with_size(DEFAULT_SIZE);
}
void push(array *self, int data) {
	if(self->length == self->buffer_size) resize(self, 2 * self->buffer_size);
	self->buffer[self->length] = data;
	self->length++;
}
int get(array *self, size_t index) {
	return index >= self->length ? -1 : self->buffer[index];
}
int pop(array *self) {
	return self->length ? self->buffer[--self->length] : -1;
}
bool validSyntax(char* input) {
	array *lst = init();
	for(;*input && *input!='\0';*input++) {
		int item=get(lst, length(lst)-1);
		if(*input == '(') {
			push(lst, 1);
		}
		else if(*input == ')') {
			if(item == 1) {
				pop(lst);
			}
			else {
				return false;
			}
		}
		else if(*input == '{') {
			push(lst, 2);
		}
		else if(*input == '}') {
			if(item == 2) {
				pop(lst);
			}
			else {
				return false;
			}
		}
		else if(*input == '[') {
			push(lst, 3);
		}
		else if(*input == ']') {
			if(item == 3) {
				pop(lst);
			}
			else {
				return false;
			}
		}
	}
	if(length(lst) == 0) {
		return true;
	}
	return false;
}
void tests() {
	int success=0;
	int failled=0;
	#define TEST(input) if(validSyntax(input)==true) {success++;}else {failled++;}
	// good tests
	TEST("(){[]}")
	TEST("{()[]}")
	TEST("[[]]({})")
	TEST("a(dfgdfgdfgdfg)")
	TEST("a(dfgdfgd{dfdfgdfg}fgdfg)")
	TEST("((()))")
	TEST("{{{}}}")
	TEST("{{{\n}}}")
	// bad tests
	TEST("{(}")
	TEST("())")
	TEST("({[])}")
	TEST("a(dfgdfgdfgdfg")
	TEST("a(dfgdfgd{dfdfgdfgfgdfg)")
	TEST("a(dfgdfgd{dfdfgdfgfgdfg")
	// print results
	printf("%d Tests Passed\n", success);
	printf("%d Tests Failled\n", failled);
}
int main(int argc, char* argv[]) {
	if(argc == 2) {
		validSyntax(argv[1]) == true ? printf("Valid.\n") : printf("Failled!\n");
		return 1;
	}
	tests();
	return 0;
}
