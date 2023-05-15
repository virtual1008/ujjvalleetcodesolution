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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode *a=head,*b=head,*c=head;
        int n=k;
        n--;
        while(k--){
            b=b->next;
            
        }
        while(n--) c=c->next;
        while(b!=NULL){
            a=a->next;
            b=b->next;
        }
        int temp=c->val;
        c->val=a->val;
        a->val=temp;
        return head;
        
    }
};