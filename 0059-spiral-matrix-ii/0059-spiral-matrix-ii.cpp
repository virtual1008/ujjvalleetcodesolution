class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1;
        vector<vector<int>> temp(n,vector<int>(n));
        int startrow=0,startcol=0,endrow=n-1,endcol=n-1;
        while(cnt<=n*n){
           for(int i=startcol;cnt<=n*n && i<=endcol;i++){
               temp[startrow][i]=cnt;
               cnt++;
           }
           startrow++;
           for(int i=startrow;cnt<=n*n&& i<=endrow;i++){
               temp[i][endcol]=cnt;
               cnt++;
           }
           endcol--;
           for(int i=endcol;cnt<=n*n && i>=startcol;i--){
               temp[endrow][i]=cnt;
               cnt++;
           }
           endrow--;
           for(int i=endrow;cnt<=n*n&& i>=startrow;i--){
               temp[i][startcol]=cnt;
               cnt++;
           }
           startcol++;
            
        }
        return temp;
    }
};