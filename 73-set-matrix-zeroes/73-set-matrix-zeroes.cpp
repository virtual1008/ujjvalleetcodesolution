class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        vector<pair<int,int>> vec;
        int n=v.size();
        int m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0) vec.push_back({i,j});
            }
        }
        for(auto it:vec){
            int i=it.first;
            int j=it.second;
            while(i>=0){
                v[i][j]=0;
                i--;
            }
            i=it.first;
            while(i<n){
                v[i][j]=0;
                i++;
            }
            i=it.first;
            while(j>=0){
                v[i][j]=0;
                j--;
            }
            j=it.second;
            while(j<m){
                v[i][j]=0;
                j++;
            }
        }
    }
};