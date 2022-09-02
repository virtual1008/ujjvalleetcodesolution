class Solution {
public:
    void f(int i,vector<int>&nums,map<int,int>&m,int n)
    {
     if(i>=nums.size())
     {
         return;
     }
        
        f(i+1,nums,m,n);
         m[n|nums[i]]++;
        f(i+1,nums,m,n|nums[i]);
        
        
        
        
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        
        map<int,int>m;
         f(0,nums,m,0);
        int maxi=0;
        int ans=0;
        for(auto it:m)
        {
            if(it.second>=maxi)
            {
                maxi=it.second;
                
            }
            
        }
        return maxi;
        
    }
};