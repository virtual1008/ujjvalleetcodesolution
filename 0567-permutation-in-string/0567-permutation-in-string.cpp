class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        
        if(s1==s2) return true;
        
        vector<int> v(26,0),z(26,0);
        
        for(int i=0;i<s1.size();i++) {
            
            v[s1[i]-'a']++; 
        
            z[s2[i]-'a']++;
        
        }
        
        if(v==z) return true;
        
        for(int i=s1.size();i<s2.size();i++){
            
            z[s2[i]-'a']++;
            
            z[s2[i-s1.size()]-'a']--;
            
            if(v==z) {return true;break;}
            
        }
        
        return false;
        
    }
};