class Solution {
public:
    bool issafe(int row,int col,vector<string> board,int n){
        int a=row;
        int b=col;
        while(a>=0 && b>=0){
            if(board[a][b]=='Q') return false;
            a--;
            b--;
        }
        a=row;
        b=col;
        while(b>=0){
            if(board[a][b]=='Q') return false;
            //a--;
            b--;
        }
        b=col;
        while(b>=0 && a<n){
           if(board[a][b]=='Q') return false;
            a++;
            b--;
        }
        return true;
        
    }
    void backtracking(vector<string>& board,int &cnt,int col,int n){
        if(col>=n){
            cnt++;
            return;
        }
        for(int row=0;row<n;row++){
           if(issafe(row,col,board,n)){
               board[row][col]='Q';
               backtracking(board,cnt,col+1,n);
               board[row][col]='.';
           }
        }
    }
    int totalNQueens(int n) {
        int cnt(0);
        vector<string> board;
        string str;
        for(int i=0;i<n;i++) str+='.';
        for(int i=0;i<n;i++) board.push_back(str);
        backtracking(board,cnt,0,n);
        return cnt;
    }
};