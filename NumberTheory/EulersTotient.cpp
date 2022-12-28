#include<bits/stdc++.h>
using namespace std;

map<int,int> primeFactorization(int n){
    map<int,int> mp;
    for(int i=2; n>1; i++){
        while((n%i) == 0){
            mp[i]++;
            n/=i;
        }
    }
    return mp;
}


double NumberOfCoPrimes(int n){
    map<int,int> factors = primeFactorization(n);
    double ans = n;
    for(auto i:factors){
        ans *= double(1-(double(1)/i.first));
        // cout<< double(1-(double(1)/i.first));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<NumberOfCoPrimes(n);
    return 0;
}