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
    ListNode* findKthNode( ListNode* temp, int k){
        
        while(temp!=NULL && k>1){
             k--;
            temp=temp->next;
          
        }
        return temp;
    } 

     ListNode* reverseLL( ListNode* head){
         ListNode* prev=NULL;
         ListNode* fwd=NULL;
         ListNode* curr=head;

         while(curr!=NULL){
            fwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=fwd;
       }
       return prev;
     }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || head->next==NULL || k==1) return head;

        
          ListNode* temp = head;
          ListNode* prevNode=NULL;

          while(temp!=NULL){
            
             ListNode* kthNode = findKthNode(temp,k);
             if(kthNode==NULL) {

                if(prevNode!=NULL){
                    prevNode->next=temp;
                   
                }
                 break;

                
             }
             ListNode* nextNode=kthNode->next;
             kthNode->next=NULL;
             reverseLL(temp);
             if(temp==head){
                head=kthNode;
             }
             else{
                prevNode->next=kthNode;
             }
            
           prevNode=temp;
            temp=nextNode;
            

          }
          return head;
    }
};