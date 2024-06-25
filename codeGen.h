//
// Created by yupenglei on 2024/6/24.
//

#ifndef DEMO_VM_CODEGEN_H
#define DEMO_VM_CODEGEN_H

#include "visitor.h"
#include "vector"

class CodeObject;

class CodeGen : public Visitor {
private:
    std::vector<unsigned char> _instructions;

public:
    [[nodiscard]] const std::vector<unsigned char> &getInstructions() const { return _instructions; }

    void add_op(unsigned char op_code, unsigned char param = 0);

    CodeObject *make_code_object();

    void dump();

    void visit(Node *n) override;

    void visit(BinaryOp *n) override;

    void visit(ConstInt *n) override;
};


#endif //DEMO_VM_CODEGEN_H
