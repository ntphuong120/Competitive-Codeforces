#include <bits/stdc++.h>
using namespace std;

#define FAST_IO (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg1 cout << -1 << endl
#define PI 3.141592653589793238
#define MIN INT_MIN
#define MAX INT_MAX
#define INF LONG_LONG_MAX
#define MOD 1000000007
#define LLM 1000000000000000007

ll factorial(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nPr(ll n, ll r) { return factorial(n) / factorial(n - r); }
ll nCr(ll n, ll r) { return factorial(n) / (factorial(r) * factorial(n - r)); }
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ull mypow(ull a, ull b, ull m = MOD)
{
    ull ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

#ifndef ONLINE_JUDGE
#define dbg(x...)        \
    cerr << #x << " : "; \
    _print(x)
#else
#define dbg(...)
#endif
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void _print() { cerr << "\n"; }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename A>
void __print(const A &x)
{
    bool f = 1;
    cerr << '[';
    for (const auto &i : x)
    {
        cerr << (f ? "" : ","), __print(i);
        f = 0;
    }
    cerr << ']';
}
template <typename A, typename B>
void __print(const pair<A, B> &p)
{
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T)
{
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve()
{
    ll n, k;
    cin >> n >> k;
    deque<ll> d;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        d.pb(x);
    }
    int f = 1, ans = 0;
    while (k > 0 && sz(d))
    {
        if (sz(d) == 1)
        {
            if (d.front() <= k)
                ans++;
            break;
        }
        int x = d.front();
        int y = d.back();
        int z = min(x, y);
        d.pop_front();
        d.pop_back();
        if (f)
        {
            if (z == x)
            {
                if (k < 2 * z - 1)
                    break;
                k -= 2 * z - 1;
                y -= z - 1;
                f = 0;
                d.push_back(y);
                ans++;
            }
            else
            {
                if (k < 2 * z)
                    break;
                k -= 2 * z;
                x -= z;
                d.push_front(x);
                ans++;
            }
        }
        else
        {
            if (z == y)
            {
                if (k < 2 * z - 1)
                    break;
                k -= 2 * z - 1;
                x -= z - 1;
                f = 1;
                d.push_front(x);
                ans++;
            }
            else
            {
                if (k < 2 * z)
                    break;
                k -= 2 * z;
                y -= z;
                d.push_back(y);
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    FAST_IO;
    int TC = 1;
    cin >> TC;
    while (TC--)
        solve();
}