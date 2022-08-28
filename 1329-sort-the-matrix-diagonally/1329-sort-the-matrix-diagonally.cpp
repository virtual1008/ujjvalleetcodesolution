class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
         int n=mat.size();
         int m=mat[0].size();
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 vector<int> temp;
                 priority_queue<int,vector<int>,greater<int>> pq;
                 int a=i,b=j;
                 while(a<n && b<m){
                     pq.push(mat[a][b]);
                     a++;
                     b++;
                 }
                 //sort(temp.begin(),temp.end());
                 a=i,b=j;
                 //int c=0;
                 while(!pq.empty()){
                     int c=pq.top();
                     mat[a][b]=c;
                     a++;
                     b++;
                     pq.pop();
                 }
             }
         }
        return mat;
    }
};