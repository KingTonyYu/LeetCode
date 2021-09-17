#include "common_header.h"

class Solution24 {
public:
  ListNode* swapPairs(ListNode* head)
  {
    ListNode dummy;
    dummy.next = head;
    ListNode* former_head = &dummy;
    while (head != nullptr)
    {
      if (head->next == nullptr)
        break;
      former_head->next = head->next;
      head->next = head->next->next;
      former_head->next->next = head;

      former_head = head;
      head = head->next;
    }
    return dummy.next;
  }
};