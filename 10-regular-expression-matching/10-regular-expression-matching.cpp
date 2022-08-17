class Solution {
public:
    int findans(int i,int j,string s,string p){
       if(j<0)
       {
           if(i<0)
               return true;
           else
               return false;
       }
        if(i<0)
        {
            while(j>=0)
            {
                if(p[j]=='*')
                {
                    j--;
                }
                else
                    return false;
                j--;
            }
            return true;
        }
       if((s[i]==p[j] || p[j]=='.'))
           return  findans(i-1,j-1,s,p);
        else if(p[j]=='*')
        {
            int res=findans(i,j-2,s,p); // if not considering the occurence of the element
            
            if(s[i]==p[j-1]  || p[j-1]=='.')
                res=res||  findans(i-1,j,s,p);
            
          return   res;
            
        }
        else
        return  false;
    }
    bool isMatch(string s, string p) {
      //  reverse(s.begin(),s.end());
        //reverse(p.begin(),p.end());
        return findans(s.size()-1,p.size()-1,s,p);
    }
};