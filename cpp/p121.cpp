#include <bits/stdc++.h>

using namespace std;

//int maxProfit(const vector<int> &prices) {
//    const int n = (int) prices.size();
//    int stonks = 0;
//    int start;
//
//    for (int i = 0; i < n - 1; i++) {
//        start = prices[i];
//
//        for (int j = i; j < n; j++) {
//            stonks = max(stonks, prices[j] - start);
//        }
//    }
//
//    return stonks;
//}

//int maxProfit(const vector<int> &prices) {
//    int low = numeric_limits<int>::max();
//    int high = 0;
//    int stonks = 0;
//
//    for (auto price : prices) {
//        if (price < low) {
//            low = price;
//            high = 0;
//        } else {
//            if (price - low > stonks) {
//                high = price;
//                stonks = high - low;
//            }
//        }
//    }
//
//    return stonks;
//}

int maxProfit(const vector<int> &prices) {
    int low = prices[0];
    int stonks = 0;

    for (auto price: prices) {
        if (price < low) {
            low = price;
        } else if (price - low > stonks) {
            stonks = price - low;
        }
    }

    return stonks;
}

int main() {
    const vector<int> prices{2, 4, 1};
//    const vector<int> prices{7,6,4,3,1};
    cout << maxProfit(prices);
    return 0;
}