class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> check;
        check.push_back({1});
        check.push_back({1,1});
        for(int i=2;i<34;i++){
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            int l=1,r=i-1;
            while(l<=r){
                int a=check[i-1][l-1];
                int b=check[i-1][l];
                temp[l]=a+b;
                temp[r]=a+b;
                r--;
                l++;
            }
            check.push_back(temp);
        }
        return check[rowIndex];
    }
};