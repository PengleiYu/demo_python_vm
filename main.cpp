#include <execinfo.h>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include "string"

#include "lexer.h"
#include "parser.h"
#include "visitor.h"
#include "codeObj.h"
#include "codeGen.h"

void test_lexer(const char *filename) {
    Lexer lexer(filename);
    Token *t;
    while ((t = lexer.next())) {
        t->print();
    }
}

void test_parser(const char *filename) {
    Lexer lexer(filename);
    Parser parser(&lexer);
    CodeGen visitor;
    Node *pNode = parser.parse();
    visitor.visit(pNode);

    CodeObject *codeObject = visitor.make_code_object();
    CodeObject::write_to_file(std::string(filename).append("c"), *codeObject);
}


void signal_handler(int signum) {
    void *array[10];
    size_t size;

    // 得到void*指针的数组
    size = backtrace(array, 10);

    // 打印出所有的帧
    std::cerr << "Error: signal " << signum << ":\n";
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

int main() {
    signal(SIGSEGV, signal_handler);   // 注册信号处理函数

    const char *filename = "test_token.txt";
//    test_lexer(filename);
    test_parser(filename);
    return 0;
}
