#ifndef _STRING_H
#define _STRING_H 1

#include "stddef.h"

int memcmp(const void* aptr, const void* bptr, size_t size);
size_t strlen(const char*);
char* strcat(char* d, char* s);
char* strcpy(char* d, const char* s);
int strcmp(const char* s1, const char* s2);
char* strncat(char* dest, char* src, size_t n);
char* strncpy(char* dest, char* src, size_t n);
char* strstr(char* s1, const char* s2); 
char* strchr(const char* s, int c);
int strncmp(const char* s1, const char* s2, size_t n);


#endif