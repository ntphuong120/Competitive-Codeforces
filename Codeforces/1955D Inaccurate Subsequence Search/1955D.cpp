#include <bits/stdc++.h>
using namespace std;

#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define endl '\n'
#define ff first

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    map<int, int> cta, ctb;
    for (auto x : b)
        ctb[x]++;
    for (int i = 0; i < m; ++i)
        cta[a[i]]++;
    int ans = 0, ct = 0;
    for (auto e : ctb)
        ct += min(cta[e.ff], ctb[e.ff]);
    ans += (ct >= k);
    for (int i = m; i < n; ++i)
    {
        cta[a[i - m]]--;
        ct -= (ctb[a[i - m]] > cta[a[i - m]]);
        cta[a[i]]++;
        ct += (ctb[a[i]] >= cta[a[i]]);
        ans += (ct >= k);
    }
    cout << ans << endl;
}

int main()
{
    FAST_IO;
    int TC = 1;
    cin >> TC;
    while (TC--)
        solve();
}