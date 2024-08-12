#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

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

#define INF LLONG_MAX / 3

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;
}

int main()
{
    FIN;
    int n;
    cin >> n;
    vector<pair<ll, ll>> teams(n);

    vector<string> input;

    fore(i, 0, n)
    {
        string name;
        cin >> name;
        input.push_back(name);

        ll p;
        cin >> p;

        ll maxv = -1, minv = INF;
        ll points = 0;
        fore(i, 0, 6)
        {
            ll x;
            cin >> x;
            points += x;
            minv = min(minv, x);
            maxv = max(maxv, x);
        }
        points -= minv;
        points -= maxv;

        points += 10 * p;

        teams[i] = {points, i};
    }

    sort(teams.begin(), teams.end(), comp);

    // fore(i, 0, n)
    //     cout << teams[i].first << " ";
    // cout << endl;

    ll medals = 0;

    fore(i, 0, n)
    {
        if (medals >= 3)
            break;

        int current_points = teams[i].first;

        while (current_points == teams[i].first && i < n)
        {
            print(input[teams[i].second] << " " << teams[i].first);
            medals++;
            i++;
            if (medals >= 1000)
            {
                return 0;
            }
        }
        i--;
    }

    // print(medals);
}