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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* s=new ListNode();
        s->next=head;
        ListNode *a=s,*b=s;
        for(int i=0;i<n;i++) 
           a=a->next;
        while(a->next!=NULL){
            a=a->next;
            b=b->next;
        }
        b->next=b->next->next;
        return s->next;
    }
};