class Solution {
public:
    string pushDominoes(string s) {
        int l=-1;
        int last=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                if(l==-1){
                    for(int j=i-1;j>=0 && s[j]=='.' ;j--) s[j]='L';
                }else{
                    int a=i-1;
                    int b=l+1;
                    while(b<a){
                        s[b]='R';
                        s[a]='L';
                        b++;
                        a--;
                    }
                    l=-1;
                }
                last=i;
            }else if(s[i]=='R'){
                if(l!=-1){
                    for(int j=l;j<i;j++) s[j]='R';
                }
                l=i;
            }
        }
        if(last<l){
            for(int j=l;j<n;j++) s[j]='R';
        }
        return s;
    }
};