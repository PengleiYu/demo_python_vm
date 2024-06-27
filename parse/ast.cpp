//
// Created by yupenglei on 2024/6/19.
//

#include "ast.h"
#include "visitor.h"

void BinaryOp::accept(Visitor *v) {
    v->visit(this);
}

void ConstInt::accept(Visitor *v) {
    v->visit(this);
}
