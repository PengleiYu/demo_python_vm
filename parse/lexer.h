//
// Created by yupenglei on 2024/6/17.
//

#ifndef DEMO_VM_LEXER_H
#define DEMO_VM_LEXER_H

#include <cstring>
#include <cstdio>

enum TokenType {
    T_INT,
    T_NAME,

    T_PLUS,
    T_MINUS,
    T_DIV,
    T_MULT,
};

class Token {
public:
    TokenType _tt;
    const char *_value;
    int _length;

    Token(TokenType tt, const char *value, int length) : _tt(tt), _value(value), _length(length) {}

    bool equals(const char *s) const;

    void print() const;
};

enum State {
    INIT,
    INTEGER,

    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
};

class Lexer {
private:
    static const int BUF_LEN = 1024;
    char *_s;
    int _index;
    State _state;
    int _length;
    FILE *_file;

public:
    explicit Lexer(const char *filename);

    virtual ~Lexer();

    inline char getchar();

    inline void ungetc();

    Token *next();

    static Token *filter_keyword(Token *t);
};

#endif //DEMO_VM_LEXER_H
