class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> & board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.') return;
        board[i][j]='.';
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        dfs(i-1,j,board);
        dfs(i,j-1,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,board);
                    ans++;
                }
            }
        }
        return ans;
    }
};