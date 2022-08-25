class Solution {
public:
 
    int largestRectangleArea(vector<int>& v) {
        //vector<int> ans=nsn(v);
        stack<int> st,st1;
        vector<int> ans(v.size(),v.size()-1);
        vector<int> ans1(v.size(),0);
        for(int i=0,j=v.size()-1;i<v.size(),j>=0;i++,j--){
            while(!st.empty() && v[i]<v[st.top()]){
                ans[st.top()]=i-1;
                st.pop();
            }
            st.push(i);
            while(!st1.empty() && v[j]<v[st1.top()]){
                ans1[st1.top()]=j+1;
                st1.pop();
            }
            st1.push(j);
        }
        //for(auto it:ans) cout<<it<<" ";
        //cout<<"\n";
        //vector<int> ans1=psn(v);
       // for(auto it:ans1) cout<<it<<" ";
        int val=0;
        for(int i=0;i<v.size();i++){
            val=max(val,(ans[i]-ans1[i]+1)*v[i]);
        }
        return val;
    }
};