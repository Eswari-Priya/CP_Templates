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

vector<double> EulerTotient(int n){
    vector<double> coprimes(n+1,0);
    for(int i=0; i < n+1; i++)coprimes[i]=i;
    for(int i=2; i < n+1; i++){
        if(coprimes[i]==i){
            coprimes[i]--;
            long long x = i+i,y=i;
            while(x <n+1){
                coprimes[x] *= ((double)1 - (double)1/y);
                x+=y;
            }
        }
    }
    return coprimes;
}

int main(){
    int n;
    cin>>n;
    vector<double> ans = EulerTotient(n);
    for(int i=2; i < n+1; i++){
        cout<<i<<" "<<ans[i]<<endl;
    }
    return 0;
}