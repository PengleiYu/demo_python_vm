//
// Created by yupenglei on 2024/6/27.
//

#include <cstring>
#include "hiString.h"

HiString::HiString(const char *x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
}

HiString::HiString(const char *x, const int length) {
    _length = length;
    _value = new char[_length];
    for (int i = 0; i < length; ++i) {
        _value[i] = x[i];
    }
}
