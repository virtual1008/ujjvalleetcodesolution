class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int i=0,j=people.size()-1;
        while(i<=j){
            int u=people[i];
            int v=people[j];
            if(i==j){
                ans++;
                i++;
            }else if(u+v<=limit){
                ans++;
                i++;
                j--;
            }else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};