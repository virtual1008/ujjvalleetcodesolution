class Solution {
public:
    int jump(vector<int> & nums){
    int n=nums.size();
    vector<int> jump(n,INT16_MAX);
    jump[0]=0;

    for(int i=0 ; i<n-1;++i)
    {
      for(int j=i+1;j<=(i+nums[i]) && j<n;++j)
      {
        jump[j]=min(jump[i]+1, jump[j]);
      }

    }
  return jump[n-1];

}
};