//
// Created by yupenglei on 2024/6/19.
//

#ifndef DEMO_VM_AST_H
#define DEMO_VM_AST_H

class Visitor;


class Node {
public:
    virtual void accept(Visitor *v) = 0;
};

enum OpType {
    AST_OP_ADD,
    AST_OP_SUB,
    AST_OP_MUL,
    AST_OP_DIV,
    AST_OP_MOD,
};

class BinaryOp : public Node {
protected:
    OpType _op_type;
    Node *_left;
    Node *_right;
public:
    BinaryOp(OpType opType, Node *left, Node *right) : _op_type(opType), _left(left), _right(right) {}

    void accept(Visitor *v) override;


    void setLeft(Node *left) { _left = left; }

    void setRight(Node *right) { _right = right; }

    [[nodiscard]] OpType getOpType() const { return _op_type; }

    [[nodiscard]] Node *getLeft() const { return _left; }

    [[nodiscard]] Node *getRight() const { return _right; }
};

class ConstInt : public Node {
public:
    int _value;

    explicit ConstInt(int value) : _value(value) {}

    void accept(Visitor *v) override;
};

#endif //DEMO_VM_AST_H
