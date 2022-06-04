class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
        int left=0,right=n-1;
        int cnt=0;
        int lmax=0,rmax=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=lmax) lmax=height[left];
                else cnt+=lmax-height[left];
                left++;
            }else{
                if(height[right]>=rmax) rmax=height[right];
                else cnt+=rmax-height[right];
                right--;
            }
        }
        return cnt;
    }
};