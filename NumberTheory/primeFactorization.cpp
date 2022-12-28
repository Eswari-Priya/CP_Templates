#include<bits/stdc++.h>
using namespace std;

map<int,int> primeFactorization(int n){
    
    map<int,int> mp;
    for(int i=2; n>1; i++){
        while((n%i) == 0){
            mp[i]++;
            n/=i;
        }
        // cout<<n<<" "<<is<<endl;
    }
    return mp;
}

int main(){
    int n;
    // cin>>n;
    map<int,int> pf = primeFactorization(81);
    for(auto i:pf){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}