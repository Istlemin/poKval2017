#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(){
	cin.sync_with_stdio(false);
    ll mn,mx;
    cin>>mn>>mx;
    ll bestA = 0;
    ll bestB = 1e18;
    rep(a,1,sqrt(mx)+10){
        ll minB = mn/a;
        if(mn%a!=0) minB++;
        ll maxB = mx/a;
        if(minB>maxB) continue;
        ll b;
        if(a>=minB&&a<=maxB)
			b = a;
        if(a<minB)
			b = minB;
		if(a>maxB)
			b = maxB;
        if(abs(bestA-bestB)>abs(a-b)){
			bestA = a;
			bestB = b;
        }
    }
    if(bestA>bestB)
		swap(bestB,bestA);
    cout<<bestA<<" "<<bestB<<endl;
}
