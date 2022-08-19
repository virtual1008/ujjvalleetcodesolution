class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> m,n;
        for(auto it:nums) m[it]++;
        for(auto it:nums){
            if(m[it]==0) continue;
            if(n[it]>0){
                n[it]--;
                m[it]--;
                n[it+1]++;
            }
            else if(m[it]>0 && m[it+1]>0 && m[it+2]>0){
                m[it]--;
                m[it+1]--;
                m[it+2]--;
                n[it+3]++;
            }else return false;
        }
        return true;
        
        
    }
};