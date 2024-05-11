#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void readInput (vector<int> &p, vector<int> &a, int &n, long long &k, long long &pb, long long &ps) {
    cin >> n >> k >> pb >> ps;

    p.resize(n + 1);
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

long long path (vector<int> &p, vector<int> &a, long long k, long long s, long long t) {
    long long score = 0;
    
    // Dùng kỹ thuật truy vết đường đi
    while (1) {
        if (t == s || k <= 0 || k > 1e6) break; // cặn
        score += a[s];
        s = p[s];
        --k; // lượt
    }

    // Trường hợp khi đã tới vị trí đã định mà còn dư lượt thì ta nhân vào (= stay)
    if (k > 1) score = score + a[s] * k;

    return score;
}

void solve (vector<int> &p, vector<int> &a, const int &n, long long k, long long &pb, long long &ps) {
    long long score_b = 0, score_s = 0;

    // Ta sẽ tìm giá trị max mà bodya và sasha có thể có được
    long long stand1 = a[pb]*k; // Trường hợp đứng yên không thay đổi vị trí
    for (int i = 1; i <= n; ++i) {
        long long gtmax = path(p, a, k, pb, i);

        score_b = max(score_b, max(gtmax, stand1));
    }

    long long stand2 = a[ps]*k;
    for (int i = 1; i <= n; ++i) {
        long long gtmax = path(p, a, k, ps, i);

        score_s = max(score_s, max(gtmax, stand2));
    }

    if (score_b > score_s) cout << "Bodya" << '\n';
    else if (score_b < score_s) cout << "Sasha" << '\n';
    else cout << "Draw" << '\n';
}

int main () {
    //freopen("Phuong.inp", "r", stdin);
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k, pb, ps;
        vector<int> p, a;

        readInput(p, a, n, k, pb, ps);
        solve(p, a, n, k, pb, ps);
    }
}  