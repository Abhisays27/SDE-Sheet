/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *flyodCycle(ListNode *head){
        if(head==NULL){
            return NULL;
        }
         ListNode *slow=head;
         ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return slow;
            }
        }
        return NULL;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
                if(head==NULL){
            return NULL;
        }

        ListNode* intersection = flyodCycle(head);
         if (intersection == NULL) {
        return NULL; // No cycle detected
    }

        ListNode* slow=head;
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
        
        
    }
};