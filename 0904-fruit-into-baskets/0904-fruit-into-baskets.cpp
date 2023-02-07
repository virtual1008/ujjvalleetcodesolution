class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int cnt=0;
        int ans=0;
        int j=0;
        unordered_set<int> st;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            st.insert(fruits[i]);
            if(mp[fruits[i]]==1) cnt++;
            if(cnt>2){
                while(cnt>2){
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0) {
                        st.erase(fruits[j]);
                        cnt--;
                    }
                    j++;
                }
            }
            int temp=0;
            for(auto it:st){
                temp+=mp[it];
            }
            ans=max(ans,temp);
            
        }
        return ans;
    }
};