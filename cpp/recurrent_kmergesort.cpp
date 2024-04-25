#include <bits/stdc++.h>

using namespace std;

//vector<int> mergeTwoLists(vector<int>& leftVector, vector<int>& rightVector) {
//    vector<int> result = {};
//    while (leftVector.size() + rightVector.size() != 0) {
//        if (leftVector.empty()){
//            result.push_back(rightVector.front());
//            rightVector.erase(rightVector.begin());
//        } else if (rightVector.empty()){
//            result.push_back(leftVector.front());
//            leftVector.erase(leftVector.begin());
//        } else {
//            if (leftVector.front() < rightVector.front()) {
//                result.push_back(leftVector.front());
//                leftVector.erase(leftVector.begin());
//            } else {
//                result.push_back(rightVector.front());
//                rightVector.erase(rightVector.begin());
//            }
//        }
//    }
//    return result;
//}
//
//vector<int> merge(vector<vector<int>> &subvector, int left, int right) {
//    if (left == right) {
//        return subvector[left];
//    }
//
//    if (left + 1 == right) {
//        return mergeTwoLists(subvector[left], subvector[right]);
//    }
//
//    int mid = (left + right) / 2;
//    vector<int> leftMerged = merge(subvector, left, mid);
//    vector<int> rightMerged = merge(subvector, mid + 1, right);
//
//    return mergeTwoLists(leftMerged, rightMerged);
//}
//
//vector<int> kmergesort(vector<int> &nums) {
//    vector<vector<int>> subvectors;
//    vector<int> candidate;
//
//    for (auto num: nums) {
//        if (candidate.empty()) {
//            candidate.push_back(num);
//        } else {
//            if (num < candidate.back()) {
//                subvectors.push_back(candidate);
//                candidate = {};
//            }
//            candidate.push_back(num);
//        }
//    }
//    subvectors.push_back(candidate);
//
//    vector<int> result = merge(subvectors, 0, (int) subvectors.size());
//    return {};
//}


std::vector<int32_t> merge_two_lists(std::vector<int32_t> leftVector, std::vector<int32_t> rightVector) {
    std::vector<int32_t> result = {};

    int32_t l = 0;
    int32_t r = 0;
    int32_t ls = leftVector.size();
    int32_t rs = rightVector.size();

    while ((l < ls || r < rs)) {
        if (l == ls && r == rs) {
            break;
        }
        else if (l == ls && r < rs) {
            result.push_back(rightVector[r]);
            r++;
        } else if (l < ls && r == rs) {
            result.push_back(leftVector[l]);
            l++;
        } else {
            if (leftVector[l] < rightVector[r]) {
                result.push_back(leftVector[l]);
                l++;
            } else {
                result.push_back(rightVector[l]);
                r++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> input{25, 10, 4, 0, 22, 14, 13, 17, 8, 24, 25, 16, 16, 26, 12};
    auto result = merge_two_lists({12}, {2, 11});
    return 0;
}