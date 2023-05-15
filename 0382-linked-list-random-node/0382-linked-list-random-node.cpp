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
    vector<int> temp;
    int n;
public:
    Solution(ListNode* head) {
        temp.clear();
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        n=temp.size();
    }
    
    int getRandom() {
        int index=rand()%n;
        return temp[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */