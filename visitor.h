//
// Created by yupenglei on 2024/6/19.
//

#ifndef DEMO_VM_VISITOR_H
#define DEMO_VM_VISITOR_H

#include "parser.h"

class Visitor {
public:
    virtual void visit(Node *n);

    virtual void visit(BinaryOp *n) = 0;

    virtual void visit(ConstInt *n) = 0;
};

class PrintVisitor : public Visitor {
public:
    void visit(Node *n) override;

    void visit(BinaryOp *n) override;

    void visit(ConstInt *n) override;
};

#endif //DEMO_VM_VISITOR_H
