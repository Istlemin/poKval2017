#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

/*
Vi definerar en funktion f(I(heltal), catalogs(mängd))
som svarar på frågan "ifall vi bara får titta
på videor som ligger efter index I i listan, vi
har redan tittat på alla kataloger i mängden catalogs,
vad är den kortaste tiden som vi härifrån kan titta på en video
från varje katalog."

Funktionens värde för f(0,tom mängd) är svaret vi söker.

För varje video kan man välja att antingen inte kolla på den
eller kolla på den, och vi kan därför räkna ut värdet på f
rekursivt genom att testa de två fallen och välja det som ger
lägst svar:

f(I,catalogs) =
	min av
		1: (längden på video I) + f(i+1, (catalogs) union (katalogerna för videon på index I)) (Fallet då man tittar på videon på index I)
		2: f(i+1, catalogs) (Fallet då man inte tittar på videon på index I)


Basfallen blir

f(I,Full mängd) = 0 (ifall man kollat på alla kategorier redan behöver man inte kolla på några fler)
f(N,inte full mängd) = oändligt (ifall man gått igenom alla videos men inte sätt alla kategorier går det aldrig att se alla)

I koden representeras f(I,catalogs) som dp[I][catalogs]
catalogs representeras som en bitmask,
för att enkelt kunna använda det som ett index i en vektor.


*/

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
