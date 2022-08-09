class Solution {
public:
    vector<vector<string>> ans;
    bool pallindrom(string str){
        int l=0,r=str.size()-1;
        while(l<=r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void fun(vector<string> &curr,string s,string str,int i){
        if(i==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<s.size();j++){
            str+=s[j];
            if(pallindrom(str)){
                curr.push_back(str);
                string temp="";
                fun(curr,s,temp,j+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        string str="";
        fun(curr,s,str,0);
        return ans;
    }
};