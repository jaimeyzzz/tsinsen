#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int f[30010], w[30], v[30];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < m; i ++) {
        for (int j = n; j > 0; j --) {
            if (j >= w[i]) {
                f[j] = max(f[j], f[j - w[i]] + v[i] * w[i]);
            }
        }
    }
    int max = -1;
    for (int i = 0; i <= n; i++) {
        if (f[i] > max)
            max = f[i];
    }
    cout << max;
    return 0;
}
