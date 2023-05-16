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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* cnt=head;
        while(cnt!=NULL){
            ListNode* fast=head->next;
            ListNode* slow=head;
            while(fast!=NULL){
                if(fast->val<slow->val) swap(fast->val,slow->val);
                slow=fast;
                fast=fast->next;
            }
            cnt=cnt->next;
        }
        return head;
    }
};