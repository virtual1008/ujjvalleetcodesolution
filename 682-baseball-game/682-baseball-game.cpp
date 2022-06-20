class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C") st.pop();
            else if(ops[i]=="D"){
                if(st.size()==0) continue;
                int k=st.top();
                k*=2;
                st.push(k);
            }
            else if(ops[i]=="+"){
                if(st.size()<2) continue;
                int a=st.top();
                st.pop();
                int b=st.top();
                st.push(a);
                st.push((a+b));
            }else{
                int k=stoi(ops[i]);
                st.push(k);
            }
        }
        int ans=0;
        while(!st.empty()){
            int a=st.top();
            ans+=a;
            st.pop();
        }
        return ans;
    }
};