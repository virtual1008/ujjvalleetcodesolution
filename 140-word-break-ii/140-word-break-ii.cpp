class Solution {
public:
    vector<string> ans;
    void rec(int i,string s,vector<string> &v,string str){
        if(i>=s.size()){
            ans.push_back(str);
            return;
        }
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(find(v.begin(),v.end(),temp)!=v.end())
                 rec(j+1,s,v,str.size()>0?str+" "+temp:temp);
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& v) {
        string str="";
        rec(0,s,v,str);
        return ans;
    }
};