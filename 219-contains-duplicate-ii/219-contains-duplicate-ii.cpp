class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        
        int n=v.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
                m[v[i]].push_back(i);
        }
        
        for(auto i:m)
        {
             vector<int>temp=i.second;
            if(temp.size()>1)
            {
                for(int i=1;i<temp.size();i++)
                {
                    if(abs(temp[i-1]-temp[i])<=k)
                        return true;
                }
            }
        }
        return false;
        
    }
};