class Solution {
public:
    
    map<string,int> dp;
    bool rec(string s1,string s2){   
         if(s1.size()==1 || s1.size()==0) return s1==s2;
         if(s2==s1) return true;
         string temp=s1;
         temp+='*';
         temp+=s2;
         if(dp.find(temp)!=dp.end()) return dp[temp];
         int n=s1.size();
         for(int i=1;i<n;i++){
            // if(rec(s1.substr(0,i),s2.substr(0,i)))
            bool c1=rec(s1.substr(0,i),s2.substr(0,i)) && rec(s1.substr(i,n-i),s2.substr(i,n-i));
            bool c2=rec(s1.substr(0,i),s2.substr(n-i,i)) && rec(s1.substr(i,n-i),s2.substr(0,n-i));
            if(c1 || c2) return true;
         }
         return dp[temp]=false;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        if(s1.size()!=s2.size()) return false;
        return rec(s1,s2);
    }
};