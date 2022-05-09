class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> a(n),b(n);
         int maxi=INT_MAX;
        for(int i=n-1;i>=0;i--){
            maxi=min(maxi,arr[i]);
            b[i]=maxi;
        }
       
        maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            a[i]=maxi;
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(a[i]<=b[i+1]) cnt++;
        }
        return cnt+1;
    }
};