class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi=0;
        int left=0,right=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;
            if(left==right) maxi=max(maxi,left+right);
            else if(right>left){
                left=0;
                right=0;
            }
        }
        left=0,right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') left++;
            else if(s[i]=='(') right++;
            if(left==right) maxi=max(maxi,left+right);
            else if(right>left){
                left=0;
                right=0;
            }
        }
        return maxi;
    }
};