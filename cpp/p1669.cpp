#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *before_merge = list1;
    ListNode *to_del;
    ListNode *after_merge;
    ListNode *l2_last = list2;

    while (l2_last->next != nullptr) {
        l2_last = l2_last->next;
    }

    for (int i = 0; i < a - 1; i++) {
        before_merge = before_merge->next;
    }
    to_del = before_merge->next;
    after_merge = to_del;

    for (int i = a; i <= b; i++) {
        after_merge = after_merge->next;
    }

    while (to_del != after_merge) {
        ListNode *copy = to_del;
        to_del = to_del->next;

        delete copy;
    }

    before_merge->next = list2;
    l2_last->next = after_merge;

    return list1;
}

int main() {
    auto* list1 = new ListNode(10, new ListNode(1, new ListNode(13, new ListNode(6, new ListNode(9, new ListNode(5))))));
    auto* list2 = new ListNode(1'000'000, new ListNode(1'000'001, new ListNode(1'000'002)));
    auto* result = mergeInBetween(list1, 3, 4, list2);
    cout << result->val;

    while (list1 != nullptr) {
        ListNode* copy = list1;
        if (list1 == list2) {
            list2 = list2->next;
        }
        list1 = list1->next;
        delete copy;
    }

    return 0;
}