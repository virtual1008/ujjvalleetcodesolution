class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        unordered_map<string,int>mp;
        int size = messages.size();
        int words=0;
        int val=0;
        string ans="";
        string str;
        for(int i=0;i<size;i++)
        {
            str = messages[i];
            words=0;
            for(int j=0;j<str.length();j++)
            {
                if(str[j]==' ')
                {
                    words++;
                }
            }
            words++;
            mp[senders[i]]+=words;
            if(val<mp[senders[i]])
            {
                val=mp[senders[i]];
                ans=senders[i];
            }
            else if(val==mp[senders[i]] and senders[i]>ans)
            {
                ans=senders[i];
            }
        }
        return ans;
    }
};