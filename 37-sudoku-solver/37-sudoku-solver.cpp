class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool isvalid(int i,int j,char c,vector<vector<char>> & board){
        for(int k=0;k<9;k++){
            if(board[i][k]==c || board[k][j]==c) return false;
            
        }
        int a=(i)/3;
        int b=(j)/3;
        for(int x=3*a;x<3*a+3;x++){
            for(int y=3*b;y<3*b+3;y++){
                if(board[x][y]==c) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> & board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)==true) return true;
                            else board[i][j]='.';
                        }
                    }
                   return false;
                }
            }
        }
        return true;
    }
};