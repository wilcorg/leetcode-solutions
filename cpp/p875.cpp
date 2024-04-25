#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

int minEatingSpeed(const std::vector<int> &piles, int h);

bool check(const std::vector<int> &piles, int k, int h);

int main() {
    std::vector<int> piles{312884470};
    int h = 968709470;
    std::cout << minEatingSpeed(piles, h) << std::endl;
    return 0;
}

int minEatingSpeed(const std::vector<int> &piles, int h) {
    if (piles.size() > h) return -1;

    int max_h = *std::max_element(piles.begin(), piles.end());
    int min_h = 1;

    while (min_h <= max_h) {
        int mid = (min_h + max_h) / 2;

        if (check(piles, mid, h)) {
            max_h = mid - 1;
        } else {
            min_h = mid + 1;
        }
    }

    return min_h;
}

bool check(const std::vector<int> &piles, int k, int h) {

    for (int i: piles) {
        int req_div = std::ceil(i / (double) k);

        if (h >= req_div) {
            h -= req_div;
        } else {
            return false;
        }
    }
    return true;
}