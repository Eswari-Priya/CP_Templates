 // GCD*LCM = a*b

#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
     if(b==0)return a;
     return gcd(b,a%b);
}

int lcm(int a,int b){
    int Gcd = gcd(max(a,b),min(a,b));
    return a*b/Gcd;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}