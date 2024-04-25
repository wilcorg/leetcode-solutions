#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string& s1, string& s2) {
    unordered_map<char, int> s1_count;
    unordered_map<char, int> s2_count;

    for (const auto& c: s1) {
        s1_count[c] += 1;
    }

    for (const auto& c: s2) {
        s2_count[c] += 1;
    }

    for (const auto& entry: s1_count) {
        if (entry.second > s2_count[entry.first]) {
            return false;
        }
    }

    return true;
}

int main() {
    return 0;
}