//
// Created by yupenglei on 2024/6/19.
//

#include <cstdio>
#include <cassert>
#include "parser.h"

Token *Parser::getToken() {
    if (_cur_token == nullptr) {
        _cur_token = _lex->next();
//        if (_cur_token) {
//            _cur_token->print();
//        }
    }
    return _cur_token;
}

void Parser::consume() {
    _cur_token = nullptr;
}

Node *Parser::parse() {
    return expression();
}

void Parser::match(TokenType tt) {
    Token *token = getToken();
    if (token->_tt != tt) {
        printf("语法解析失败：预期%d，但得到了%d\n", tt, token->_tt);
        assert(token->_tt == tt);
    } else {
        consume();
    }
}

int Parser::stoi(Token *data) {
    int value = 0;
    for (int i = 0; i < data->_length; ++i) {
        value = value * 10 + data->_value[i] - '0';
    }
    return value;
}

// expression是加减号连接的多个term
Node *Parser::expression() {
    Node *term1 = term();
    Token *pToken = getToken();
    while (pToken != nullptr &&
           (pToken->_tt == T_PLUS || pToken->_tt == T_MINUS)) {
        consume();

        OpType opType = pToken->_tt == T_PLUS ? AST_OP_ADD : AST_OP_SUB;
        Node *term2 = term();

        term1 = new BinaryOp(opType, term1, term2);
        pToken = getToken();
    }
    return term1;
}

// term是乘除号连接的多个factor
Node *Parser::term() {
    Node *factor1 = factor();
    Token *pToken = getToken();
    while (pToken != nullptr &&
           (pToken->_tt == T_MULT || pToken->_tt == T_DIV)) {
        consume();

        OpType opType = pToken->_tt == T_MULT ? AST_OP_MUL : AST_OP_DIV;
        Node *factor2 = factor();

        factor1 = new BinaryOp(opType, factor1, factor2);
        pToken = getToken();
    }
    return factor1;
}

// factor可能是int或expression
// TODO 待处理括号
Node *Parser::factor() {
    Token *pToken = getToken();
    if (pToken->_tt == T_INT) {
        consume();
        return new ConstInt(stoi(pToken));
    } else {
        return expression();
    }
    return nullptr;
}
