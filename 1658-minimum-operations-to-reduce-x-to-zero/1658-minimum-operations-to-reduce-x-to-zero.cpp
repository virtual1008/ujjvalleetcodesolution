class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int a:nums)
            sum += a; 
        sum -= x;  
		
        int left = 0, right = 0;
        int curr_sum = 0, ans = INT_MAX;
        while(right <= n && left <= right){
            if(curr_sum == sum){
                ans = min(ans, n - (right - left));
                curr_sum -= nums[left];
                left++;
                continue;
            }
            if(curr_sum < sum){
                curr_sum += nums[right];
                right++;
            }else if(curr_sum > sum){
                curr_sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};