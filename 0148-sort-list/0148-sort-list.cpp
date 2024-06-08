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
private:
    ListNode* findMiddle(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        

         if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        if(l1->val>l2->val){
            swap(l1,l2);
        }

        ListNode* res = l1;

        while(l1!=NULL && l2!=NULL){
            ListNode* temp = NULL;

            while(l1!=NULL && l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return res;

    }
     
public:
   ListNode* sortList(ListNode* head) {

    if(head==NULL || head->next==NULL) return head;
    
    ListNode* middle = findMiddle(head);

    ListNode* lefthead = head;
    ListNode* righthead = middle->next;

    middle->next=NULL;

    lefthead = sortList(lefthead);
   righthead = sortList(righthead);

   return  merge(lefthead,righthead);




        
      
        
    }
};