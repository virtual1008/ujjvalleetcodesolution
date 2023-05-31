class Solution {
public:
   // map<string,int> dp1;
    int mod=1e9+7;
    pair<int,int>dp[101][101];
    pair<int,int> rec(int i,int j,vector<string> &board){
        if(i<0 || j<0 || board[i][j]=='X' ) return {-1e3,0};
        if(board[i][j]=='E') return {0,1};
        pair<int,int>p={-1,-1};
        if(dp[i][j]!=p){
            return dp[i][j];
        }
        pair<int,int> left,up,leftup;
        left=rec(i,j-1,board);
        up=rec(i-1,j,board);
        leftup=rec(i-1,j-1,board);
        long long k=max({left.first,up.first,leftup.first});
        long long path=0;
        if(k==left.first) path+=(left.second)%mod;
        if(k==up.first) path+=(up.second)%mod;
        if(k==leftup.first) path+=(leftup.second)%mod;
        long long t=(board[i][j]=='S'?0:(board[i][j]-'0'));
        return dp[i][j]={t+k,path%mod};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
       pair<int,int>p1={-1,-1};
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                dp[i][j]=p1;
            }
        }
        vector<int> ans;
        auto c=rec(board.size()-1,board[0].size()-1,board); 
        if(c.first<0) return {0,0};
        return {c.first,c.second};
    }
};