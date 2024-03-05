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
          // Base case
        if (head == NULL) {
            return NULL;
        }
        
        // Check if there are at least k nodes remaining
        ListNode* curr = head;
        int count = 0;
        while (curr != NULL && count < k) {
            curr = curr->next;
            count++;
        }
        
        // If fewer than k nodes remaining, no need to reverse
        if (count < k) {
            return head;
        }
        
        // Reverse the first k nodes
        ListNode* prev = NULL;
        ListNode* next = NULL;
        curr = head;
        count = 0;
        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        // Recursively reverse the remaining list
        if (curr != NULL) {
            head->next = reverseKGroup(curr, k);
        }
        
        // Return the new head of the reversed group
        return prev;
    }
};