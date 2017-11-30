#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
	vi v(5);
	rep(i,1,5)
		cin>>v[i];
    ll ans = v[4]+v[3];
    v[1] -= min(v[3],v[1]);
    ans += (v[2]*2+v[1])/4;
    if((v[2]*2+v[1])%4!=0) ans++;
	cout<<ans<<endl;
}
