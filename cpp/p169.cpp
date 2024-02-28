#include <vector>
#include <iostream>
#include <unordered_map>

//int majorityElement(const std::vector<int> &nums) {
//    std::unordered_map<int, int> elementCount;
//    size_t threshold = nums.size() / 2;
//
//    for (auto element : nums) {
//        elementCount[element] += 1;
//        if (elementCount[element] > threshold) {
//            return element;
//        }
//    }
//    return -1;
//}

int majorityElement(const std::vector<int> &nums) {
    int leadingElement;
    int count = 0;

    for (auto &element: nums) {
        if (count == 0) {
            leadingElement = element;
        }

        if (element == leadingElement) {
            count += 1;
        } else {
            count -= 1;
        }
    }
    return leadingElement;
}

int main() {
    std::vector<int> input{2, 2, 2, 2, 1, 1, 1};
    std::cout << majorityElement(input) << std::endl;
    return 0;
}