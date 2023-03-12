#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

typedef long double ld;

#define fr(n) for (int i = 0; i < n; i++)
#define freq1(n) for (int i = 1; i <= n; i++)
#define freq(n) for (int i = 0; i <= n; i++)
#define fra(a, n) for (int i = a; i < n; i++)
#define ll long long int
#define endl "\n"
#define pb push_back
#define read(x) \
    int x;      \
    cin >> x
#define readl(x) \
    ll x;        \
    cin >> x
#define readvi(v, n) \
    vector<int> v;   \
    fr(n)            \
    {                \
        read(x);     \
        v.pb(x);     \
    }
#define readvl(v, n) \
    vector<ll> v;    \
    fr(n)            \
    {                \
        readl(x);    \
        v.pb(x);     \
    }
#define yes cout << "YES\n"
#define no cout << "NO\n"
const ld PI = 3.14159265358979323846L;
const ld E = 2.71828182845904523536L;
const ll mod = 1000000007;

using namespace std;

void solve()
{
    read(n);
    read(d);
    ll ans = 0;
    int remaining = n;
    int maximum = (n * 0.4) - 1;
    int i = 0;
    vector<vector<int>> v;
    v.pb({12000,10});
    v.pb({10000,6});
    v.pb({27500,15});
    v.pb({7500,5});
    v.pb({8000,15});
    vector<int> ipt; 
    for (auto x : v)
    {
        ll income = x[0] * (d / x[1]);
        ipt.pb(income);
    }
    sort(ipt.begin(), ipt.end(), greater<int>());
    for (auto x : ipt)
    {
        ans += x;
        remaining--;
    }
    while (remaining > 0)
    {
        if (remaining > maximum)
        {
            ans += (ipt[i] * maximum);
            remaining -= maximum;
        }
        else
        {
            ans += (ipt[i] * remaining);
            remaining = 0;
            break;
        }
        i++;
    }
    cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("TOF_large_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("TOF_large_output.txt", "w", stdout);

#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    fr(t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << endl;
    }
    return 0;
}