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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;

        ListNode* tmp = head;
        int length = 0;
        while (tmp) {
            tmp = tmp->next;
            length++;
        }
        length -= length % k;

        ListNode* pre_head = &dummy;

        for (int i = 0; i < length; i+= k) {

            ListNode* cur_end = pre_head->next;
            ListNode* cur = cur_end->next;
            for (int j = 1; j < k; j++) {
                cur_end->next = cur->next;
                cur->next = pre_head->next;
                pre_head->next = cur;
                cur = cur_end->next;
            }
            pre_head = cur_end;
        }
        return dummy.next;
    }
};