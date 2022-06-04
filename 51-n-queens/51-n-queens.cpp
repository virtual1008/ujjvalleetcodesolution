class Solution {
public:
    bool issafe(int r,int c,int n,vector<string> & board){
        int a=r;
        int b=c;
        while(a>=0 && b>=0){
            if(board[a][b]=='Q') return false;
            a--;
            b--;
        }
        a=r;
        b=c;
        while(b>=0){
            if(board[a][b]=='Q') return false;
            b--;
        }
        b=c;
        while(a<n && b>=0){
            if(board[a][b]=='Q') return false;
            a++;
            b--;
        }
        return true;
    }
    void fun(int col,int n,vector<string>& board,vector<vector<string>>& ans){
        if(col>=n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,n,board)){
                board[row][col]='Q';
                fun(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
         string str;
        for(int i=0;i<n;i++) str+='.';
        for(int i=0;i<n;i++) board.push_back(str);
        fun(0,n,board,ans);
        return ans;
    }
};