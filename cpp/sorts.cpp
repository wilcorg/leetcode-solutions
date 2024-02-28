#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& a);

void mergeSort(std::vector<int>& a, size_t p, size_t r);

void merge(std::vector<int>& a, size_t p, size_t q, size_t r);

void bubbleSort(std::vector<int>& a);

int main() {
    const std::vector<int> a = {2, 5, 4, 8, 7, 6, 1, 3};
    std::vector<int> sorted(a);

//    insertionSort(sorted);
    mergeSort(sorted, 0, a.size() - 1);
//    bubbleSort(sorted);

    for (int i: sorted) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

void insertionSort(std::vector<int>& a) {
    size_t n = a.size();
    for (int i = 1; i < n; i++) {
        // element to insert into left hand
        int key = a[i];
        // left hand max bound
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            // shift array elements to the right
            a[j + 1] = a[j];
            j -= 1;
        }
        // replace first from the left shifted element
        a[j + 1] = key;
    }
}

void mergeSort(std::vector<int>& a, size_t p, size_t r) { // NOLINT(*-no-recursion)
    if (p >= r) {
        return;
    }

    size_t q = (p + r) / 2;  // midpoint of a[p:r]
    mergeSort(a, p, q);  // recursive sort of left half
    mergeSort(a, q + 1, r);  // recursive sort of right half
    merge(a, p, q, r);
}

void merge(std::vector<int>& a, size_t p, size_t q, size_t r) {
    size_t left_len = q - p + 1;  // length of a[p:q]
    size_t right_len = r - q;  // length of p[q+1:r]
    std::vector<int> left_arr, right_arr;

    // copy a[p:q] into left_arr[0:left_len-1]
    for (int i = 0; i < left_len; i++) {
        left_arr.push_back(a[p + i]);
    }

    // copy a[q+1:r] into right_arr[0:right_len-1]
    for (int j = 0; j < right_len; j++) {
        right_arr.push_back(a[q + 1 + j]);
    }
    size_t i = 0;  // indexes smallest remaining element in left_arr
    size_t j = 0;  // indexes smallest remaining element in right_arr
    size_t k = p;  // k indexes the location in A to fill

    // as long as each of the left_arr and right_arr contains unmerged element
    // copy *the smallest unmerged element* back into a[p:r]
    while (i < left_len && j < right_len) {
        if (left_arr[i] <= right_arr[j]) {
            a[k] = left_arr[i];
            i++;
        } else {
            a[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // after either left or right arr had gone entirely
    // copy the remainder of the other to the end of a[p:r]
    while (i < left_len) {
        a[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_len) {
        a[k] = right_arr[j];
        j++;
        k++;
    }
}

void bubbleSort(std::vector<int>& a) {
    size_t n = a.size();
    for (size_t i = 0; i < n; i++) {
        for (size_t j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j-1]);
            }
        }
    }
}
