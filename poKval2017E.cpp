#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
	ll n;
    cin>>n;
	vi t(n);
	vi c(n);
	ll allC = 0;
    rep(i,0,n){
		string cats;
		cin>>t[i]>>cats;
        rep(j,0,cats.size())
			c[i] |= (1<<(cats[j]-'a'));
		allC |= c[i];
    }
    vector<vi> dp(n+1,vi((1<<10),0));
    rep(j,0,1<<10)
		if(j!=allC)
			dp[n][j] = 1e18;
    for(ll i = n-1;i>=0;--i)
        rep(j,0,1<<10)
            dp[i][j] = min(dp[i+1][j|c[i]]+t[i],dp[i+1][j]);
    cout<<dp[0][0]<<endl;
}
