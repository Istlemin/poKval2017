#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
    string str; cin>>str;
    ll n = str.size();
    ll start = 0;
    rep(i,0,n)
        if(str[i] == 'V')
			start |= (1<<i);
    queue<pii> q;
    q.push({start,0});
    vector<bool> seen(1<<n,false);
    while(!q.empty()){
        ll c = q.front().first;
        ll dist = q.front().second;
        q.pop();
        if(c==(1<<n)-1) {
			cout<<dist<<endl;
			return 0;
        }
        if(seen[c]) continue;
        seen[c] = true;
        rep(i,0,n-1){
            ll left = c>>(i+2);
            ll lSize = n-2-i;
            ll right = c%(1<<i);
            ll rSize = i;
			ll p = (c&(3<<i))>>i;
            p = p^3;
            q.push({right+(left<<rSize)+(p<<(lSize+rSize)),dist+1});
            q.push({((right+(left<<rSize))<<2)+p,dist+1});
        }
    }
}
