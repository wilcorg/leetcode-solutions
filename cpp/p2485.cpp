#include <iostream>

int pivotInteger(int n) {
    int lhs = 0;
    int rhs = (n * (n + 1)) / 2;

    for (int i = 1; i <= n; i++) {
        lhs += i;
        rhs -= (i - 1);

        if (lhs == rhs) {
            return i;
        }
    }

    return -1;
}

int main() {
    std::cout << pivotInteger(8);
    return 0;
}