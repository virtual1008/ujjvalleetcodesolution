class Solution {
public:
    string convert(string s, int no) {
        if(no==1)
        return s;
        int n=s.size();
        char v[no][1000];
        memset(v,'0',sizeof(v));
        int counter=0;
        int flag=1;
        int count=0;
        for(int i=0;i<1000;i++)
        {
                    if(count==n)
                        break;
                        
                        if(counter==0)
                        {
                            counter=no-2;
                            for(int j=0;j<no;j++)
                            {
                                v[j][i]=s[count];
                                count++;
                              if(count==n)
                              {
                                  flag=0;
                                  break;
                              }
                            }
                        }
                        else
                        {
                            v[counter][i]=s[count];
                            count++;
                            counter--;
                        }
            
            if(flag==0)
                break;
                    
        }
        string ans;
        for(int i=0;i<no;i++)
        {
            for(int j=0;j<1000;j++)
                if(v[i][j]!='0')
                    ans.push_back(v[i][j]);
        }
        return ans;
    }
};