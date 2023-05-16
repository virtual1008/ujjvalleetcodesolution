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
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            swap(slow->val,fast->val);
            slow=slow->next;
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        if(fast&&slow) swap(fast->val,slow->val);
        return head;
    }
};