#include "string_builder.h"

int main(int argc, char *argv[]) {
    SB *sb = new_string_builder();
    printf("length %zu\n", length(sb));
    for (int i=1; i<argc; ++i) {
        append(sb, argv[i]);
        printf("string builder is now %s, length %zu, capacity %zu\n", 
            get_str(sb), length(sb), capacity(sb));
    }
    free_string_builder(sb);
    return 0;
}