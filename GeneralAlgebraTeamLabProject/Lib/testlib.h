#ifndef TESTLIB_H
#define TESTLIB_H

#include "Lib_global.h"

class LIB_EXPORT TestLib
{
public:
    TestLib();
private:
    int i = 0;
public:
    void set_i(int input);
    int get_i();
};

#endif // TESTLIB_H
