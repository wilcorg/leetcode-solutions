#include <bits/stdc++.h>

using namespace std;

//int maximumStrongPairXor(vector<int> &nums) {
//    sort(nums.begin(), nums.end());
//    const int n = nums.size();
//    int j = 0;
//    int delta = 0;
//    int maxi = 0;
//
//    for (int i = 0; i < n; i++) {
//        j = i;
//
//        while (j < n) {
//            delta = nums[j] - min(nums[i], nums[j]);
//
//            if (delta <= nums[i]) {
//                maxi = max(maxi, nums[j] ^ nums[i]);
//            } else {
//                break;
//            }
//
//            j++;
//        }
//    }
//
//    return maxi;
//}

int maximumStrongPairXor(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    int j = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        // i >= j
        while (i < n && (nums[i] - nums[j] <= min(nums[i], nums[j]))) {
            maxi = max(maxi, nums[i] ^ nums[j]);
            i++;
        }

        // j is an `i` copy
        i = j;
        j++;
    }

    return maxi;
}

int main() {
    vector<int> nums{5, 6, 25, 30};
    cout << maximumStrongPairXor(nums);
    return 0;
}