#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> pre(n,0);
    vector<int> a(n,0);
    int sum = 0;
    pre[0]++;
    for(int i=0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
        sum%=k;
        sum = (sum+k)%k;                    //To deal with negative remainders
        pre[sum]++;
    }
    int ct = 0;
    for(int i=0; i < k; i++){
        ct += (pre[i]*(pre[i]-1))/2;
    }
    cout<<ct;

}