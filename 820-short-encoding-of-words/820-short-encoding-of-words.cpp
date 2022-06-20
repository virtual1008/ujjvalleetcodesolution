class Solution {
public:
    static bool compare(string s1,string s2){
        return s1.size()>s2.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
       map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        sort(words.begin(),words.end(),compare);
        int ans=0;
        for(int i=0;i<words.size();i++){
            int sz=words[i].size();
            int k=sz;
            if(m[words[i]]>0) ans+=(k+1);
            for(int j=k-1;j>=0;j--){
                string str=words[i].substr(j,k-j);
                m[str]=0;
            }
        }
        return ans;
    }
};