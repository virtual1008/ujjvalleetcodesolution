class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        for(int i=0;i<(a+b);i++){
            ans+='a';
        }
        if(abs(a-b)<=1){
            int i=0;
            while(b>0){
                ans[i]='b';
                i+=2;
                b--;
            }
        }else{
           if(b>a){
               int i=0;
               while(abs(a-b)>1){
                   ans[i]='b';
                   i++;
                   ans[i]='b';
                   i+=2;
                   b-=2;
                   a--;
               }
               while(b>0){
                   ans[i]='b';
                   i+=2;
                   b--;
               }
               
           }else{
                for(int i=0;i<(a+b);i++){
                  ans[i]='b';
                }
                int i=0;
                while(abs(a-b)>1){
                   ans[i]='a';
                   i++;
                   ans[i]='a';
                   i+=2;
                   b-=1;
                   a-=2;
               }
               while(a>0){
                   ans[i]='a';
                   i+=2;
                   a--;
               }
               
           }
        }
        return ans;
    }
};