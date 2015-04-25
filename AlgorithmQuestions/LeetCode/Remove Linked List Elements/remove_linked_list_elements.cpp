#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        while (head->val == val) {
            if (head->next == NULL) {
                head = NULL;
                return head;
            }
            head = head->next;
        }
        ListNode* cur = head;
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
