#include "../include/lex.h"

#include <stdio.h>

int main(void) {
    lex_open("test.txt");
    unsigned char c;
    while ((c = lex_next())) {
        if (c == 0xFF)
            break;
        printf("%d (%c)\n", c, c);
    }
    lex_close();
    return 0;
}