#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int f[10010];

void swap(int i, int j) {
    int tmp = f[i];
    f[i] = f[j];
    f[j] = tmp;
}

void search(int p, int k) {
    if (k == 0) {
        return;
    }
    int cnt = 0, step = 1;
    for (int i = n - 2; i >= p; i --) {
        if (step <= m)
            step *= n - i - 1;
        for (int j = i + 1; j < n; j ++) {
            if (f[i] < f[j]) {
                if (cnt + step >= k) {
                    swap(i, j);
                    if (cnt + step == k) {
                        sort(f + i + 1, f + n, [](const int& a, const int& b) {
                            if (a > b) return true;
                            return false;
                        });
                    }
                    else {
                        sort(f + i + 1, f + n);
                        search(i + 1, k - cnt - 1);
                    }
                    return;
                }
                else {
                    cnt += step;
                }
            }
        }
        sort(f + i, f + n);
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> f[i];
    }
    search(0, m);
    for (int i = 0; i < n; i ++) {
        cout << f[i];
        if (i < n - 1) cout << ' ';
    }
    return 0;
}
