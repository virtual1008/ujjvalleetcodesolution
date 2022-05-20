class Solution {
public:
    bool check(vector<int>v)
    {
        int n=v.size();
        for(int i=1;i<n;i++)
        {
            if(v[i]<=v[i-1])
                return false;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& v) {
      int cnt=0;
        if(check(v))
            return true;
        
        vector<int >first,second;
        int n=v.size();
        int i;
        for(  i=0;i<n-1;i++)
        {
            if(v[i+1]<=v[i])
            {
                first.push_back(v[i]);
                second.push_back(v[i+1]);
                i+=2;
                break;
            }
            else
            {
                first.push_back(v[i]);
                second.push_back(v[i]);
            }
        }
        for(;i<n;i++)
        {
            first.push_back(v[i]);
                second.push_back(v[i]);
        }
       
        
        if(check(first) || check(second))
            return true;
        else
            return false;
    }
};