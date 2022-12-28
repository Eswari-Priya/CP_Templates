#include<bits/stdc++.h>
using namespace std;
struct Triplet{
    int gcd;
    int x;
    int y;
};

Triplet extendedEuclid(int a,int b){
    if(b==0){
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    Triplet partialAns = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=partialAns.gcd;
    ans.x = partialAns.y;
    ans.y = partialAns.x - floor(a/b)*partialAns.y;
    return ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    Triplet ans = extendedEuclid(a,b);
    cout<<ans.x<<" "<<ans.y;
    return 0;
}
