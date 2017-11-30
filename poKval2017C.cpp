#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
	ll n; cin>>n;
    vi v(n);
    rep(i,0,n) cin>>v[i];
    ll ans = v[n-1];
    for(ll i = n-1; i>0; --i)
        ans = max(v[i],ans*2-v[i]);
    cout<<max(0ll,ans-v[0])<<endl;
}

/*ll extraBoxes = 0;
while(true){
	vi currV = v;
	currV[0] += extraBoxes;
	bool poss = true;
	rep(i,0,n-1){
		ll push = max(0LL,(currV[i]-currV[i+1])/2);
		currV[i] -= push;
		currV[i+1] += push;
		if(currV[i]<currV[i+1]){
			poss=false;
			break;
		}
		assert(currV[i]>=currV[i+1]&&currV[i]<=currV[i+1]+1);
	}
	if(poss){
		cout<<extraBoxes<<endl;
		break;
	}
	extraBoxes++;
}*/
