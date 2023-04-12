class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vect;
        for(int i=0;i<path.size();i++){
            string temp="";
            while(path[i]!='/' && i<path.size()){
                temp+=path[i];
                i++;
            }
            if(temp.size()!=0)
            vect.push_back(temp);
        }
        vector<string> kd;
        int i=0;
        while(i<vect.size()){
            int len=vect[i].size();
            if(vect[i]==".."){
                if(kd.size()>0) kd.pop_back();
            }else if(vect[i]=="."){
                i++;
                continue;
            }
            else{
                kd.push_back(vect[i]);
            }
            i++;
        }
        string ans;
        ans+='/';
        i=0;
        while(i<kd.size()){
            ans+=kd[i];
            if(i!=kd.size()-1) ans+='/';
            i++;
        }
        return ans;
    }
};