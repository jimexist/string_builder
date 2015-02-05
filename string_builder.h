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
void append_i(SB *sb, int i);
void append_ui(SB *sb, unsigned int ui);
void append_c(SB *sb, char c);
size_t length(SB *sb);
size_t capacity(SB *sb);

/* warning, user must free the returned array */
char *get_str_copy(SB *sb);

#endif
