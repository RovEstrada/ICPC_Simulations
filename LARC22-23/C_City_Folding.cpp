#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vll;

#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)

int main(){FIN;

    ll n, p, h; cin >> n >> p >> h;
    vector<bool> m(n);
    h--;
    p--;
    ll q = 1 << n;
    
    for(ll i = n - 1; i >= 0; i--){
        if (h < 1ll<<i)
            m[i] = false;
        else{
            m[i] = true;
            h = 1ll<<(i+1) - 1 - h;
        }
    }

    q = 1 << n;
    char zero, one;
    if(p <= q/2){
        one = 'L';
        zero = 'R';
    }else{
        one = 'R';
        zero = 'L';
    }

    for(ll i = 0 ; i < n; i++){
        if(m[i])
            cout << one;
        else 
            cout << zero;
    }

    cout << endl;




}