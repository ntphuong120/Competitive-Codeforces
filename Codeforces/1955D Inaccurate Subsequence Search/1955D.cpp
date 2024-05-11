#include <bits/stdc++.h>
 
using namespace std;
 
void ReadInput(int &n, int &m, int &k, vector<int> &a, vector<int> &b) {
    cin >> n >> m >> k;
 
    a.resize(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    b.resize(m + 1);
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
}
 
bool timkiem(vector<int> b, const int &m, const int &x) {
    int l = 1, r = m;
 
    while(l <= r) {
        int mid = (l + r)/2;
        
        if(b[mid] == x) return true;
        else if(b[mid] > x)
            r = mid - 1;
        else 
            l = mid + 1;
    }
    
    return false;
}
 
const int maxn = 1e6 + 1;
void solve(const int &n, const int &m, const int &k, vector<int> &a, vector<int> &b) {
    sort(b.begin(), b.end());
 
    int result = 0, count = 0;
    bool used[maxn];
    for(int i = 1; i <= n - m + 1; ++i) {
        memset(used, false, sizeof(used));
        for(int j = i; j < i + m; ++j) {
            if(!used[a[j]] && timkiem(b, m, a[j])) {
                count++;
            }
            if(count >= k) {
                result++;
                break;
            }
 
            used[a[j]] = true;
        }
        count = 0;
    }
 
    cout << result << '\n';
}
 
int main() {
    freopen("Phuong.inp", "r", stdin);
 
    int t; 
    cin >> t;
    while(t--) {
        int n, m, k;
        vector<int> a, b;
        ReadInput(n, m, k, a, b);
        solve(n, m, k, a, b);
    }
}