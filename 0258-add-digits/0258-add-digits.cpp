class Solution {
public:
    int len(int num){
        int c=0;
        while(num>0){
            num/=10;
            c++;
        }
        return c;
    }
    int sumv(int num){
        int c=0;
        while(num>0){
            c+=(num%10);
            num/=10;
        }
        return c;
    }
    int addDigits(int num) {
        if(num==0) return 0;
        while(len(sumv(num))!=1){
            num=sumv(num);
            
        }
        return sumv(num);
    }
};