#include <iostream>
#include <string>

//bool isPalindrome(const std::string &s);
//
//std::string longestPalindrome(const std::string &s) {
//    if (s.length() == 1) {
//        return s;
//    }
//
//    std::string max_string = s.substr(0, 1);
//    int max_len = 1;
//
//    for (int i = 0; i < s.length() - 1; i++) {
//        for (int j = i + 1; j <= s.length(); j++) {
//            if (j - i > max_len && isPalindrome(s.substr(i, j - i))) {
//                max_len = j - i;
//                max_string = s.substr(i, j - i);
//            }
//        }
//    }
//
//    return max_string;
//}
//
//bool isPalindrome(const std::string &s) {
//    size_t n = s.length();
//    size_t mid = n / 2;
//
//    if (n <= 1) {
//        return true;
//    }
//
//    for (size_t i = 0; i <= mid; i++) {
//        if (s[i] != s[n - 1 - i]) {
//            return false;
//        }
//    }
//    return true;
//}

std::string maxPalindrome(const std::string& s, int left, int right);

std::string longestPalindrome(const std::string& s) {
    if (s.length() <= 1) {
        return s;
    }

    std::string max_pal = s.substr(0, 1);

    for (int i = 0; i < s.length() - 1; i++) {
        // odd palindrome
        const std::string& odd_pal = maxPalindrome(s, i, i);
        // even palindrome
        const std::string& even_pal = maxPalindrome(s, i, i + 1);

        if (odd_pal.length() > max_pal.length()) {
            max_pal = odd_pal;
        }
        if (even_pal.length() > max_pal.length()) {
            max_pal = even_pal;
        }
    }

    return max_pal;
}

// take next left and right elements and checks that this string is still the palindrome
std::string maxPalindrome(const std::string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left -= 1;
        right += 1;
    }
    return s.substr(left + 1, right - left - 1);
}


int main() {
//    const std::string input = "babad";
    const std::string input = "azaza";
    std::cout << longestPalindrome(input) << std::endl;
    return 0;
}