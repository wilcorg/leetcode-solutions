#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <stack>

//typedef std::pair<int, int> car;

//bool compare_pos(const car &left, const car &right);

u_int32_t carFleet(int target, const std::vector<int> &position, const std::vector<int> &speed);

int main() {
//    std::vector<int> position{10, 8, 0, 5, 3};
//    std::vector<int> speed{2, 4, 1, 1, 3};
//    int target = 12;

    std::vector<int> position{0, 4, 2};
    std::vector<int> speed{2, 1, 3};
    int target = 10;

    std::cout << carFleet(target, position, speed) << std::endl;
    return 0;
}

u_int32_t carFleet(const int target, const std::vector<int> &position, const std::vector<int> &speed) {
    size_t n = position.size();
    std::vector<std::pair<int, int>> cars;
    std::stack<double> stack;

    cars.reserve(n);
    for (int i = 0; i < position.size(); i++) { cars.emplace_back(position[i], speed[i]); }
    std::sort(cars.begin(), cars.end()/*, compare_pos*/);

    for (size_t i = 0; i < n; i++) {
        double time = (target - cars[i].first) / (double) cars[i].second;

        while (!stack.empty() && time >= stack.top()) {
            stack.pop();
        }

        stack.push(time);

    }

    return (u_int32_t ) stack.size();
}

//bool compare_pos(const car &left, const car &right) {
//    return left.first < right.first;
//}

