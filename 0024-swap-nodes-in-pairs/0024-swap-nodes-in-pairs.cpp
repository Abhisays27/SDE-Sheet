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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL) return head;
         ListNode* dummy = new  ListNode(0);
         dummy->next=head;
          ListNode* prev =dummy;
           ListNode* curr=head;

           while(curr!=NULL && curr->next!=NULL){
            ListNode* first = curr;
             ListNode* second= curr->next;

                // Swapping the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move pointers
            prev = first;
            curr = first->next;
           }
           return dummy->next;

        
    }
};