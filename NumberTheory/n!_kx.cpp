 #include<bits/stdc++.h>
 using namespace std;

vector<int> Sieve(int n){
    vector<int> p(n+1,0);
    p[2]=1;
    for(int i=3; i < n+1; i+=2)p[i]=1;
    for(int i=3; i< n+1; i+=2){
        if(p[i]){
            for(int j=i*i; j < n+1; j+=i)p[j]=0;
        }
    }
    return p;
}

map<int,int> primeFactorization(int n){
    vector<int> p = Sieve(n);
    // vector<int> primeFactors;
    map<int,int> mp;
    for(int i=2; i < n+1; i++){
        if(p[i]){
            // cout<<i;
            while(n > 1){
                if(n%i != 0){
                    break;
                }
                n /= i;
                mp[i]++;
            }
        }
    }
    return mp;
}

map<int,int> calPowers(map<int,int> mp,int n){
    map<int,int> powers;
    for(auto i: mp){
        int key = i.first;
        int ct = 0;
        while(key <= n){
            ct += floor(float(n)/key);
            // cout<<key<<" "<<ct<<endl;
            key*=i.first;
        }
        powers[i.first]=ct;

    }
    return powers;
}

int main(){
    int n,k;
    cin>> n>>k;
    map<int,int> factors = primeFactorization(k);
    map<int,int> powers = calPowers(factors,n);
    int ans=INT_MAX;
    for(auto i:factors){
        // cout<<i.first<<" "<<powers[i.first]<<endl;
        ans = min(ans,powers[i.first]/i.second);
    }
    cout<<ans;
}