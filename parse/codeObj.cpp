//
// Created by yupenglei on 2024/6/24.
//

#include "codeObj.h"
#include "fstream"

int CodeObject::save_to_file(std::ofstream &file) {
    return save_code_to_file(file);
}

int CodeObject::write_to_file(std::string &filename, CodeObject &co) {
    std::ofstream file = std::ofstream(filename, std::ios::out | std::ios::binary);
    int magic_number = 0xa0df303;

    if (!file.good()) {
        std::cerr << "打开文件失败" << std::endl;
        return -1;
    }

    file.write(reinterpret_cast<const char *>(&magic_number), 4);
    int ret = co.save_to_file(file);

    file.close();
    return ret;
}

int CodeObject::save_code_to_file(std::ofstream &file) {
    std::ofstream &file1 = file;
    file1 << 's';
    save_const_value((int) _instructions.size(), file1);
    for (unsigned char instruction: _instructions) {
        file1 << instruction;
    }
    return 0;
}

template<typename T>
int CodeObject::save_const_value(T t, std::ofstream &file) {
    file.write(reinterpret_cast<const char *>(&t), sizeof(T));
    return 0;
}
