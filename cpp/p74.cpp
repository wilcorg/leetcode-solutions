#include <vector>
#include <iostream>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0;
    int right = n * m - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int a = mid / m;
        int b = mid % m;
        if (matrix[a][b] == target) {
            return true;
        } else if (matrix[a][b] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//    std::vector<std::vector<int>> matrix = {{1}, {3}};
    int target = 3;

    std::cout << searchMatrix(matrix, target);
    return 0;
}