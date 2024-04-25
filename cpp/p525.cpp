#include <bits/stdc++.h>
using namespace std;

int findMaxLength(const vector<int>& nums) {
    const int n = (int) nums.size();
    // vec el -> last el index
    unordered_map<int, int> last_index;
    int sum = 0;
    int dist = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            sum += -1;
        } else {
            sum += 1;
        }

        if (sum == 0) {
            dist = i + 1;
        } else if (last_index.find(sum) != last_index.end()) {
            dist = max(dist, i - last_index[sum]);
        } else {
            last_index[sum] = i;
        }
    }

    return dist;
}

int main() {
//    vector<int> nums {0, 1, 1, 1, 1, 1, 0, 1, 0, 1};
    vector<int> nums {0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
    cout << findMaxLength(nums);
    return 0;
}