#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(const vector<int>& nums) {
    const int n = (int) nums.size();
    vector<int> ps(n, 0);

    // result[i] = 1 * result[0] * result[1] * ... * result[i - 1]
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        ps[i] = prefix;
        prefix *= nums[i];
    }

    // result[i] = result[i] * result[n - 1] * result[n - 2] * ... * result[i + 1]
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ps[i] *= postfix;
        postfix *= nums[i];
    }

    return ps;
}

int main() {
    vector<int> nums{1, 2, 3, 4};
    auto result = productExceptSelf(nums);
    return 0;
}