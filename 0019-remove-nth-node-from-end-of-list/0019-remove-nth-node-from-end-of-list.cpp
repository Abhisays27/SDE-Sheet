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
    ListNode* reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;
        while (curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Reverse the linked list
        ListNode* reversedHead = reverseLL(head);

        // Handle the case when n equals the length of the linked list
        if (n == 1) {
            ListNode* temp = reversedHead;
            reversedHead = reversedHead->next;
            delete temp;
            return reverseLL(reversedHead);
        }

        // Find the node before the one to be removed
        ListNode* curr = reversedHead;
        ListNode* prev = NULL;
        int cnt = n - 1;
        while (cnt > 0 && curr != NULL) {
            prev = curr;
            curr = curr->next;
            cnt--;
        }

        // Remove the nth node from the end
        if (prev != NULL) {
            prev->next = curr->next;
            delete curr;
        }

        // Reverse the modified linked list and return the head
        return reverseLL(reversedHead);
    }
};
