#include <bits/stdc++.h>

using namespace std;

string customSortString(const string &order, const string &s) {
    unordered_map<char, int> letter_count;
    string answer;
    answer.reserve(s.length() + 1);

    for (char letter: s) {
        letter_count[letter]++;
    }

    for (char letter: order) {
        while (letter_count[letter] != 0) {
            answer += letter;
            letter_count[letter]--;
        }
    }

    for (auto &entry: letter_count) {
        while (entry.second != 0) {
            answer += entry.first;
            entry.second--;
        }
    }
    return answer;
}

int main() {
    string order = "kqep";
    string s = "pekeq";
    cout << customSortString(order, s);
    return 0;
}