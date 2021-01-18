// Copyright 2021 SharunovEvgeny
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string inf = "(2 + 8.3) * (6 - 3.2)";
    std::cout << infix2postfix(inf) << std::endl;
    inf = "(123 + 123.23 * 22) + (23 - 11) + 22 / 1";
    std::cout << infix2postfix(inf) << std::endl;
    inf = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
    std::cout << infix2postfix(inf) << std::endl;
    inf = "999 - 111";
    std::cout << infix2postfix(inf) << std::endl;
    return 0;
}
