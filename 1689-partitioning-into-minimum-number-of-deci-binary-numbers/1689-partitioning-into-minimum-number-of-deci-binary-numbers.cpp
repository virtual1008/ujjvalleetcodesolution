class Solution {
public:
    int minPartitions(string n) {
        int x=0;
        for(int i=0;i<n.length();i++){
            int y=n[i]-'0';
            if(y>x) x=y;
        }
        return x;
    }
};