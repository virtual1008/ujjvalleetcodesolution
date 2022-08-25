class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans(m,0);
        int area=0;
        int k=0;
        while(k<n){
            for(int i=0;i<m;i++){
                if(matrix[k][i]=='0') ans[i]=0;
                ans[i]+=matrix[k][i]-'0';
            }
            vector<int> left(m,m-1),right(m,0);
            stack<int> st1,st2;
           for(int i=0,j=m-1;j>=0,i<m;j--,i++){
               while(!st1.empty() && ans[st1.top()]>ans[i]){
                   left[st1.top()]=i-1;
                   st1.pop();
               }
               st1.push(i);
               while(!st2.empty() && ans[st2.top()]>ans[j]){
                   right[st2.top()]=j+1;
                   st2.pop();
               }
               st2.push(j);
           }
            for(int i=0;i<m;i++){
                area=max(area,(left[i]-right[i]+1)*ans[i]);
            }
            k++;
            
            
        }
        return area;
    }
};