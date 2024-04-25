#include <bits/stdc++.h>

using namespace std;

//int search(vector<int> &nums, int target) {
//    int n = nums.size();
//    int pivot = 0;
//    int left = 0;
//    int right = n - 1;
//
//    for (int i = 0; i < nums.size(); i++) {
//        if (nums[((i - 1) % n + n) % n] < nums[i]) {
//            pivot++;
//        } else {
//            break;
//        }
//    }
//
//    while (left <= right) {
//        int mid = (left + right) / 2;
//        int mid_pivot = (mid + pivot) % n;
//
//        if (nums[mid_pivot] == target) {
//            return mid_pivot;
//        } else if (nums[mid_pivot] < target) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//
//    return -1;
//}

int search(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // if left half is sorted
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                // dive into this subarray
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } // since array is rotated, right half must be sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                // dive into this subarray
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 5;
    cout << search(nums, target);
    return 0;
}