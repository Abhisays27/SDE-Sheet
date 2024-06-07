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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (!head) return NULL;
        if (left == right) return head;

        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move `prev` to the node just before the reversal starts
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = curr->next;

        // Reverse the sublist
        for (int i = 0; i < right - left; ++i) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        return dummy->next;
    }

        
    
};