//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        // k=m+n
        // k/2
        // k/2 and k+1/2;
       int k=array1.size()+array2.size()-1;
       double total=0;
       int a=k/2;
       int b=(k+1)/2;
       //cout<<a<<" "<<b;
       int i=0, j=0;
       int n=array1.size(),m=array2.size();
       while(i<n && j<m){
           int ele;
           int curr=i+j;
           if(array1[i]<=array2[j]){
               ele=array1[i];
               i++;
           }else{
               ele=array2[j];
               j++;
           }
         
           //cout<<total<<endl;
           //int curr=i+j;
           if(curr==a || curr==b){
              // cout<<ele;
               if(a==b) return ele;
               total+=(1.0)*(ele);
               if(curr==b) break;
           }
       }
       if(i==n){
           while(j<m){
               if(i+j==a || i+j==b){
                    if(a==b) return array2[j];
                    total+=(1.0)*(array2[j]);
                    if(i+j==b) break;
               }
               j++;
           }
       }
       if(j==m){
           while(i<n){
               if(i+j==a || i+j==b){
                    if(a==b) return array1[i];
                    total+=(1.0)*(array1[i]);
                    if(i+j==b) break;
                   // i++;
               }
               i++;
           }
       }

       return total/(2.0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends