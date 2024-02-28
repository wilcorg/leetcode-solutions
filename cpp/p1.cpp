#include <vector>
#include <unordered_map>

// 7 ms & 14.13 MB
std::vector<int> twoSum(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> numMap;
    size_t n = nums.size();
    std::vector<int> result = {};

    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];

        if (numMap.count(complement) > 0) {
            result = {i, numMap[complement]};
            return result;
        }
        numMap[nums[i]] = i;
    }
    return result;
}

int main() {
    auto result = twoSum(std::vector<int>{3, 2, 4}, 6);
    return 0;
}