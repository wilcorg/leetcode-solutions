#include <bits/stdc++.h>

using namespace std;

//int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
//    const int r = (int) nums.size();
//    int c = 0;
//    int a = 0;
//    int p = 1;
//    int l;
//
//    while (c < r) {
//        l = c;
//        while (l >= 0) {
//            p *= nums[l];
//            if (p < k) {
//                l--;
//                a++;
//            } else {
//                break;
//            }
//        }
//        c++;
//        p = 1;
//    }
//
//    return a;
//}

int numSubarrayProductLessThanK(const vector<int> &nums, int k) {
    if (k <= 1) return 0;

    int left = 0;
    int right = 0;
    int product = 1;
    int count = 0;
    int n = (int) nums.size();

    while (right < n) {
        product *= nums[right];

        while (product >= k) {
            product /= nums[left];
            left++;
        }
        count += 1 + (right - left);  // for [a, b, c] add new cases: [c], [b, c], [a, b, c]
        right++;
    }

    return count;
}

int main() {
    vector<int> nums{10, 5, 2, 6};
    int k = 100;
    cout << numSubarrayProductLessThanK(nums, k);
    return 0;
}