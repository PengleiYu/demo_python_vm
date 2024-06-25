//
// Created by yupenglei on 2024/6/24.
//

#ifndef DEMO_VM_CODEOBJ_H
#define DEMO_VM_CODEOBJ_H

#include "vector"
#include "iostream"
#include "string"

class CodeObject {
private:
    std::vector<unsigned char> &_instructions;

public:
    explicit CodeObject(std::vector<unsigned char> &instructions) : _instructions(instructions) {}

    int save_to_file(std::ofstream &file);

    int save_code_to_file(std::ofstream &file);

    template<typename T>
    int save_const_value(T t, std::ofstream& file);

    static int write_to_file(std::string &filename, CodeObject &co);
};


#endif //DEMO_VM_CODEOBJ_H
