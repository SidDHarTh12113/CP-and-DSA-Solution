#include<bits/stdc++.h>
using namespace std;
 
int solve(vector<int> a,vector<int>b){
    int n=a.size(),m=b.size();
    int i=0,j=0,ans=0,sone=0,stwo=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            sone+=a[i];
            i++;
        }else if(a[i]>b[j]){
            stwo+=b[j];
            j++;
        }else{
            ans+=max(sone,stwo);
            ans+=a[i];
            i++;j++;
            sone=0;
            stwo=0;
        }
    }
    while(i<n){
        sone+=a[i];
        i++;
    }
    while(j<m){
        stwo+=b[j];
        j++;
    }
    ans+=max(sone,stwo);
    return ans;
}
int main()
{
    int n;
    while(true){
    cin>>n;
    if(n==0)
       return 0;
    else{
        vector<int> arr1(n);
        for(int i=0;i<n;i++)
           cin>>arr1[i];
        int m;
        cin>>m;
        vector<int> arr2(m);
        for(int i=0;i<m;i++)
           cin>>arr2[i];
        cout<<solve(arr1,arr2)<<endl;
    }
    }
    return 0;
}
