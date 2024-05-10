#include <bits/stdc++.h>
 
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define ALL(x) (x).begin,(x).end()
 
using namespace std;
 
int main () {
    //freopen("Phuong.inp", "r", stdin);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        long double k;
        cin >> n >> k;
 
        long long cost_l = ceil(k/2), cost_r = floor(k/2);
 
        vector<int> a(n + 1);
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
 
        if (sum <= k) {
            cout << n << '\n';
            continue;
        }
 
        long long l = 1, r = n, count = 0, sum_l = 0, sum_r = 0;
        while (l <= r) {
            if ((sum_l + a[l]) > cost_l && (sum_r + a[r]) > cost_r) {
                break;
            }
 
 
            if ((sum_l + a[l]) <= cost_l) {
                ++count;
                sum_l += a[l];
                ++l;
            }
 
            if ((sum_r + a[r]) <= cost_r) {
                ++count;
                sum_r += a[r];
                --r;
            }
        }
 
        cout << count << '\n';
    }
}