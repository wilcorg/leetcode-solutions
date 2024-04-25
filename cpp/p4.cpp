#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = (int) nums1.size();
    int n = (int) nums2.size();

    if (m > n) {
        swap(nums1, nums2);
        swap(m, n);
    }

    // points to nums1
    int left = 0;
    int right = m;

    // midpoint of the combined array
    int mid = (m + n + 1) / 2;

    while (left <= right) {
        int partition1 = left + right / 2;
        int partition2 = mid - partition1;

        int max_left1 = (partition1 == 0) ? numeric_limits<int>::min() : nums1[partition1 - 1];
        int min_right1 = (partition1 == m) ? numeric_limits<int>::max() : nums1[partition1];

        int max_left2 = (partition2 == 0) ? numeric_limits<int>::min() : nums2[partition2 - 1];
        int min_right2 = (partition2 == n) ? numeric_limits<int>::max() : nums2[partition2];

        if (max_left1 <= min_right2 && max_left2 <= min_right1) {
            // found the correct partitions
            if ((m + n) % 2 == 0) {
                // even
                return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
            } else {
                // odd
                return max(max_left1, max_left2);
            }
        } else if (max_left1 > min_right2) {
            // adj partition1 to the left
            right = partition1;
        } else {
            // adj partition1 to the right
            left = partition1 + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}