#include <bits/stdc++.h>

using namespace std;

vector<int> merge(vector<vector<int>>& vecs);

vector<int> kMergeSort(vector<int> &nums, int k);

int main() {
//    vector<vector<int>> vecs = {{0, 5, 10, 15, 20},
//                                {3, 8, 13, 18, 23},
//                                {2, 7, 12, 17, 22, 110, 145},
//                                {1, 6, 11, 16, 21, 666},
//                                {4, 9, 14, 19, 24}};
//    auto result = merge(vecs);

    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto result = kMergeSort(nums, 3);

    return 0;
}

vector<int> kMergeSort(vector<int> &nums, int k) {
    if (nums.size() == 1) {
        return nums;
    }
    vector<vector<int>> results;
    for (int i = 0; i < k; i++) {
        auto start = nums.begin() + (nums.size() / k * i);
        auto end = nums.begin() + (nums.size() / k * (i + 1));
        vector<int> slice(start, end);
        results.push_back(kMergeSort(slice, k));
    }

    return merge(results);
}

vector<int> merge(vector<vector<int>> &vecs) {
    const int n = (int) vecs.size();
    vector<int> ans;
    map<int, int> val_of_list;

    for (int i = 0; i < n; i++) {
        if (!vecs[i].empty()) {
            val_of_list[vecs[i].at(0)] = i;
            vecs[i].erase(vecs[i].begin());
        }
    }

    do {
        const auto &pair = val_of_list.begin();
        ans.push_back(pair->first);
        if (!vecs[pair->second].empty()) {
            val_of_list[vecs[pair->second].at(0)] = pair->second;
            vecs[pair->second].erase(vecs[pair->second].begin());
        }
        val_of_list.erase(pair->first);
    } while (!val_of_list.empty());

    return ans;
}
