class Solution {
public:
    int maxScore(vector<int>& vec, int k) {
        int sum=0;
        int n=vec.size();
        for(auto it:vec) sum+=it;
        int temp=0;
        int ans=0;
        for(int i=0;i<n-k;i++) temp+=(vec[i]);
        ans=sum-temp;
        for(int i=n-k;i<n;i++){
            temp+=vec[i];
            temp-=vec[i-(n-k)];
            ans=max(sum-temp,ans);
        }
        return ans;
        
    }
};