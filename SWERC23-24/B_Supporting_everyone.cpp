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
#define fore(i, a, b) for (ll i = (a), TT = (b); i < TT; ++i)

int main()
{
    FIN;
    int n, m;
    cin >> n >> m;

    vector<int> colors(m + 1), bought(m + 1);
    unordered_map<string, bool> crayon;
    unordered_map<string, int> times;
    vector<string> names(n);

    int ans = 0;

    fore(i, 0, n)
    {
        int q; cin >> q;
        string country = "";
        fore(j, 0, q)
        {
            int x;
            cin >> x;
            country += to_string(x);
        }
        sort(country.begin(), country.end());
        times[country]++;
        names[i] = country;
    }

    // fore(i,0,n)
    // {
    //     print(names[i]);
    // }
    
    fore(i, 0, n)
    {
        string name = names[i];
        if(crayon[name] == true)
            continue;
    
        int q = times[name];
        int len = name.size();

        if (len <= q)
        {
            crayon[name] = true;
            for(auto c : name)
            {
                int d = c - '0';
                if(bought[d] == 0)
                {
                    ans++;
                }
                bought[d] = 1;
            }
        }
        else
            ans++;
    }

    print(ans);
}