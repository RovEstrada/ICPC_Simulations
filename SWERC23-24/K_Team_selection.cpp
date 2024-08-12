#include <bits/stdc++.h>
#define ll long long
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

using namespace std;

#define print(s) cout << s << endl
#define fore(i, a, b) for (ll i = (a), TT = (b); i < TT; ++i)

struct segtree{
    int size;
    vector<int> val;
 
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        val.resize(2*size);
    }
 
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size())
                val[x] = a[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);
        val[x] = val[2 * x + 1] + val[2 * x + 2]; 
    }
 
    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
 
    void set(int ind, int x, int lx, int rx){
        if (rx - lx == 1){
            val[x] = !val[x];
            return;
        }
        int mid = (lx + rx)/2;
        if (ind < mid)
            set(ind, 2 * x + 1, lx, mid);
        else
            set(ind, 2 * x + 2, mid, rx);
 
        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }
 
    void set(int ind){
        set(ind, 0, 0, size);
    }
 
    int query(int k, int x, int lx, int rx){
        if(rx - lx == 1) return lx; 
        int mid = (lx + rx) / 2;
        int temp;
        if (k < val[2 * x + 1])
            temp = query(k, 2 * x + 1, lx, mid);
        else
            temp = query(k - val[2 * x + 1], 2 * x + 2, mid, rx);
 
        return temp;
    }
 
    int query(int k){
        return query(k, 0 , 0, size);
    }
 
};


int main()
{
    // int n, m; cin >> n >> m;
    // vector<int> a(n);
    // segtree st;
    // st.init(n);
    
    // for(int i = 0; i < n; i++)
    //     cin >> a[i];
 
    // st.build(a);
 
    // while(m--){
    //     int op; cin >> op;
    //     if (op == 1){
    //         int ind; cin >> ind;
    //         st.set(ind);
    //     }
    //     else{
    //         int k; cin >> k;
    //         cout << st.query(k) << "\n";
    //     }
    // }

    FIN;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);

    vector<int> ones(n + 1, 1);

    vector<int> team_a(n / 2);
    vector<int> team_b(n / 2);

    for (int i = 0; i < n / 2; i++)
        cin >> a[i];

    for (int i = 0; i < n / 2; i++)
        cin >> b[i];

    segtree st;
    st.init(n + 1);
    st.build(ones);

    fore(i, 0, n / 2)
    {
        int index = st.query(a[i] - 1);
        team_a[i] = index + 1;
        st.set(index);

        index = st.query(b[i] - 1);
        team_b[i] = index + 1;
        st.set(index);
    }

    fore(i, 0, n / 2)
            cout << team_a[i] << " ";
    cout << "\n";
    fore(i, 0, n / 2)
            cout << team_b[i] << " ";
    cout << "\n";
}