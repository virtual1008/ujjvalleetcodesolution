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
    ListNode* reverse(ListNode* node){
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* nextval=curr->next;
        while(curr!=NULL){
            nextval=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextval;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* node= new ListNode(100);
        node->next=head;
        head=node;
        left;
        right;
        right+=1;
        right-=left;
        ListNode* mid=head;
        ListNode* last=head;
        ListNode* prev=NULL;
        while(left--){
            prev=mid;
            mid=mid->next;
        }
        if(prev!=NULL){
            prev->next=NULL;
        }
        ListNode* leftNode=mid;
        prev=NULL;
        while(right--){
            prev=mid;
            mid=mid->next;
        }
        ListNode* node1=new ListNode(100);
        
        //mid->next=NULL;
        if(prev!=NULL) prev->next=NULL;
        leftNode=reverse(leftNode);
        ListNode* ans=head;
        while(ans!=NULL){
            prev=ans;
            ans=ans->next;
        }
        prev->next=leftNode;
        ans=prev;
        while(ans!=NULL){
            prev=ans;
            ans=ans->next;
        }
        prev->next=mid;
        return head->next;
    }
};