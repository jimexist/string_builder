#include "string_builder.h"

struct string_builder {
    size_t size;
    size_t capacity;
    char *str;
};

static void resize(SB *sb, size_t new_capacity) {
    if (new_capacity < sb->size + 1) {
        new_capacity = sb->size + 1;
    }
    sb->capacity = new_capacity;
    sb->str = (char *) realloc(sb->str, sizeof(char) * sb->capacity);
    sb->str[sb->size] = '\0';
    assert(sb && "failed to realloc");
}

SB *new_string_builder() {
    SB *sb = (SB*) malloc(sizeof(SB));
    assert(sb && "failed to malloc");
    sb->size = 0;
    sb->capacity = 0;
    sb->str = NULL;
    resize(sb, 64);
    return sb;
}

void append(SB *sb, const char *str) {
    const size_t str_len = strlen(str);
    const size_t new_size = str_len + sb->size;
    if (new_size + 1 > sb->capacity) {
        size_t new_capacity = sb->capacity;
        while (new_capacity < new_size + 1) {
            new_capacity <<= 1;
        }
        resize(sb, new_capacity);
    }
    strcat(sb->str, str);
    sb->size = new_size;
}

void append_i(SB *sb, int i) {
    char buf[13];
    sprintf(buf, "%d", i);
    append(sb, buf);
}

void append_ui(SB *sb, unsigned int ui) {
    char buf[13];
    sprintf(buf, "%u", ui);
    append(sb, buf);
}

void append_c(SB *sb, char c) {
    char buf[2];
    buf[0] = c;
    buf[1] = '\0';
    append(sb, buf);
}

void free_string_builder(SB *sb) {
    free(sb->str);
    free(sb);
}

size_t length(SB *sb) {
    return sb->size;
}

size_t capacity(SB *sb) {
    return sb->capacity;
}

char *get_str_copy(SB *sb) {
    char *copy = (char *) malloc(sizeof(char) * (sb->size + 1));
    return strcpy(copy, sb->str);
}
