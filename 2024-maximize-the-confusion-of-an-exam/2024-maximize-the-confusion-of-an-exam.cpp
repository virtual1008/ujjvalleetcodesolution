class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // if i wanna to change values of string answerkey to 'F';
        int cnt=0;
        int ans=0;
        int r=0;
        for(int i=0;i<answerKey.size();i++){
            if(answerKey[i]=='T') cnt++;
            while(k<cnt){
                if(answerKey[r]=='T') cnt--;
                r++;
            }
            ans=max(ans,i-r+1);
        }
        cnt=0;
        r=0;
        for(int i=0;i<answerKey.size();i++){
            if(answerKey[i]=='F') cnt++;
            while(k<cnt){
                if(answerKey[r]=='F') cnt--;
                r++;
            }
             ans=max(ans,i-r+1);
        }
        return ans;
    }
};