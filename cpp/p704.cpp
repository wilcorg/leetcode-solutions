#include <vector>
#include <iostream>

int search(const std::vector<int> &nums, int target) {
    size_t left = 0;
    size_t right = nums.size() - 1;

    while (left <= right) {
        size_t mid = (left + right) / 2;

        if (nums[mid] == target) {
            return (int) mid;
        } else if (nums[mid] < target) {
            right = mid + 1;
        } else {
            left = mid - 1;
        }
    }
    return -1;
}

int main() {
    int target = -1;
//    std::vector<int> nums{-1, 0, 3, 5, 9, 12};
    std::vector<int> nums{-1};

    std::cout << search(nums, target);
    return 0;
}