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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
         if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* c = dummy;
        dummy->next = head;
        ListNode* a = head;
        ListNode* b = head->next;
       

        while(b!=NULL){
            if(a->val!=b->val){
                a=a->next;
                b=b->next;
                c=c->next;
            }
            else{
                while(a->val==b->val){
                    b=b->next;
                }
                c->next=b;
                a=b;
                b=b->next;
            }
        }
        return dummy->next;
        
    }
};