#include<bits/stdc++.h>
using namespace std;

vector<bool> Sieve(long long n=10000001){
    vector<bool> p(n+1,0);
    p[2]=1;
    for(long long i=3; i < n+1; i+=2)p[i]=1;
    for(long long i=3; i < n+1; i+=2){
        if(p[i]==1){
            for(long long j=i*i;j < n+1; j+=i)p[j]=0;
        }
    }
    return p;
}

vector<long long> Primes(long long n){
    vector<bool> p = Sieve(n);
    vector<long long> primes;
    for(long long i=2; i < n+1; i++){
        if(p[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

vector<vector<long long>> DistinctPrimeFactors(int n){
    vector<vector<long long>> dprimes(n+1);
    vector<long long> primes = Primes(n);
    // cout<<"ok";
    for(long long i=0; i < primes.size(); i++){
        long long x = primes[i],y = primes[i];
        while(x < n+1){
            dprimes[x].push_back(y);
            x+=y;
        }
        // cout<<i<<"ok";
    }
    // cout<<"ok";
    return dprimes;
}

int main(){
    int n=40;
    vector<vector<long long>> dprimes = DistinctPrimeFactors(n);
    for(int i=0; i < n+1; i++){
        cout<<i<<"--";
        for(int j:dprimes[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}