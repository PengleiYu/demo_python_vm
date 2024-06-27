//
// Created by yupenglei on 2024/6/27.
//

#ifndef DEMO_VM_HISTRING_H
#define DEMO_VM_HISTRING_H


class HiString {
private:
    char *_value;
    int _length;


public:
    HiString(const char * x);

    HiString(const char * x, const int length);

    [[nodiscard]] char *value() const { return _value; }

    char **value_address() { return &_value; }

    [[nodiscard]] int length() const { return _length; }
};

#endif //DEMO_VM_HISTRING_H
