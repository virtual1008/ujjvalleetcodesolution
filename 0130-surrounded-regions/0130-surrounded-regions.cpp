class Solution {
public:
    void dfs (vector<vector<char>> & board,int i,int j){
        int n=board.size();
        int m=board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X' || board[i][j]=='O') return ;
        board[i][j]='O';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='Y';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1)&& board[i][j]=='Y'){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='Y'){
                  board[i][j]='X';
                }
            }
        }
        return;
    }
};