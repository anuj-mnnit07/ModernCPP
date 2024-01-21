#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include <iostream>
using namespace std;

constexpr long double operator"" _cm(long double x) { return x*10; }
constexpr int operator"" _binary(const char* str, size_t len) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = ret << 1;
        if(str[i] == '1')
            ret += 1;
    }
    return ret;
}

TEST_CASE("user_defined_literals") {
    long double x = 10.0_cm;
    cout << "x = " << x << endl;
    int binary = "100"_binary;
    cout << "binary = " << binary << endl;
}