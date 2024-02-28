struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            auto* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }


int main() {
    auto *l1a = new ListNode(3);
    auto *l1b = new ListNode(4, l1a);
    auto *l1 = new ListNode(2, l1b);

    auto *l2a = new ListNode(4);
    auto *l2b = new ListNode(6, l2a);
    auto *l2 = new ListNode(5, l2b);

    auto *result = addTwoNumbers(l1, l2);

    delete l1a;
    delete l1b;
    delete l1;
    delete l2a;
    delete l2b;
    delete l2;
    result = nullptr;
    delete result;
    return 0;
}
