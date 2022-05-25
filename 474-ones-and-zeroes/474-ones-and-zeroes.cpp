class Solution {
public:
    int dp[601][101][101]; 
    pair<int, int> countOneAndZero(string s)
    {
        int one = 0, zero = 0;
        
        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] == '1') 
                one++;
            else            
                zero++;
        }
        
        return {one, zero};
    }
    
    int solve(int i, int one, int zero, int& maxZero, int& maxOne, 
             vector<string>& arr)
    {
        if(i>=arr.size()) return 0;
        auto it=countOneAndZero(arr[i]);
        if(dp[i][one][zero]!=-1) return dp[i][one][zero];
        int ans1,ans2,ans;
        if(one+it.first<=maxOne && zero+it.second<=maxZero){
            ans1=1+solve(i+1,one+it.first,zero+it.second,maxZero,maxOne,arr);
             ans2=solve(i+1,one,zero,maxZero,maxOne,arr);
            ans=max(ans1,ans2);
        }else{
            ans=solve(i+1,one,zero,maxZero,maxOne,arr);
        }
        return dp[i][one][zero]=ans;
        
        
        
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int maxZero = m; 
        int maxOne = n; 
        memset(dp, -1, sizeof(dp)); 
        return solve(0, 0, 0, maxZero, maxOne, arr);
    }
};