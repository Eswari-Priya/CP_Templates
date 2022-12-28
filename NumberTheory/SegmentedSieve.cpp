#include<iostream>
#include<vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
vector<int> primes;
void Primes(long long n=32000){
    vector<bool> p(n,0);
    p[2]=1;
    for(long long i=3; i < n; i+=2)p[i]=1;
    for(long long i=3; i < n; i+=2){
        if(p[i]==1){
            for(long long j=i*i;j < n; j+=i)p[j]=0;
        }
    }
    for(int i=0; i < n; i++){
        if(p[i])primes.push_back(i);
    }
    // return p;
}

vector<bool> SegmentedSieve(long long m, long long n){
    Primes();
    vector<bool> np(n-m+1,1);
    for(int i=0; primes[i]*primes[i] <= n; i++){
        int mul = ceil(float(m)/primes[i]);
        if(mul==1){
            // np[0]=1
            mul++;
        }
        for(int j=primes[i]*mul; j <= n; j+=primes[i]){
            np[j-m]=0;
        }
        
    }
    for(int i=0; i < n-m+1; i++){
        if(np[i] && i+m!= 1)cout<<i+m<<"\n";
    }
    cout<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        SegmentedSieve(m,n);
        
    }
    return 0;
}