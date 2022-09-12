class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int l=0,r=tokens.size()-1;
        int score=0;
        while(l<=r){
            if(power>=tokens[l]){
                power-=tokens[l];
                score++;
                l++;
                
            }else if(score>=1){
                power+=tokens[r];
                score--;
                r--;
                
            }else{
                break;
            }
            ans=max(ans,score);
        }
        return ans;
    }
};