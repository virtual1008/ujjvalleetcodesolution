class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int a=-1;
        int b=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mini>nums[i]){
                mini=nums[i];
                a=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                b=i;
            }
        }
        int x=max(a,b)+1;
        int y=n-(min(a,b));
        int z=min(a,b)+1+n-max(b,a);
        cout<<x<<" "<<y<<" "<<z;
        return min({x,y,z});
        
    }
};