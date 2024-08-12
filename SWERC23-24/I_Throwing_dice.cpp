#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long double ld;
typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(ll i = (a), TT = (b); i < TT; ++i)

int main(){ FIN;
    ll m, n;
    cin >> m >> n;

    vector<double> alice(m);
    vector<double> bob(n);

    double sumA = 0, sumB = 0, E;
    fore(i, 0, m){
        cin>>alice[i];
    }
    fore(i, 0, n){
        cin>>bob[i];
    }
    fore(i, 0, m){
        E = (1 + alice[i])/2.0 ;
        sumA += E;
    }
    fore(i, 0, n){
        E = (1+ bob[i])/2.0 ;
        sumB += E;
    }
    if(sumA > sumB){
        cout<<"ALICE";
    }
    else if(sumA < sumB){
        cout<<"BOB";
    }
    else{
        cout<<"TIED";
    }

    return 0;
}