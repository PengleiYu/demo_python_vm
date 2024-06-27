//
// Created by yupenglei on 2024/6/24.
//

#include "codeGen.h"
#include "op_code.h"
#include "codeObj.h"

void CodeGen::visit(BinaryOp *n) {
    visit(n->getLeft());
    visit(n->getRight());

    switch (n->getOpType()) {
        case AST_OP_ADD:
            add_op(BINARY_ADD);
            break;
        case AST_OP_SUB:
            add_op(BINARY_SUB);
            break;
        case AST_OP_MUL:
            add_op(BINARY_MUL);
            break;
        case AST_OP_DIV:
            add_op(BINARY_DIV);
            break;
        default:
            printf("未知二元操作符 %d\n", n->getOpType());
            break;
    }
}

void CodeGen::visit(ConstInt *n) {
    add_op(LOAD_CONST, n->_value);
}

void CodeGen::visit(Node *n) {
    // todo 不重写有问题吗？
//    Visitor::visit(n);
    n->accept(this);
}

void CodeGen::add_op(unsigned char op_code, unsigned char param) {
    _instructions.push_back(op_code);
    if (op_code > HAVE_ARGUMENT) {
        _instructions.push_back(param);
    }
}

CodeObject *CodeGen::make_code_object() {
    return new CodeObject(_instructions);
}

void CodeGen::dump() {
    for (unsigned char _instruction: _instructions) {
        printf("%d\n", _instruction);
    }
}

