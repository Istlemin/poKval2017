#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

/*
4- och 3-grupper behöver egna sätesgrupper,
men i varje 3-grupp kan även en 1-grupp sitta,
så vi subtraherar min(3grupper,1grupper) från antal 1grupper.
Nu har vi endast 2- och 1-grupper kvar, och då går det alltid
att fylla ut så att endast en sätesgrupp inte blir tom.
Därför adderar vi bara (antal personer kvar)/4 avrundat uppåt till svaret.
Notera att om man man gör heltalsdivition avrundas default neråt,
så man måste addera 1 så länge det inte är delbart med 4
*/

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
