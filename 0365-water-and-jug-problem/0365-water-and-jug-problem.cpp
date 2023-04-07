class Solution {
public:
    bool bfs(int &total ,int &target ,int &jug1,int &jug2,int jug,vector<int> & vis){
        if(jug>total ||  jug<0 ||vis[jug]==true) return false;
        if(jug==target) return true;
        vis[jug]=true;
        bool a=bfs(total,target,jug1,jug2,jug+jug1,vis);
        bool b=bfs(total,target,jug1,jug2,jug-jug1,vis);
        bool c=bfs(total,target,jug1,jug2,jug+jug2,vis);
        bool d=bfs(total,target,jug1,jug2,jug-jug2,vis);
        return a||b||c||d;
    }
    bool canMeasureWater(int jug1, int jug2, int target) {
        int total=jug1+jug2;
        vector<int> vis(total+1,false);
        return bfs(total,target,jug1,jug2,0,vis);
    }
};