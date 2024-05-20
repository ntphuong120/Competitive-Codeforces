#include <iostream>
#include <vector>

using namespace std;

struct Node {
    long long lazy;
    long long val;

} nodes[(long long)(1e6+1)*4];

// Hàm dùng để đẩy giá trị T xuống các con
void down(int id) {
    long long t = nodes[id].lazy;

    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2 + 1].lazy += t;
    nodes[id*2 + 1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, long long val) {
    if (v < l || r < u) {
        return ;
    }
    
    // Cập nhật đồng thời giá trị của nút và giá trị Lazy
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); // đẩy giá trị id xuống các con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

long long get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -1e15;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); 

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
}

int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;

        update(1, 1, n, i, i, x);
    }

    int q; cin >> q;

    while(q--) {
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1) {
            long long val; cin >> val;

            update(1, 1, n, x, y, val);
        }
        else if(type == 2) {
            cout << get(1, 1, n, x, y) << '\n';
        }
    }
}