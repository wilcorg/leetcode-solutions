#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

map<int, int> filterMap(const ListNode *copy) {
    map<int, int> count;

    while (copy != nullptr) {
        count[copy->val] += 1;
        copy = copy->next;
    }

    for (auto &left: count) {
        if (left.first == 0) {
            count[left.first] = 0;
            continue;
        }

        int req_sum = -left.first;
        map<int, int>::reverse_iterator rev;
        // index -> count
        map<int, int> indexes_to_remove;
        indexes_to_remove[left.first] = 1;

        for (rev = count.rbegin(); rev != count.rend(); ++rev) {
            if (req_sum == 0) {
                for (auto &entry: indexes_to_remove) {
                    count[entry.first] -= indexes_to_remove[entry.first];
                }
                break;
            }

            if (rev->first == left.first) {
                break;
            }

            int to_substract = req_sum / rev->first;
            int substracted = min(to_substract, (count[rev->first] - indexes_to_remove[rev->first]));
            indexes_to_remove[rev->first] += substracted;
            req_sum -= substracted * rev->first;
        }
    }
    return count;
}

//ListNode *removeZeroSumSublists(ListNode *head) {
////    const auto *copy = head;
////    // number -> count
////    auto count = filterMap(copy);
////
////    while (head != nullptr && count[head->val] == 0) {
////        head = head->next;
////    }
////
////    auto* current = head;
////    while (current != nullptr) {
////        if (current->next != nullptr) {
////            if (current->next != nullptr && count[current->next->val] == 0) {
////                while (count[current->next->val] == 0) {
////                    auto *rm = current->next;
////                    current->next = current->next->next;
////                    delete rm;
////                }
////            } else {
////                count[current->next->val] -= 1;
////                current = current->next;
////            }
////        } else {
////            current = current->next;
////        }
////    }
////
////    return head;
//}
ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode node = ListNode(0, head);
    unordered_map<int, ListNode *> mp;
    int prefix = 0;
    for (ListNode *ptr = &node; ptr; ptr = ptr->next) {
        prefix += (ptr->val);
        // if prefix sum is repeated, we have a cycle
        // so save the next point after this cycle
        mp[prefix] = ptr;
    }
    prefix = 0;
    for (ListNode *ptr = &node; ptr; ptr = ptr->next) {
        prefix += (ptr->val);
        // next will ptr to next node if any cycle with this node wasn't detected
        // or ptr to the next node after the cycle if detected
        ptr->next = mp[prefix]->next;
    }
    return node.next;
}


int main() {
    auto dupa = ListNode(1, new ListNode(2, new ListNode(-3, new ListNode(3, new ListNode(-3, new ListNode(3))))));

    removeZeroSumSublists(&dupa);

    return 0;
}