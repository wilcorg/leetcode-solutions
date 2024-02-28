#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> &&nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> answer;

    if (nums.size() < 3) {
        return answer;
    }

    for (size_t i = 0; i < nums.size(); i++) {
        // threshold index that will be increased
        // next numbers are guaranteed to be positive, so 1st num can't be >0
        if (nums[i] > 0) {
            break;
        }

        // since nums are sorted, duplicated values will produce the same result AND will be the next element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // next element from the bound (lowest)
        size_t low = i + 1;
        // last element in array (highest)
        size_t high = nums.size() - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];

            if (sum > 0) {  // sum is positive -> decrease high bound
                high--;
            } else if (sum < 0) {  // sum is negative -> increase low bound
                low++;
            } else {  // zero case
                int last_low_occurrence = nums[low];
                int last_high_occurrence = nums[high];

                answer.push_back({nums[i], nums[low], nums[high]});

                while (low < high && nums[low] == last_low_occurrence) {
                    low++;
                }

                while (low < high && nums[high] == last_high_occurrence) {
                    high--;
                }
            }
        }
    }
    return answer;
}

int main() {
    auto result = threeSum(
            std::vector<int>{-1, 0, 1, 2, -1, 4});
    return 0;
}
