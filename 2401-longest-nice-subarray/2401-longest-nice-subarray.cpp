class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> vec(32,0);
        int ans=0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            int c=nums[i];
            int k=0;
            vector<int> temp(32,0);
            bool flag=true;
            while(c>0){
                int r=c%2;
                c/=2;
                temp[k]=r;
                if(r==1 && vec[k]){
                    flag=false;
                    break;
                }
                k++;
            }
            c=nums[i];
            if(flag){
                for(int a=0;a<32;a++){
                    vec[a]|=temp[a];
                }
                ans=max(ans,i-j+1);
            }else{
                int b=nums[j];
                k=0;
                while(b>0){
                    int r=b%2;
                    if(r) vec[k]^=r;
                    k++;
                    b/=2;
                }
                j++;
                i--;
            }
        }
        return ans;
    }
};






