#include <bits/stdc++.h>
using namespace std;

int characterReplacement(const string& s, int k) {
    const int n = s.size();
    unordered_map<char, int> letter_count;
    int l = 0;
    int ans = 0;
    int max_count = 0;

    for (int r = 0; r < n; r++) {
        letter_count[s[r]] += 1;
        max_count = max(max_count, letter_count[s[r]]);

        while ((r - l + 1 - max_count) > k) {
            letter_count[s[l]] -= 1;
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    return ans;
}

int main() {
    string s = "ABAB";
    int k = 2;

    cout << characterReplacement(s, k);
    return 0;
}