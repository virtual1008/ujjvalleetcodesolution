class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        queue<pair<int,int>> q;
        int x=click[0];
        int y=click[1];
        if(board[x][y]=='M'){
            board[x][y]='X';
            return board;
        }
        q.push({x,y});
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            x=p.first;
            y=p.second;
            if(board[x][y]>='1'&& board[x][y]<='9') continue;
            int cnt=0;
            for(int i=x-1;i<=x+1;i++){
                for(int j=y-1;j<=y+1;j++){
                    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='M')continue;
                    cnt++;
                }
            }
            if(cnt>0){
                board[x][y]='0'+cnt;
                continue;
            }
            board[x][y]='B';
            for(int i=x-1;i<=x+1;i++){
                for(int j=y-1;j<=y+1;j++){
                    if(i>=0 && j>=0 && i<board.size() && j<board[0].size() &&!vis[i][j]){
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
            
        }
        return board;
    }
};