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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next;
            slow=slow->next;
            fast=fast->next;
        }
        //cout<<slow->val;
        ListNode* prev=NULL,*curr=slow->next,*node=curr->next;
        //cout<<curr->val<<" "<<node->val;
        while(node!=NULL){
            curr->next=prev;
            prev=curr;
            curr=node;
            node=node->next;
        }
        curr->next=prev;
        while(curr!=NULL){
            if(curr->val==head->val){
                curr=curr->next;
                head=head->next;
            }else{
                return false;
            }
        }
        return true;
    }
};