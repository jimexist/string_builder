#include "string_builder.h"

int main(int argc, char *argv[]) {
    SB *sb = new_string_builder();
    int i;
    char *copy = get_str_copy(sb);
    printf("string builder is now '%s', length %zu, capacity %zu\n", 
        copy, length(sb), capacity(sb));
    free(copy);
    
    for (i=1; i<argc; ++i) {
        append(sb, argv[i]);
        copy = get_str_copy(sb);
        printf("string builder is now '%s', length %zu, capacity %zu\n", 
            copy, length(sb), capacity(sb));
        free(copy);
    }
    return 0;
}
