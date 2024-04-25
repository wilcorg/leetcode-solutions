#include <bits/stdc++.h>

using namespace std;

int searchInsert(const vector<int>& nums, int target) {
   int left = 0;
   int right = nums.size() - 1;

   if (target > nums[right]) {
       return nums.size();
   }

   while (left <= right) {
       int mid = (left + right) / 2;
       int cur = nums[mid];

       if (cur == target) {
           return mid;
       } else if (target < cur) {
           right = mid - 1;
       } else {
           left = mid + 1;
       }
   }
    return left;
}

int main() {
    vector<int> nums {1, 3, 5, 6};
    int target = 0;

    cout << searchInsert(nums, target);
    return 0;
}