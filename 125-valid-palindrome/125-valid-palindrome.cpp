class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>v;
        for(auto i:s)
        {
            if(i>='a' && i<='z')
                v.push_back(i);
            else if(i>='A' && i<='Z')
            {
                char c='a';
                c+=(i-65);
                v.push_back(c); 
                
            }else if (i>='0' && i<='9')
                v.push_back(i);
        }
        int i=0;
        int j=v.size()-1; 
        while(i<j)
        {
            if(v[i]!=v[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};