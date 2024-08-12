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

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// ll distance()

int main()
{
    FIN;
    ll n;
    cin >> n;
    vector<ll> mountains(n);
    vector<pii> l_max_v;

    vector<pii> r_max_v;

    fore(i, 0, n) cin >> mountains[i];

    ll l_max_index = 0;      // Index de la montana mas alta hacia un lado
    ll l_max = mountains[0]; // Montana mas alta hacia un lado

    ll r_max_index = n - 1;      // Index de la montana mas alta hacia un lado
    ll r_max = mountains[n - 1]; // Montana mas alta hacia un lado

    ll num_ans = 0;
    ll den_ans = 0;
    double beauty_max = 0;

    l_max_v.push_back({mountains[0], 0});

    fore(i, 1, n)
    {
        if (l_max < mountains[i])
        {
            l_max_v.clear();
            l_max_v.push_back({mountains[i], i});
            l_max = mountains[i];
            l_max_index = i;
            continue;
        }

        if (l_max_v.back().first >= mountains[i])
            l_max_v.push_back({mountains[i], i});
        else
        {
            ll j = l_max_v.size() - 1;
            while (l_max_v[j].first <= mountains[i] && j >= 0)
            {
                j--;
                l_max_v.pop_back();
            }

            if (j < 0)
                continue;

            ll slope = (mountains[l_max_v[j].second + 1] - mountains[l_max_v[j].second]);
            ll delta_h = (mountains[i] - mountains[l_max_v[j].second]);
            double beauty = i - l_max_v[j].second - ((double)delta_h / (double)slope);

            ll num_temp = abs((i - l_max_index) * slope - delta_h);
            ll den_temp = abs(slope);


            l_max_v.push_back({mountains[i], i});



            // print(i << " " << beauty << " l max: " << l_max);

            if (num_temp * den_ans > den_temp * num_ans || (den_ans == 0))
            {
                num_ans = num_temp;
                den_ans = den_temp;
                beauty_max = beauty;
            }
        }
    }

    // print(beauty_max);

    r_max_v.push_back({mountains.back(), n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
        if (r_max < mountains[i])
        {
            r_max_v.clear();
            r_max_v.push_back({mountains[i], i});
            r_max = mountains[i];
            r_max_index = i;
            continue;
        }

        if (r_max_v.back().first >= mountains[i])
            r_max_v.push_back({mountains[i], i});
        else
        {
            ll j = r_max_v.size() - 1;
            while (r_max_v[j].first <= mountains[i] && j >= 0)
            {
                j--;
                r_max_v.pop_back();
            }

            if (j < 0)
                continue;

            ll slope = (mountains[r_max_v[j].second - 1] - mountains[r_max_v[j].second]);
            ll delta_h = (mountains[i] - mountains[r_max_v[j].second]);
            double beauty = r_max_v[j].second - i - ((double)delta_h / (double)slope);

            ll num_temp = abs((r_max_v[j].second - i) * slope - delta_h);
            ll den_temp = abs(slope);

            // print(i << " " << beauty << " r max: " << r_max);

            r_max_v.push_back({mountains[i], i});

            if (num_temp * den_ans > den_temp * num_ans || (den_ans == 0))
            {
                num_ans = num_temp;
                den_ans = den_temp;
                beauty_max = beauty;
            }
        }
    }

    if (beauty_max == 0)
    {
        print(0);
        return 0;
    }
    else if (num_ans % den_ans == 0)
    {
        print(num_ans / den_ans);
        return 0;
    }

    ll div = gcd(num_ans, den_ans);

    // print(div);

    print(num_ans / div << "/" << den_ans / div);
}