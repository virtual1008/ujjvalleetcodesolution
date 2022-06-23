class Solution {
public:
    int getMaxLen(vector<int>& nums) {
      int neg=0,pos=0,ans=0;
      for(int i=0;i<nums.size();i++){
          if(nums[i]==0){
              neg=0;
              pos=0;
          }else if(nums[i]>0){
              pos++;
              int a=neg;
              int b=pos;
              if(a%2==0)ans=max(ans,b+a);
          }else{
              neg++;
              if(neg%2==0) ans=max(neg+pos,ans);
              else ans=max(neg-1+pos,ans);
          }
      }
        neg=0;
        pos=0;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
          if(nums[i]==0){
              neg=0;
              pos=0;
          }else if(nums[i]>0){
              pos++;
              int a=neg;
              int b=pos;
              if(a%2==0)ans=max(ans,b+a);
          }else{
              neg++;
              if(neg%2==0) ans=max(neg+pos,ans);
              else ans=max(neg-1+pos,ans);
          }
      }
        
       return ans;
    }
};