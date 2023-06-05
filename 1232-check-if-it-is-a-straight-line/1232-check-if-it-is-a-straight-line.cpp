class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
         if(coordinates.size()<=2) return true;
         //sort(coordinates.begin(),)
         double x1=coordinates[0][0],x2=coordinates[1][0];
         double y1=coordinates[0][1],y2=coordinates[1][1];
         if(x1==x2){
             for(auto it:coordinates){
                 if(it[0]!=x1) return false;
             }
             return true;
         }else{
             double slope=(y2-y1);
             slope/=(1.0*(x2-x1));
             //cout<<slope<<"->";
             for(int i=1;i<coordinates.size();i++){
                  x1=coordinates[i-1][0],x2=coordinates[i][0];
                  y1=coordinates[i-1][1],y2=coordinates[i][1];
                 double temp=(y2-y1);
                 if(x2==x1) return false;
                 temp/=(1.0*(x2-x1));
                 //cout<<temp<<" ";
                 if(temp!=slope) return false;
             }
         }
        return true;
    }
};