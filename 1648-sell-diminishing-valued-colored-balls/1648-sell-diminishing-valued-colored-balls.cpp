class Solution {
public:
    long long diff(long long a,long long b){
        return (a*(a+1)-b*(b+1))/2;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(),inventory.rend());
        int n=inventory.size();
        int mod=1e9+7;
        inventory.push_back(0);
        long long ans=0;
        long long cnt=0;
        for(int i=0;i<n;i++){
            long long a=inventory[i];
            long long b=inventory[i+1];
            cnt++;
            long long d=diff(a,b);
            if(cnt*(a-b)<=orders){
                orders-=cnt*(a-b);
                ans+=(cnt*d)%mod;
                ans%=mod;
            }else{
                long long  dividen,rem=0;
                dividen=orders/cnt,rem=orders%cnt;
                ans=(ans+(cnt*diff(a,a-dividen)))%mod;
                ans=(ans+((a-dividen)*rem))%mod;
                break;
            }            
        }
        return ans;
    }
};