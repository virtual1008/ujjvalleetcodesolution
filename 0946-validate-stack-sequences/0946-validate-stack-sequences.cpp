class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()!=popped.size()) return false;
        stack<int> st;
        int i=0, j=0;
        while(i<pushed.size() && j<popped.size()){
            if(pushed[i]==popped[j]){
                i++;
                j++;
            }
            else if(!st.empty()){
                int k=st.top();
                if(k==popped[j]){
                    st.pop();
                    j++;
                }else{
                    st.push(pushed[i]);
                    i++;
                }
            }else{
                st.push(pushed[i]);
                i++;
            }
        }
        if(i<pushed.size()) return false;
        if(j<popped.size()){
            while(!st.empty() && j<popped.size()){
                int k=st.top();
                if(k==popped[j]) {
                    st.pop();
                    j++;
                }
                else return false;
            }
        }
        return st.empty() && j==popped.size();
    }
};