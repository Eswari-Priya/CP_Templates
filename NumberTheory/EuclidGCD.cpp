#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
     if(b==0)return a;
     return gcd(b,a%b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(max(a,b),min(a,b));
    return 0;
}