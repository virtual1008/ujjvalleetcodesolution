class Solution {
public:
    int rec(int i,int j,string s,string p){
        if(j<0)
       {
           if(i<0)
               return true;
           else
               return false;
       }
        if(i<0){
            while(j>=0){
                if(p[j]=='*') j--;
                else return false;
                j--;
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='.') return rec(i-1,j-1,s,p);
        else if(p[j]=='*'){
            int result=rec(i,j-2,s,p);
            if(s[i]==p[j-1] || p[j-1]=='.') result=result || rec(i-1,j,s,p);
            return result;
        }else
        return false;
    }
    bool isMatch(string s, string p) {
        return rec(s.size()-1,p.size()-1,s,p);
    }
};