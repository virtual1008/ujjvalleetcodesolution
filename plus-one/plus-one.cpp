class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=1;
        for(auto &it:digits){
            int temp=it+carry;
            it=temp%10;
            carry=temp/10;
        }
        if(carry>0)digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};