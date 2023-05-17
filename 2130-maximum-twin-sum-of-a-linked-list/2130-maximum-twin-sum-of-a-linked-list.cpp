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
    int pairSum(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL ){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        ListNode* node=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* nextval=curr->next;
        while(curr!=NULL){
            nextval=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextval;
        }
        int ans=INT_MIN;
        while(prev!=NULL && head!=NULL){
            int temp=prev->val;
            temp+=head->val;
            ans=max(ans,temp);
            prev=prev->next;
            head=head->next;
        }
        
        return ans;
    }
};