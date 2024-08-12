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

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    if (n == 0)
        return 0;

    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            int low = lower_bound(ans.begin(), ans.end(),
                                  nums[i]) -
                      ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

int main()
{
    FIN;
    int n;
    cin >> n;

    vector<vector<int>> cadenas(5);
    vector<int> c_cards;
    int c_divisions = 0;
    // SWERC

    string swerc = "SWERC";
    bool junto = true;
    bool final = true;
    char prev = 'Z';

    fore(i, 0, n)
    {
        string s;
        cin >> s;
        fore(j, 0, 4)
        {
            if (s[0] == 'C')
            {
                c_cards.push_back(s[1] - '0');
                cadenas[4].push_back(s[1] - '0');
                break;
            }
            else if (s[0] == swerc[j])
            {
                cadenas[j].push_back(s[1] - '0');
                if (prev == 'C')
                {
                    c_cards.push_back(-1);
                    c_divisions++;
                }

                break;
            }
        }

        prev = s[0];

        if (i == n - 1) // Checamos si la ultima carta es C
        {
            if (s[0] != 'C')
                final = false;
            else
                c_divisions++;
        }
    }

    vector<int> lis(5);
    int moves = 0;

    fore(i, 0, 4)
    {
        lis[i] = lengthOfLIS(cadenas[i]);
        // cout << lis[i] << " ";
    }
    // cout << endl;

    fore(i, 0, 4)
    {
        moves += cadenas[i].size() - lis[i];
        // print(swerc[i] << ": "<< cadenas[i].size() - lis[i]);
    }

    //--------------------Calculo de movimientos para C------------------------

    vector<vector<int>> c_segments(c_divisions);
    int c_lis;

    // print("divisiones: " << c_divisions << " final: " << final);

    int k = 0;

    fore(i, 0, c_cards.size())
    {
        cout << c_cards[i] << " ";
    }
    cout << endl;

    fore(i, 0, c_cards.size())
    {
        if (c_cards[i] == -1)
        {
            k++;
            cout << endl;
            continue;
        }
        c_segments[k].push_back(c_cards[i]);
        cout << c_cards[i] << " ";
    }

    // print(k);
    cout << endl;
    print("DIVISIONES: " << c_divisions);
    print("MOVES BEFORE C: " << moves);

    cout << endl;

    c_lis = lengthOfLIS(c_segments[c_divisions - 1]);

    if (final == true)
    {
        moves += c_segments[c_divisions - 1].size() - c_lis;
        // print("C size:" << cadenas[4].size());
        // print("Last segment size: " << c_segments[c_divisions - 1].size());
        // print("Last segment LIS: " << c_lis);
    }
    else
    {
        moves += cadenas[4].size();
        // print("C size:" << cadenas[4].size());
    }

    print(moves);
}