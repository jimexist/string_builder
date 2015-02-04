#ifndef _STRING_BUILDER_H_
#define _STRING_BUILDER_H_

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct string_builder;
typedef struct string_builder SB;

SB *new_string_builder();
void free_string_builder(SB *sb);
void append(SB *sb, const char *str);
size_t length(SB *sb);
char *get_str(SB *sb);

#endif