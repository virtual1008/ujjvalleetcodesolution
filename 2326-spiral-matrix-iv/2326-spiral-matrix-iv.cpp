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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int startrow=0,startcol=0,endrow=m-1,endcol=n-1;
        int cnt=1;
        while(head!=NULL){
            for(int i=startcol;head!=NULL&&i<=endcol;i++){
                ans[startrow][i]=head->val;
                head=head->next;
                cnt++;
            }
            startrow++;
            for(int i=startrow;head!=NULL&&i<=endrow;i++){
                ans[i][endcol]=head->val;
                head=head->next;
                cnt++;
            }
            endcol--;
            for(int i=endcol;head!=NULL&&i>=startcol;i--){
                ans[endrow][i]=head->val;
                head=head->next;
                cnt++;
            }
            endrow--;
            for(int i=endrow;head!=NULL&&i>=startrow;i--){
                ans[i][startcol]=head->val;
                head=head->next;
                cnt++;
            }
            startcol++;
            
        }
        return ans;
        
    }
};