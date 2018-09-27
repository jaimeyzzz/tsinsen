#include <algorithm>
#include <iostream>

using namespace std;

int t, m;
int f[1010], v[110], w[110];

int main() {
    cin >> t >> m;
    for (int i = 0; i < m; i ++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < m; i ++) {
        for (int j = t; j >= 1; j --) {
            if (j >= w[i])
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    int max = -1;
    for (int i = 1; i <= t; i ++) {
        if (f[i] > max)
            max = f[i];
    }
    cout << max;

    return 0;
}
