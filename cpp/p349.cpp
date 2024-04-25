#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(const vector<int> &nums1, const vector<int> &nums2) {
    // nums1 element -> nums1 element count
    unordered_map<int, bool> count;
    vector<int> result;

    for (int num: nums1) {
        count[num] = true;
    }

    for (int num: nums2) {
        if (count[num]) {
            count[num] = false;
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};

    for (int num : intersection(nums1, nums2)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}