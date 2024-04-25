#include <bits/stdc++.h>
using namespace std;

//int lengthOfLongestSubstring(const std::string& s) {
//    std::unordered_map<char, int> memory;
//    int high_bound = 0, low_bound = 0;
//    int maximum = 0;
//
//    while (high_bound < s.size()) {
//        if (memory[s[high_bound]] == 0) {
//            memory[s[high_bound]] += 1;
//            high_bound += 1;
//
//            if (high_bound - low_bound > maximum) {
//                maximum = high_bound - low_bound;
//            }
//        } else {
//            while (memory[s[high_bound]] != 0) {
//                memory[s[low_bound]] = 0;
//                low_bound++;
//            }
//        }
//    }
//    return maximum;
//}

int lengthOfLongestSubstring(const std::string& s) {
    int n = s.size();
    // char_index stores the subarray index when char occurred at the first time
    std::vector<int> char_index(128, -1);
    int max_length = 0;
    int low_bound = 0, high_bound = 0;

    while (high_bound < n) {
        // character already in subarray
        if (char_index[s[high_bound]] >= low_bound) {
            // subarray now starts with the next index of duplicated char
            low_bound = char_index[s[high_bound]] + 1;
        }

        char_index[s[high_bound]] = high_bound;
        max_length = std::max(max_length, high_bound - low_bound + 1);

        high_bound += 1;
    }
    return max_length;
}

int main() {
//    std::string input = "abcabcbb";
    std::string input = "bbbb";
//    std::string input = "abcabcbb";
    std::cout << lengthOfLongestSubstring(input) << std::endl;
    return 0;
}