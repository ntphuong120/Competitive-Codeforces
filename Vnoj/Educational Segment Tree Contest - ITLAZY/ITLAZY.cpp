#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a, t;

void readInput() {
    cin >> n;

    a.resize(n + 1);
    t.resize(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void build(int id, int l, int r) {
    if(l == r) {
        t[id] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build(id*2, l, mid);
    build(id*2 + 1, mid + 1, r);

    t[id] = max(t[id*2], t[id*2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return t[id];

    int mid = (l + r)/2;
    return max(get(id, l, mid, u, v), get(id, mid + 1, r, u, v));
}

void update(int id, int l, int r, int x, int y, int val) {
    
}

int main() {
    //freopen("Phuong.inp", "r", stdin);
    readInput();

    int t;
    cin >> t;

    build(1, 1, n);
    while(t--) {
        int type, x, y;

        cin >> type >> x >> y;

        if(type == 1) {
            int val; cin >> val;
            update(1, 1, n, x, y, val);
        }
        else {
            cout << get(1, 1, n, x, y) << '\n';
        }
    }
}