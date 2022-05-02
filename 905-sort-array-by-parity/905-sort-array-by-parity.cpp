class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
        int l=0,r=1;
        while(r<v.size() && l<v.size()){
            if(v[r]%2==0 && v[l]%2!=0 && r>l){
                swap(v[r],v[l]);
                l++;
                r++;
            }else if(v[l]%2==0) l++;
            else r++;
        }
        return v;
    }
};