#ifndef MAIN_H
#define MAIN_H

#define MAX_COMMAND_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


/*Prototypes*/

int strcmp(const char *str1, const char *str2);
size_t strcspn(const char *str1, const char *str2);
int gline(int argc, char *argv[]);
int main(void);

#endif
