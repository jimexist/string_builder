#include "string_builder.h"

struct string_builder {
    size_t size;
    size_t capacity;
    char *str;
};

static void resize(SB *sb, size_t new_capacity) {
    if (new_capacity < sb->size) {
        new_capacity = sb->size;
    }
    sb->capacity = new_capacity;
    sb->str = (char *) realloc(sb->str, sizeof(char) * sb->capacity); 
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
    if (new_size > sb->capacity) {
        resize(sb, new_size);
    }
    strcat(sb->str, str);
    sb->size = new_size;
}

void free_string_builder(SB *sb) {
    free(sb->str);
    free(sb);
}

size_t length(SB *sb) {
    return sb->size;
}

char *get_str(SB *sb) {
    return sb->str;
}
