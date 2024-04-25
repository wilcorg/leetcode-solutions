#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(const vector<int>& nums, int goal) {
    int sum = 0;
    int count = 0;
    vector<int> ps(nums.size() + 1, 0);
    ps[0] = 1;

    for (int num: nums) {
        sum += num;
        if (sum >= goal) {
            // since our array is binary, we count subarrays that
            // prefix sum starts with sum - goal and ends with goal
            count += ps[sum - goal];
        }
        ps[sum] ++;
    }

    return count;
}

int main() {
    vector<int> nums {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal);
    return 0;
}