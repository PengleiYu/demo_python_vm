//
// Created by yupenglei on 2024/6/17.
//

#include <cstdio>
#include <cstdlib>
#include "Lexer.h"

Token::Token(TokenType tt, const char *value, int length) : _tt(tt), _value(value), _length(length) {}

bool Token::equals(const char *s) const {
    if (_length != strlen(s)) {
        return false;
    }

    for (int i = 0; i < _length; ++i) {
        if (*(_value + i) != *(s + i)) {
            return false;
        }
    }
    return true;
}

void Token::print() const {
    printf("%d: ", _tt);
    for (int i = 0; i < _length; i++) {
        printf("%c", _value[i]);
    }
    printf("\n");
}

Lexer::Lexer(const char *filename) {
    _s = new char[BUF_LEN];
    _file = fopen(filename, "r");
    if (_file == nullptr) {
        printf("无法打开文件 %s\n", filename);
        exit(-1);
    }

    fgets(_s, BUF_LEN, _file);
    _length = strlen(_s);
    _state = INIT;
    _index = 0;
}

Lexer::~Lexer() {
    if (_file) {
        fclose(_file);
        _file = nullptr;
    }
    if (_s) {
        delete[] _s;
        _s = nullptr;
    }
}

char Lexer::getchar() {
    return _s[_index++];
}

void Lexer::ungetc() {
    _index--;
}

Token *Lexer::next() {
    int start = _index;
    int length = 0;
    _state = INIT;

    while (_index < _length) {
        char c = getchar();
        if (_state == INIT) {
            if (c == ' ' || c == '\t') {
                start++;
                continue;
            }

            if ('0' <= c && c <= '9') {
                _state = INTEGER;
            } else if (c == '+') {
                _state = OP_ADD;
            } else if (c == '-') {
                _state = OP_SUB;
            } else if (c == '*') {
                _state = OP_MUL;
            } else if (c == '/') {
                _state = OP_DIV;
            }

            length++;
        } else if (_state == INTEGER) {
            if ('0' <= c && c <= '9') {
                length++;
            } else {
                ungetc();
                return new Token(T_INT, _s + start, length);
            }
        } else if (_state == OP_ADD) {
            ungetc();
            return new Token(T_PLUS, _s + start, length);
        } else if (_state == OP_SUB) {
            ungetc();
            return new Token(T_MINUS, _s + start, length);
        } else if (_state == OP_MUL) {
            ungetc();
            return new Token(T_MULT, _s + start, length);
        } else if (_state == OP_DIV) {
            ungetc();
            return new Token(T_DIV, _s + start, length);
        }
    }
    return nullptr;
}

Token *Lexer::filter_keyword(Token *t) {
    return nullptr;
}

