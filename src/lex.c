#include "../include/lex.h"
#include "../include/stringutil.h"
#include "../include/failsafe.h"

#include <stdio.h>
#include <stdint.h>

/*
    Represents an handle to the input file.
    This handle is closed when the lexer is.
*/
static FILE	*handle;


#define	READ	fgetc(handle)
#define FOWARD	fseek(handle, 1, SEEK_CUR)	
#define	PEEK	fgetc(handle); fseek(handle, -1, SEEK_CUR)

// Opens a new file.            
void lex_open(const char *filepath) {
    handle = fopen(filepath, "r");
    if (!handle) {
        failsafe_fatal("lmnopc: Could not open file", &lex_open);
    }
}

// Closes an input file.
void lex_close(void) {
    fclose(handle);
    return;
}

// Fetches the next token.
// Returns xFF if failure, returns x00 if EOF.
char lex_next(void) {
    // 1. Skipping whitespaces
    char c = READ;
    while (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v')
        c = READ;
    
    // 2. EOF?
    if (c == EOF)
        return 0;
    
    // 3. Checking for operators
    switch (c) {
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
    case '@':
    case '$':
    case '~':
    case '?':
    case ':':
    case ';':
    case ',':
        // These characters are only used one time in tokens.
        return c;
    case '+':
    case '-':
    case '&':
    case '|':
    case '^':
    case '<':
    case '>':
    case '.':
    case '!':
    case '*':
    case '/':
    case '%':
    case '=': {
        char p = PEEK;
        if (p == c) {
            if (c == '+' ||
                c == '-' ||
                c == '&' ||
                c == '|' ||
                c == '=' ||
                c == '<' ||
                c == '>' ||
                c == '.') {
                FOWARD;
                if (c == '<' ||
                    c == '>') {
                    p = PEEK;
                    if (p == '=') {
                        FOWARD;
                        return c == '<' ? LEX_LARROWSEQU : LEX_RARROWSEQU;
                    }
                }
                if (c == '.') {
                    p = PEEK;
                    if (p == '.') {
                        FOWARD;
                        return LEX_DOTDOTDOT;
                    }
                }
                return c == '+' ? LEX_PPLUS : c == '-' ? LEX_MMINUS :
                       c == '&' ? LEX_AMPERSANDS : c == '|' ? LEX_PIPES :
                       c == '=' ? LEX_EQUALS : c == '<' ? LEX_LARROWS :
                       c == '>' ? LEX_RARROWS : LEX_DOTDOTDOT;
            }
        }
        else if (c == '-' && p == '>') {
            FOWARD;
            return LEX_ARROW;
        }
        else if (p == '=') {
            if (c == '+' ||
                c == '-' ||
                c == '*' ||
                c == '/' ||
                c == '%' ||
                c == '&' ||
                c == '|' ||
                c == '^' ||
                c == '!' ||
                c == '*' ||
                c == '/' ||
                c == '%' ||
                c == '<' ||
                c == '>') {
                FOWARD;
                return c == '+' ? LEX_PLUSEQUAL : c == '-' ? LEX_MINUSEQUAL :
                       c == '*' ? LEX_STAREQUAL : c == '/' ? LEX_SLASHEQUAL :
                       c == '%' ? LEX_PEREQUAL : c == '&' ? LEX_ANDEQUAL :
                       c == '|' ? LEX_PIPEEQUAL : c == '^' ? LEX_CARETEQUAL :
                       c == '<' ? LEX_GREQUAL : c == '>' ? LEX_LEEQUAL :
                       LEX_NEQUAL;
            }
        }
        return c;
    }
    }
    
    return 0xFF;
}