class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& tar) {
        int cnt0=0,cnt90=0,cnt180=0,cnt270=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 int x=i,y=j;
                 if(tar[i][j]!=mat[x][y]) cnt0++;
                 int temp=x;
                 x=y;
                 y=abs(n-1-temp);
                 if(tar[i][j]!=mat[x][y]) cnt90++;
                 temp=x;
                 x=y;
                 y=abs(n-1-temp);
                 if(tar[i][j]!=mat[x][y]) cnt180++;
                 temp=x;
                 x=y;
                 y=abs(n-1-temp);
                 if(tar[i][j]!=mat[x][y]) cnt270++;
            }
        }
        return min({cnt0,cnt90,cnt180,cnt270})==0;
    }
};