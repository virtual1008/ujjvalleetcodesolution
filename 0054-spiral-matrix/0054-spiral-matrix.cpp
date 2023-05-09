class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int startcol=0,startrow=0,endcol=m-1,endrow=n-1;
        int total=n*m;
        int cnt=0;
        vector<int> ans;
        while(cnt<total){
            for(int i=startcol;cnt<total && i<=endcol;i++){
                ans.push_back(matrix[startrow][i]);
                cnt++;
            }
            startrow++;
            for(int i=startrow;cnt<total && i<=endrow;i++){
                ans.push_back(matrix[i][endcol]);
                cnt++;
            }
            endcol--;
            for(int i=endcol;cnt<total && i>=startcol;i--){
                ans.push_back(matrix[endrow][i]);
                cnt++;
            }
            endrow--;
            for(int i=endrow;cnt<total && i>=startrow;i--){
                ans.push_back(matrix[i][startcol]);
                cnt++;
            }
            startcol++;
        }
        return ans;
        
    }
};