#include <iostream>
#include <vector>

using namespace std;

struct KimCuong {
    int x, y;
    long long w;
};

int n;
vector<KimCuong> dia;

void readInput() {
    cin >> n;

    dia.resize(n + 1);
    for(int i = 1; i <= n; ++i) 
        cin >> dia[i].x >> dia[i].y >> dia[i].w;
}

int main() {

}