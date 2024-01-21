#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

using namespace std;

int lambda_with_destructor() {
    auto l = [i = [] {
        struct S {
            S() {
                cout << "Constructor" << endl;
            }
            S(const S&) {
                cout << "Copy Constructor" << endl;
            }
            ~S() {
                cout << "Destructor" << endl;
            }
        };
        return S{};
    }()
    ] {
        return i;
    };
    auto l2 = l;
    return 0;
}

TEST_CASE("lambda_with_destructor") {
    lambda_with_destructor();
}