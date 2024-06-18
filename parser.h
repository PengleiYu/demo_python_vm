//
// Created by yupenglei on 2024/6/19.
//

#ifndef DEMO_VM_PARSER_H
#define DEMO_VM_PARSER_H

#include "ast.h"
#include "lexer.h"


class Parser {
private:
    Lexer *_lex;
    Token *_cur_token;
public:
    explicit Parser(Lexer *lex) : _lex(lex), _cur_token(nullptr) {}

    virtual ~Parser() = default;

    Node *parse();

    void consume();

    Token *getToken();

    void match(TokenType tt);

    Node *expression();

    Node *term();

    Node *factor();

    int stoi(Token *data);
};


#endif //DEMO_VM_PARSER_H
