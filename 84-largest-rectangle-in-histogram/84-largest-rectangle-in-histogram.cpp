class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int> pre(n, -1), suf(n, n);
        stack<int> lft, rgt;
        
        for(int i=0, j=n-1; i<n; j--, i++){
            while(!lft.empty() and v[lft.top()] >= v[i]) lft.pop();
            if(!lft.empty()) pre[i] = lft.top();
            lft.push(i);
            
            while(!rgt.empty() and v[rgt.top()] >= v[j]) rgt.pop();
            if(!rgt.empty()) suf[j] = rgt.top();
            rgt.push(j);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, (suf[i] - pre[i] - 1)*v[i]);
        }
        return ans;
    }
};