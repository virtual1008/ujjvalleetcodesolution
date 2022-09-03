class Solution {
public:
    int count(int i,int j,vector<vector<int>>& m){
        int cnt=0;
        int n=m.size();
        int w=m[0].size();
        if(j>0) if(m[i][j-1]==1 || m[i][j-1]==-2) cnt++;
        
        if(j>0 && i>0) if(m[i-1][j-1]==1 || m[i-1][j-1]==-2) cnt++;
        
        if(i>0) if(m[i-1][j]==1 || m[i-1][j]==-2) cnt++;
        
        if(j<w-1 && i>0) if(m[i-1][j+1]==1 || m[i-1][j+1]==-2) cnt++;
        
        if(j<w-1) if(m[i][j+1]==1 || m[i][j+1]==-2) cnt++;
        
        if(j<w-1 && i<n-1) if(m[i+1][j+1]==1 || m[i+1][j+1]==-2) cnt++;
        
        if(i<n-1) if(m[i+1][j]==1 || m[i+1][j]==-2) cnt++;
        
        if(j>0 && i<n-1) if(m[i+1][j-1]==1 || m[i+1][j-1]==-2) cnt++;
        
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt1=count(i,j,board);
                if(board[i][j]==1){
                    if(cnt1<2 || cnt1>3) board[i][j]=-2;
                }
                else{
                    if(cnt1==3) board[i][j]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2){
                    board[i][j]=1;
                }
                else if(board[i][j]==-2){
                    board[i][j]=0;
                }
            }
        }
    }
};