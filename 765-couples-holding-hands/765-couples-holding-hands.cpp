class Solution {
public:
    map<int,int> m;
    int minSwapsCouples(vector<int>& row) {
        for(int i=0;i<row.size();i++){
            m[row[i]]=i;
        }
        int t=0;
        for(int i=0;i<row.size();i+=2){
            int first=row[i];
            int second=first^1;
            if(row[i+1]!=second){
                swap(row,i+1,m[second]);
                t++;
            }
        }
        return t;
    }
    void swap(vector<int> &arr,int i,int j){
       int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        m[arr[i]]=i;
        m[arr[j]]=j;
    }
};