#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

/*
Ett angripsätt är att göra en brute force. Man testar
alla möjliga antal extra lådor att börja med, och sedan
simulerar man processen och kollar ifall man kommer hela
vägen. I varje steg vill man putta ner så många lådor som
går. Detta funkerar dock inte, eftersom man kan behöva upp till
3000*2^20 extra lådor att börja med.

Istället kan man göra
en binärsökning, över antal extralådor. Detta går eftersom 
ifall man testar ett värde och ser att det inte fungerar vet
man att svaret är större, och om man får att det fungerar
vet man att svaret är lägre.

Ett annat sätt man kan göra på är att "gå baklänges" genom
staplarna. Först räkna ut hur många extra som behövs om man
börjar på näst sista, därifrån hur många som behövs om man
börjar på tredje sista o.s.v.
*/

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