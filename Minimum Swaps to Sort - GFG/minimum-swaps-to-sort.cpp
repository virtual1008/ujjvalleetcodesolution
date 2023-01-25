//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    // 10 19 6 3 5
	     // 1 5 4 6 2
	     // 1 2 4 5 6
	     map<int,int> m;
	     for(int i=0;i<nums.size();i++){
	         m[nums[i]]=i;
	     }
	     vector<int> temp=nums;
	     sort(temp.begin(),temp.end());
	     int cnt=0;
	     for(int i=0;i<nums.size();i++){
	         if(temp[i]!=nums[i]){
	             m[nums[i]]=m[temp[i]];
	             swap(nums[i],nums[m[temp[i]]]);
	             m[temp[i]]=i;
	             cnt++;
	         }
	     }
	     for(auto it:m){
	       //  cout<<it.first<<
	     }
	     return cnt;
	    
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends