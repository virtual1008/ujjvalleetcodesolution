class Solution {
public:
    int cnt=0;
    int countArrangement(int n) {
        vector<int> vec;
        for(int i=1;i<=n;i++) vec.push_back(i);
        rec(0,vec);
        return cnt;
    }
    void rec(int i,vector<int> &arr){
        if(i==arr.size()) cnt++;
            for(int j=i;j<arr.size();j++){
                swap(arr,i,j);
                if(arr[i]%(i+1)==0 || (i+1)%arr[i]==0)rec(i+1,arr);
                swap(arr,i,j);
            }
        
    }
    void swap(vector<int> &arr,int i,int j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
};