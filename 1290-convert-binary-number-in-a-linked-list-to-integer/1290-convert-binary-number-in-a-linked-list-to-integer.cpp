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
    int getDecimalValue(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        

        int cnt=0;
        int len=0;
        if(head->next==NULL) len=1;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            cnt++;
        }
        if(fast->next==NULL) len = cnt*2+1;
        if(fast==NULL) len=cnt*2;

        int s = len-1;

        ListNode* temp=head;
        int sum=0;

        while(temp!=NULL){
            sum+=temp->val*pow(2,s);
            s--;
            temp=temp->next;
        }

        return sum;


        
    }
};