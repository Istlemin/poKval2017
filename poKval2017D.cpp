#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

/*
Ifall man ser spelet som en riktad graf, där varje nod 
representerar ett state i spelet, och varje kant från nod
a till b representerar ett drag som man kan göra för att
komma från a till b. Då kan man göra en BFS i grafen från
start-statet till målstatet. Tidskomplexiteten för BFS är
O(antal kanter+antal noder), vilket går då antalet kanter är
ca N*2^N där N är längden på sekvensen, som är <= 15.

Man kan även se det som att man börjar med att hitta alla
states som ligger exakt ett drag från starten, därifrån hitta
alla states som ligger exakt två drag från starten o.s.v.
När man kommer till målstatet avbryter man.

Ett smidigt sätt att implementera detta på är med så kallade
bitmasks. Man representerar varje state med ett tal melan
0 och 2^N, där talets representation i bas 2 beskriver statet.
Då det finns inbyggt många operationer för (snabbt) manipulera
bitarna för ett tal går det relativt enkelt att utföra dragen.
Dessutom gör detta det enklare att hålla koll på vilka states
du redan utforskat, då man enkelt kan använda ett state som
index i en array.

*/

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
