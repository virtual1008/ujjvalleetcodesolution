class Solution {
public:
    vector<int> dp;
    int rec(int i,vector<int> & stone){
        if(i>=stone.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int total=0;
        int maxi=INT_MIN;
        for(int j=0;j<3;j++){
            if(i+j<stone.size()) total+=stone[i+j];
            maxi=max(maxi,total-rec(i+j+1,stone));
        }
        return dp[i]=maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        dp=vector<int>(stoneValue.size(),-1);
        int c=rec(0,stoneValue);
        if(c>0) return "Alice";
        else if(c==0) return "Tie";
        return "Bob";
    }
};