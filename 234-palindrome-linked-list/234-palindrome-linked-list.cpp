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
        ListNode* slow = head;
 ListNode* fast = head;
 
 while(fast->next != NULL && fast->next->next != NULL){
     slow = slow->next;
     fast = fast->next->next;
 }
 
 slow = slow->next;
 
 ListNode* pre = NULL;
 
 while(slow != NULL){
     ListNode* next =  slow->next;
     slow->next = pre;
     pre = slow;
     
     slow = next;            
 }
 
 while(pre != NULL){
     if(head->val != pre->val) return 0;
     
     head = head->next;
     pre = pre->next;            
 }
 
 return 1;
    }
};