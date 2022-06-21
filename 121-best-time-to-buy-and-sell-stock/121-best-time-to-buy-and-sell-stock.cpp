class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int mval=0,maxi=INT_MAX;
     for(int i=0;i<prices.size();i++){
         maxi=min(prices[i],maxi);
         mval=max(mval,prices[i]-maxi);
         
     }
        return mval;
        
    }
};