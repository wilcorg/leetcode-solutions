#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


//bool isPalindrome(ListNode* head) {
//    ListNode* cur = head;
//    int count = 0;
//
//    while (cur != nullptr) {
//        count++;
//        cur = cur->next;
//    }
//    if (count == 1) {
//        return true;
//    }
//
//    int mid = (count + 1) / 2;
//    stack<int> st;
//    cur = head;
//    for (int i = count; i > mid; i--) {
//        st.push(cur->val);
//        cur = cur->next;
//    }
//
//    if (count % 2 == 1) {
//        cur = cur->next;
//    }
//
//    for (int i = count - mid; i > 0; i--) {
//        if (!st.empty() && cur->val == st.top()) {
//            st.pop();
//            cur = cur->next;
//        } else {
//            return false;
//        }
//
//    }
//
//    return st.empty();
//}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* next;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = reverse(slow->next);
    ListNode* backup = second;
    ListNode* cur = head;
    while (second != nullptr) {
        if (cur->val != second->val) {
            reverse(backup);
            return false;
        }
        cur = cur->next;
        second = second->next;
    }

    reverse(backup);
    return true;
}

int main() {
    auto* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    cout << isPalindrome(head);

    while (head != nullptr) {
        ListNode* copy = head;
        head = head->next;
        delete copy;
    }

    return 0;
}