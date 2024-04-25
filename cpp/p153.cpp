#include <bits/stdc++.h>

using namespace std;

int findMin(const vector<int> &nums);

int main() {
//    vector<int> nums{1, 2, 3, 4, 5};
    vector<int> nums {4,5,6,7,0,1,2};
//    vector<int> nums{3, 1, 2};
    cout << findMin(nums);
    return 0;
}

//int findMin(const vector<int> &nums) {
//    int left = 0, right = nums.size() - 1;
//
//    while (left < right) {
//        int mid = (left + right) / 2;
//
//        if (nums[mid] > nums[right]) {
//            left = mid + 1;  // +1 coz we have op> here
//        } else {
//            right = mid;  // op <= here, so we don't have +1
//        }
//    }
//
//    return nums[left];
//}

int findMin(const vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int result = numeric_limits<int>::max();

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[left] <= nums[mid]) {
            // if left half is sorted
            result = min(result, nums[left]);
            left = mid + 1;
        } else {
            result = min(result, nums[mid]);
            right = mid - 1;
        }
    }

    return result;
}
