class Solution {
public:
     unordered_map<char,string> mapping = 
       { {'2', "abc"}, 
        {'3',"def" }, 
        {'4', "ghi" }  ,
        {'5', "jkl"}, 
        {'6', "mno" } ,
        {'7', "pqrs"}, 
        {'8', "tuv"} , 
        {'9', "wxyz" }};
    void combination(string v1,string v2,int i,vector<string> &comb){
        if(i==v1.size()) {
            comb.push_back(v2);
            return;
        }
        char ch=v1[i];
        string str=mapping[ch];
        for(int k=0;k<str.size();k++){
            char letter = str[k];
            combination(v1, v2+letter, i+1, comb);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> comb;
        if(digits.size()==0) return comb;
        combination(digits,"",0,comb);
        return comb;
        
    }
};