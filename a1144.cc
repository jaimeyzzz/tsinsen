#include <algorithm>
#include <cstdio>
#include <limits>

using namespace std;

int n, m;
int r[110];
int dph[110][110][10];
int dpl[110][110][10];

int mod10(int a) {
    return ((a % 10) + 10) % 10;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &r[i]);
        r[i + n] = r[i];
    }

    for (int k = 1; k <= m; k ++) {
        for (int i = 0; i < 2 * n; i ++) {
            for (int j = i + k - 1; j < i + n; j ++) {
                if (k == 1) {
                    if (i == j) {
                        dpl[i][j][k] = dph[i][j][k] = mod10(r[j]);
                    }
                    else {
                        dpl[i][j][k] = dph[i][j][k] =
                            mod10(dph[i][j - 1][1] + r[j]);
                    }
                }
                else {
                    dph[i][j][k] = 0;
                    dpl[i][j][k] = numeric_limits<int>::max();
                    for (int l = i; l < j; l ++) {
                        dph[i][j][k] = max(dph[i][j][k], dph[i][l][1] * dph[l + 1][j][k - 1]);
                        dpl[i][j][k] = min(dpl[i][j][k], dpl[i][l][1] * dpl[l + 1][j][k - 1]);
                    }
                }
            }
        }
    }
    int res_max = 0, res_min = numeric_limits<int>::max();
    for (int i = 0; i < n; i ++) {
        res_max = max(res_max, dph[i][i + n - 1][m]);
        res_min = min(res_min, dpl[i][i + n - 1][m]);
    }
    printf("%d\n%d\n", res_min, res_max);

    return 0;
}
