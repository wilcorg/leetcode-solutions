#include <iostream>

//bool isPalindrome(int x) {
//    if (x < 0) {
//        return false;
//    } else if (x <= 9) {
//        return true;
//    } else {
//        int x_copy = x;
//        int num_length = 0;
//
//        while (x_copy != 0) {
//            num_length++;
//            x_copy /= 10;
//        }
//
//        int mid = num_length / 2;
//
//        for (int i = 0; i < mid; i++) {
//            int left_digit = static_cast<int>(x / powf32x(10, (num_length - 1 - i))) % 10;
//            int right_digit = static_cast<int>(x / powf32x(10, i)) % 10;
//
//            if (left_digit != right_digit) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//}

bool isPalindrome(long long x) {

    if (x < 0) {
        return false;
    } else if (x <= 9) {
        return true;
    } else {
        long long reversed = 0, x_copy = x;

        while (x_copy > 0) {
            reversed = reversed * 10 + x_copy % 10;
            x_copy /= 10;
        }
        return reversed == x;
    }
}

int main() {
    std::cout << isPalindrome(123454321) << std::endl;
    return 0;
}