#include <iostream>
#include <cassert>
#include "User.h"
using namespace std;
void test() {
    User u;
    u.setData("1","A","B",100);

    assert(u.getBalance() == 100);
}

int main() {
    test();
    cout << "Tests passed\n";
}