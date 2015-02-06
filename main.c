#include "string_builder.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define LINE_LENGTH (65535)

static char words[] = "/usr/share/dict/words";

int main(void) {
    
    size_t nb;
    char buf[LINE_LENGTH + 1];
    
    SB *sb = new_string_builder();
    int fd = open(words, O_RDONLY);
    assert(fd);
    
    while ((nb = read(fd, buf, LINE_LENGTH)) > 0) {
        buf[nb] = '\0';
        append(sb, buf);
        printf("sb is now %ld, capacity %ld\n",
            length(sb), capacity(sb));
        if (nb < LINE_LENGTH) {
            break;
        }
    }
    assert(nb >= 0);
    
    free_string_builder(sb);
    return 0;
}
