#include <cstdio>
#include "Lexer.h"


void test_lexer(const char *filename) {
    Lexer lexer(filename);
    Token *t;
    while ((t = lexer.next())) {
        t->print();
    }
}

int main() {
    const char *filename = "test_token.txt";
    test_lexer(filename);
    return 0;
}
