class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<int,int> mp;
        while(n>0){
            mp[n%10]++;
            n/=10;
        }
        map<int,map<int,int>> cnt;
        for(int i=0;i<31;i++){
            int val=1<<i;
            int k=val;
            map<int,int> np;
            while(k>0){
               np[k%10]++;
               k/=10;
            }
            cnt[val]=np;
            
        }
        bool flag=false;
        for(auto it:cnt){
            if(it.second==mp) flag=true;
        }
        return flag;
    }
};