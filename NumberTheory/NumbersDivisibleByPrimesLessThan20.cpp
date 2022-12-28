#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> arr2,int k){
    vector<int> arr;
    for(int i:arr2){
        if(i <= k)arr.push_back(i);
    }
    vector<vector<int>> sets;
    int n = arr.size();
    for(int i=0; i < (1<<n); i++){
        vector<int> tmp;
        for(int j=0; j < n; j++){
            if(i&(1<<j)){
                tmp.push_back(arr[j]);
                // cout<<arr[j]<<" ";
            }
        }
        // cout<<endl;
        sets.push_back(tmp);
    }
    return sets;
}

int main(){
    int n;
    cin>>n;
    vector<int> primes = {2,3,5,7,11,13,17,19};
    vector<vector<int>> sets = subsets(primes,n);
    int ans = 0;
    for(int i=0; i < sets.size(); i++){
        int sz = sets[i].size();
        if(sz==0)continue;
        int ele=1;
        for(int j=0; j < sz; j++){
            ele*=sets[i][j];
        }
        if(sz&1)ans+=floor(n/ele);
        else ans-=ceil(n/ele);
    }
    cout<<ans;
}