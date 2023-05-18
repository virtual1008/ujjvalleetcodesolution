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
    int countval(ListNode* l1){
        int cnt=0;
        while(l1!=NULL){
            cnt++;
            l1=l1->next;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1=countval(l1);
        int cnt2=countval(l2);
        if(cnt2>cnt1) swap(l1,l2);
        ListNode* prev=NULL;
        ListNode* curr=l1;
        ListNode* nextnode=curr->next;
        while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        l1=prev;
        prev=NULL;
        curr=l2;
        nextnode=curr->next;
         while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        l2=prev;
        int carry=0;
        ListNode* ans=l1;
        while(l1!=NULL && l2!=NULL){
            int temp=l1->val+l2->val+carry;
            carry=temp/10;
            temp%=10;
            l1->val=temp;
            prev=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int temp=l1->val+carry;
            carry=temp/10;
            temp%=10;
            prev=l1;
            l1->val=temp;
            l1=l1->next;
        }
        while(l2!=NULL){
            int temp=l2->val+carry;
            carry=temp/10;
            temp%=10;
            prev->next=new ListNode(temp);
            l1=prev;
            l1=l1->next;
            l2=l2->next;
        }
        if(carry){
            prev->next=new ListNode(carry);
        }
        curr=ans;
        prev=NULL;
        while(curr!=NULL){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
};









