class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> v(n+1,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i+1][j]= v[i][j]+matrix[i][j];
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int l=i+1;l<=n;l++){
                for(int j=0;j<m;j++){
                    int sum=0;
                    for(int r=j;r<m;r++){
                        sum+=v[l][r]-v[i][r];
                        if(sum==k) return k;
                            if(sum<=k) ans=max(ans,sum);
                    }
                }
            }
        }
        return ans;
    }
};