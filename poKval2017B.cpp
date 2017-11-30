#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

/*
Iterera över alla möjliga längder a på den ena sidan,
och räkna för varje a ut ett giltigt intervall för längden 
b på den andra sidan. Ifall a ligger i intervallet för b
sätter man b = a, ifall a<minB sätter man b=minB och
ifall a>minB sätter man b=maxB. Det värdet på a som ger
lägst värde på abs(a-b) är lösningen.

Om man testar alla möjliga värden på a kommer man i värsta fall
behöva iterara 10^12 gånger (alldeles för mycket), men på grund
av rektangels symmetri räcker det att testa alla värden på a som
är mindre eller lika med kvadratroten av maximala arean, vilket ger 
ca 10^6 iterationer av loopen.

*/

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
