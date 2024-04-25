#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    deque<ListNode*> dq;
    ListNode* ro = head;
    ListNode** rw = &head;

    while (ro != nullptr) {
        dq.push_back(ro);
        ro = ro->next;
    }

    bool is_head = true;
    head = nullptr;
    ListNode* cur = head;

    while (!dq.empty()) {
        if (is_head) {
            cur = dq.front();
            dq.pop_front();
            is_head = false;
        } else {
            cur = dq.back();
            dq.pop_back();
            is_head = true;
        }
        cur = cur->next;
    }
}

int main() {
    auto* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    reorderList(head);

    while (head != nullptr) {
        ListNode* copy = head;
        head = head->next;
        delete copy;
    }
    return 0;
}