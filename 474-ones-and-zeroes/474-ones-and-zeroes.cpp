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
        if(i >= arr.size()) 
            return 0;
        if(one > maxOne || zero > maxZero)
            return 0;
        if(dp[i][one][zero] != -1)
        {
            return dp[i][one][zero];
        }
        
        pair<int, int> p = countOneAndZero(arr[i]);
        int ans1 = 0, ans2 = 0, ansWithout = 0;
        if(one + p.first <= maxOne && zero + p.second <= maxZero)
        {
            ans1 = 1 + solve(i + 1, one + p.first, zero + p.second, 
                           maxZero, maxOne, arr);
            ans2 = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        else 
        {
            ansWithout = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        return dp[i][one][zero] = max({ans1, ans2, ansWithout});
        
        
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int maxZero = m; 
        int maxOne = n; 
        memset(dp, -1, sizeof(dp)); 
        return solve(0, 0, 0, maxZero, maxOne, arr);
    }
};