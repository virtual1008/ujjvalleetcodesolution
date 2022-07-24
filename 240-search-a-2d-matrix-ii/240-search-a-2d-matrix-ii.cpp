class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int i=0,j=matrix[0].size()-1,n=matrix.size();
    while(j>=0 && i<n)
    {
        if(target>matrix[i][j])
            i++;
        else if(target<matrix[i][j])
            j--;
        else
            return true;
    }
    return false;
}
};