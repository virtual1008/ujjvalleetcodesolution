class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 vector<int> temp;
                 int a=i,b=j;
                 while(a<n && b<m){
                     temp.push_back(mat[a][b]);
                     a++;
                     b++;
                 }
                 sort(temp.begin(),temp.end());
                 a=i,b=j;
                 int c=0;
                 while(c<temp.size()){
                     mat[a][b]=temp[c];
                     a++;
                     b++;
                     c++;
                 }
             }
         }
        return mat;
    }
};