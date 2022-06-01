class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> curr={1};

    if(n==0){
        return curr;
    }

    while (n--)
    {
        vector<int> temp(curr.size()+1,0);
        for (int i = 0; i < temp.size(); i++)
        {
            if(i-1>=0){
                temp[i]+=curr[i-1];
            }
            if(i<=curr.size()-1){
                temp[i]+=curr[i];
            }
            

        }
        curr=temp;
  
        

    }
    return curr;
    }
};