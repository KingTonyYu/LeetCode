/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int plus_one = 0;
        ListNode dummy;
        ListNode* cur = &dummy;
        while (l1 && l2) {
            int sum = l1->val + l2->val + plus_one;
            int cur_digit = sum % 10;
            plus_one = sum / 10;

            cur->next = new ListNode(cur_digit);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1)
            swap(l1, l2);
        while (l1) {
            int sum = l1->val + plus_one;
            int cur_digit = sum % 10;
            plus_one = sum / 10;

            cur->next = new ListNode(cur_digit);
            cur = cur->next;
            l1 = l1->next;
        }

        cur->next = plus_one ? new ListNode(1) : nullptr;
        return dummy.next;
    }
};