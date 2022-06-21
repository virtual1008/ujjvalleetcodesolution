class Solution {
		int func(int i, int e, vector<int>& arr, vector<int>& dp) {
		if (i >= e) return 0;
		if (dp[i] != -1)
			return dp[i];
		dp[i] = max(func(i + 1, e, arr, dp), arr[i] + func(i + 2, e, arr, dp));
		return dp[i];
	}
public:
	
	int rob(vector<int>& nums) {

		if (nums.size() < 4)
			return *max_element(nums.begin(), nums.end());

		int ans = 0;
		
		vector<int> dp(nums.size(), -1);
		int without_first = func(0, nums.size() - 1, nums, dp);
		fill(dp.begin(), dp.end(), -1);
		int without_last = func(1, nums.size(), nums, dp);
		ans = max(without_first, without_last);				
		return ans;
	}
};