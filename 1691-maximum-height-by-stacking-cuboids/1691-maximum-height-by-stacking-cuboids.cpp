class Solution {
public:
    int ans = 0 ;
    map<string,int> dp ;
    
    int solve(int pos , vector<vector<int>> &cuboids , int baseL , int baseB , int baseH){
        if(pos >= cuboids.size()) return 0 ;
        
        string code = to_string(pos) + " " + to_string(baseL) + " " + to_string(baseB) + " " + to_string(baseH) ;
        if(dp.find(code) != end(dp) ) return dp[code] ;
        
        int topL = cuboids[pos][0] , topB = cuboids[pos][1] , topH = cuboids[pos][2] ;
        int op1 = 0 , op2 = 0 ;
        if(topL <= baseL and topB <= baseB and topH <= baseH) op1 = topH + solve(pos + 1 , cuboids, topL , topB , topH) ;
        op2 = solve(pos + 1 , cuboids , baseL , baseB ,baseH ) ;
        
        return dp[code] = max({op1,op2}) ;
        
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto &x : cuboids) sort(begin(x),end(x)) ;
		
        sort(begin(cuboids),end(cuboids),greater<vector<int>>()) ;
        
        return solve(0,cuboids,INT_MAX,INT_MAX,INT_MAX) ;
        
    }
};