#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using pii = pair<int,int>;
#define all(x) x.begin(),x.end()
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
	fast;
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
}

ll binaryExponent(int x,int n){
    if(n==0)return 1LL;
    if(n&1){
        ll val = binaryExponent(x,(n-1)/2);
        return val*val*x;
    }
    ll val = binaryExponent(x,n/2);
    return val*val;
}

void solve() {
	int x,n;
    cin>>x>>n;
    cout<<binaryExponent(x,n);
}

int main() {
	setIO();
    int tc =1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) 
        solve();
}