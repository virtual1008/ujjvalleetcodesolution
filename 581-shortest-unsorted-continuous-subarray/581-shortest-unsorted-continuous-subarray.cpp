class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
	        return 0;
        
        int smallest = INT_MAX;
        int largest = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(i != 0 && arr[i] < arr[i - 1]) {
                smallest = min(smallest, arr[i]);
                largest = max(largest, arr[i]);
            }
            else if(i != n - 1 && arr[i] > arr[i + 1]) {
                smallest = min(smallest, arr[i]);
                largest = max(largest, arr[i]);
            }      
        }
        
        if(smallest == INT_MAX || largest == INT_MIN)
            return 0;
        
        int left = 0;
        while(left < n - 1 && smallest >= arr[left])
            left++;
        
        int right = n - 1;
        while(right > 0 && largest <= arr[right])
            right--;
        
        return right - left + 1;
    }
};