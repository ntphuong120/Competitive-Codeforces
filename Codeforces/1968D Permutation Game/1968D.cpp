#include <iostream>
#include <vector>

using namespace std;

long long n, k, location_bodya, location_sasha;
 
// Đầu vào
void readInput(vector<long long> &p, vector<long long> &a) {
    cin >> n >> k >> location_bodya >> location_sasha;
 
    a.resize(n + 1);
    p.resize(n + 1);
    for(long long i = 1; i <= n; ++i) cin >> p[i];
    for(long long i = 1; i <= n; ++i) cin >> a[i];
}

// Hàm dùng để lưu vị trỉ đường đi bằng giá trị của mảng "a"
void find(vector<long long> &p, vector<long long> &a, vector<long long> &path, long long pos) {
    vector<bool> vis(p.size()); // vector dùng để đánh dấu những vị trí "p" đã được đi qua

    path.push_back(0);
    // kỹ thuật truy vết đường đi
    while(!vis[pos]) {
        vis[pos] = 1;
        // Lưu vị trí đã đi qua bằng giá trị mảng "a" để có thể sử dụng để tính toán
        path.push_back(a[pos]);
        pos = p[pos];
    }
}

// tìm điểm lớn nhất mà bodya và sasha có thể đạt được
long long score(vector<long long> &path, long long k) {
    /*
        score: dùng cập nhật tổng điểm những vị trí đã đi qua
        mx: lưu giá trị lớn nhất
        cur: dùng để tính giá trị tại các điểm đã đi qua + với vị trí hiện tại * k vì còn dư lượt
    */
    long long score = 0, mx = 0, cur = 0;
    for(long long i = 1; i < path.size(); ++i) {
        if(k < i) break;
        cur = score + path[i]*(k - i + 1);
        mx = max(mx, cur);
        score += path[i];
    }

    return mx;
}

void solve() {
    vector<long long> p, a;
    readInput(p, a);

    vector<long long> pathB, pathS;
    find(p, a, pathB, location_bodya);
    find(p, a, pathS, location_sasha);

    long long scoreB = 0, scoreS = 0;
    scoreB = score(pathB, k);
    scoreS = score(pathS, k);

    cout << scoreB << ' ' << scoreS << '\n';

    if(scoreB > scoreS) cout << "Bodya" << '\n';
    else if(scoreB < scoreS) cout << "Sasha" << '\n';
    else cout << "Draw" << '\n';
    
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}