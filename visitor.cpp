//
// Created by yupenglei on 2024/6/19.
//
#include <cstdio>

#include "visitor.h"

void Visitor::visit(Node *n) {
    n->accept(this);
}

void PrintVisitor::visit(Node *n) {
    n->accept(this);
}

void PrintVisitor::visit(BinaryOp *n) {
    visit(n->getLeft());
    visit(n->getRight());

    switch (n->getOpType()) {
        case AST_OP_ADD:
            printf("binary_add\n");
            break;
        case AST_OP_SUB:
            printf("binary_sub\n");
            break;
        case AST_OP_MUL:
            printf("binary_mul\n");
            break;
        case AST_OP_DIV:
            printf("binary_div\n");
            break;
        default:
            printf("unknown binary op %d\n", n->getOpType());
            break;
    }
}

void PrintVisitor::visit(ConstInt *n) {
    printf("load_const\t%d\n", n->_value);
}
