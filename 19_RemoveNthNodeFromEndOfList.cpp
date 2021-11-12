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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode dummy;
      dummy.next = head;
      
      ListNode* left = &dummy;
      ListNode* right = head->next;
      
      for (int i = 1; i < n; i++) {
        right = right->next;
      }
      
      while (right != nullptr) {
        left = left->next;
        right = right->next;
      }
      
      //delete left next
      ListNode* tmp = left->next;
      left->next = left->next->next;
      delete tmp;
      return dummy.next;
      
        
    }
};