#include<bits/stdc++.h>
using namespace std;

vector<bool> Sieve(long long n=10000001){
    vector<bool> p(n+1,0);
    p[2]=1;
    for(long long i=3; i < n; i+=2)p[i]=1;
    for(long long i=3; i < n; i+=2){
        if(p[i]==1){
            for(long long j=i*i;j < n; j+=i)p[j]=0;
        }
    }
    return p;
}

vector<int> primes(long long n){
    vector<bool> p = Sieve(n);
    for(int i=2; i < n+1; i++){

    }
}

bool largeNumberPrime(long long n){
    vector<bool> p = Sieve();
    if(n < 10000001)return p[n];
    // cout<<n;
    for(long long i = 2; i*i < n+1; i++){
        if(p[i] && (n%i)==0){
            // cout<<i<<" ";
            return false;
        }
    }
    return true;
}
int main(){
    // int n;
    // cin>>n;
    // vector<bool> p = Primes(n);
    // for(int i=0; i < n; i++)if(p[i])cout<<i<<" ";
    cout<<largeNumberPrime(2147483647LL);
    return 0;
}