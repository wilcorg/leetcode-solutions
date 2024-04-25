#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//ListNode* reverseList(ListNode* head) {
//    stack<int> mem;
//    ListNode* cur = head;
//
//    while (cur != nullptr) {
//        mem.push(cur->val);
//        cur = cur->next;
//    }
//
//    cur = head;
//    while (cur != nullptr) {
//        cur->val = mem.top();
//        mem.pop();
//        cur = cur->next;
//    }
//
//    return head;
//}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next = nullptr;

    while (cur != nullptr) {
        next = cur->next;  // backup next coz cur->next won't point to next anymore
        cur->next = prev;  // prev is now next of cur

        // since our next pointers are broken now we move forward the list using saved pointers
        prev = cur;
        cur = next;
    }

    return prev;
}

int main() {
    auto* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    reverseList(head);

    while (head != nullptr) {
        ListNode* copy = head;
        head = head->next;
        delete copy;
    }
    return 0;
}