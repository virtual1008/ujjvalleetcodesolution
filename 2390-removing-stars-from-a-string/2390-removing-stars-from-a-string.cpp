class Solution {
public:
    string removeStars(string s) {
       stack<char> q;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') q.push(s[i]);
            else q.pop();
        }
        string ans;
        while(!q.empty()){
            char c=q.top();
            ans+=c;
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};