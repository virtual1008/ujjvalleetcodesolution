class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(33,0),v1(33,0);
        for(auto ele:nums){
            long long it=ele;
            int i=0;
            if(it>0){
               while(it>0){
                  int c=it%2;
                  if(c) v[i]++;
                  it/=2;
                  i++;
              }
            }else{
                it*=-1;
               while(it>0){
                  int c=it%2;
                  if(c) v1[i]++;
                  it/=2;
                  i++;
              } 
            }
        }
        long long ans=0;
        long long temp=1;
        bool flag=false;
        for(auto it:v){
            ans+=(temp*(it%3));
            temp*=2;
        }
        if(ans==0) flag=true;
        temp=1;
        for(auto it:v1){
            ans+=(temp*(it%3));
            temp*=2;
        }
        if(flag) ans*=-1;
        return ans;
    }
};