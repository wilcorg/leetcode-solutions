#include <iostream>
#include <vector>
#include <cassert>
#include <limits>
#include <algorithm>
#include <climits>

//int maxSubArray(const std::vector<int>& nums) {
//    const size_t size = nums.size();
//    int maxSum = nums[0];
//    int firstInd = 0;
//    int lastInd = 1;
//
//    while (firstInd < size && lastInd <= size) {
//        int candidate = arraySum(nums, firstInd, lastInd);
//        if (candidate >= maxSum && lastInd < size) {
//            maxSum = candidate;
//            lastInd += 1;
//        } else {
//            firstInd += 1;
//        }
//
//        if (firstInd == lastInd) {
//            lastInd += 1;
//        }
//    }
//
//    return maxSum;
//}

//// recursive solution - O(n^2) time, O(n) space
//int solve(const std::vector<int> &nums, int i, bool toTake) {
//    if (i == nums.size()) {
//        if (toTake) {
//            // case when algorithm selected last array element and there is no next element
//            return 0;
//        } else {
//            // case when algorithm selected any element for subarray
//            return std::numeric_limits<int>::min();
//        }
//    }
//
//    if (toTake) {
//        // algorithm stops subarray on nums[i - 1] inclusively or continues taking elements
//        // if subarray from nums[i] is going to be negative, algorithm stops taking elements
//        return std::max(0, nums[i] + solve(nums, i + 1, true));
//    } else {
//        // subarray hasn't started yet, algorithm can either start subarray or skip current element
//        return std::max(solve(nums, i + 1, false), nums[i] + solve(nums, i + 1, true));
//    }
//}
//
//int maxSubArray(const std::vector<int> &nums) {
//    return solve(nums, 0, false);
//}

//// recursive solution with results caching - O(n) time, O(n) space
//int solve(const std::vector<int> &nums, int i, bool toTake, std::vector<std::vector<int>>& cache) {
//    if (i == nums.size()) {
//        if (toTake) {
//            // case when algorithm selected last array element and there is no next element
//            return 0;
//        } else {
//            // case when algorithm selected any element for subarray
//            return std::numeric_limits<int>::min();
//        }
//    }
//
//    if (cache[toTake][i] != std::numeric_limits<int>::min()) {
//        return cache[toTake][i];
//    }
//
//    if (toTake) {
//        // algorithm stops subarray on nums[i - 1] inclusively or continues taking elements
//        // if subarray from nums[i] is going to be negative, algorithm stops taking elements
//        return cache[toTake][i] = std::max(0, nums[i] + solve(nums, i + 1, true, cache));
//    } else {
//        // subarray hasn't started yet, algorithm can either start subarray or skip current element
//        return cache[toTake][i] = std::max(solve(nums, i + 1, false, cache), nums[i] + solve(nums, i + 1, true, cache));
//    }
//}
//
//int maxSubArray(const std::vector<int> &nums) {
//    // 2-dimensional array 2 x <nums_size> filled with INT_MIN
//    std::vector<std::vector<int>> cache(2, std::vector<int>(nums.size(), std::numeric_limits<int>::min()));
//    return solve(nums, 0, false, cache);
//}

//// linear dynamic programming approach, O(n) time, O(n) space
//int maxSubArray(const std::vector<int>& nums) {
//    // 2-dimensional array 2 x <nums_size>, fill value doesn't matter
//    std::vector<std::vector<int>> cache(2, std::vector<int>(size(nums)));
//
//    // first index defines toTake var: 0 -> toTake = false; 1 -> toTake = true
//    // cache[1][i] stores maximum subarray sum **ending at** i
//    // cache[0][i] stores maximum subarray sum **upto** i
//    cache[0][0] = nums[0];
//    cache[1][0] = nums[0];
//
//    for (int i = 1; i < size(nums); i++) {
//        // we update cache[1][i] as max **either by** choosing current element as max
//        // OR sum current element with previous one (also subarray sum)
//
//        // if subarray with new element sum is going to be smaller than new element itself
//        // OR new element is greater than subarray with new element sum
//        // it will abandon and create new subarray based on current element
//        cache[1][i] = std::max(nums[i], nums[i] + cache[1][i - 1]);
//
//        // maximum subarray sum so far between maximum subarray sum
//        // AND separate element if it greater than subarray sum
//        cache[0][i] = std::max(cache[0][i - 1], cache[1][i]);
//    }
//
//    return cache[0][nums.size() - 1];
//}

//// Kadane's algorithm, O(n) time, O(1) space
//int maxSubArray(const std::vector<int>& nums) {
//    int currentMax = 0;
//    int maxTillNow = std::numeric_limits<int>::min();
//
//    for (const int& num : nums) {
//        // if subarray with new element sum is going to be smaller than new element itself
//        // OR new element is greater than subarray with new element sum
//        // it will abandon and create new subarray sum based on current element
//        currentMax = std::max(num, currentMax + num);
//
//        // maximum subarray sum so far between maximum subarray sum
//        // AND separate element if it greater than subarray sum
//        maxTillNow = std::max(maxTillNow, currentMax);
//    }
//    return maxTillNow;
//}

// Divide & Conquer, O(n*log(n)) time, O(n) space
//int maxSubArray(const std::vector<int> &nums, int left, int right) {
//    if (left > right) {
//        return std::numeric_limits<int>::min();
//    }
//    int mid = (left + right) / 2;
//
//    // max subarray sum in [L, mid-1], starts from mid-1
//    int leftSum = 0;
//    // max subarray sum in [mid+1, R], starts from mid+1
//    int rightSum = 0;
//
//    int currentSum = 0;
//    for (int i = mid - 1; i >= left; i--) {
//        currentSum += nums[i];
//        leftSum = std::max(leftSum, currentSum);
//    }
//
//    currentSum = 0;
//    for (int i = mid + 1; i <= right; i++) {
//        currentSum += nums[i];
//        rightSum = std::max(rightSum, currentSum);
//    }
//    std::vector<int> subarraySums = {maxSubArray(nums, left, mid - 1), maxSubArray(nums, mid + 1, right),
//                                     leftSum + nums[mid] + rightSum};
//
//    return *std::max_element(subarraySums.begin(), subarraySums.end());
//}


int maxSubArray(std::vector<int> &A, int L, int R) {
    if (L > R) return INT_MIN;
    int mid = (L + R) / 2, leftSum = 0, rightSum = 0;
    // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
    for (int i = mid - 1, curSum = 0; i >= L; i--)
        curSum += A[i],
                leftSum = std::max(leftSum, curSum);
    // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
    for (int i = mid + 1, curSum = 0; i <= R; i++)
        curSum += A[i],
                rightSum = std::max(rightSum, curSum);
    // return max of 3 cases
    std::cout << "\n-----------------------------------------------------------------------\n";
    std::cout << "L = " << L << "; R = " << R << "; mid = " << mid << std::endl;
    std::cout << "leftSum = " << leftSum << "; rightSum = " << rightSum << "; A[mid] = " << A[mid] << std::endl;
    std::cout << "subarray sum: " << leftSum + A[mid] + rightSum << std::endl;
    std::cout << "-----------------------------------------------------------------------\n" << std::endl;
    return std::max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R), leftSum + A[mid] + rightSum});
}

int maxSubArray(std::vector<int> &nums) {
    return maxSubArray(nums, 0, size(nums) - 1);
}

int main() {
    std::vector<int> input{-7, 9, -8, -10, 110, -7};
//    std::vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubArray(input) << std::endl;
    return 0;
}