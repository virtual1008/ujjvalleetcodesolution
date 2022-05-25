class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=i-1,y=i+1;
            while(x>=0 && y<n && s[x]==s[y] ){
                x--;
                y++;
                ans++;
            }
             x=i,y=i+1;
             while(x>=0 && y<n && s[x]==s[y] ){
                x--;
                y++;
                ans++;
            }
        }
        return ans+n;
    }
};