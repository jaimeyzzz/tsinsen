#include <cstdio>
#include <cstdlib>

int n, m, x, y;
long long dp[25][25]= {0};

bool conflict(int a, int b) {
    if (a < 0 || b < 0 || a > n || b > m)
        return true;
    int ax = abs(a - x);
    int by = abs(b - y);
    if ((ax == 2 && by == 1) ||
        (ax == 1 && by == 2) ||
        (ax == 0 && by == 0))
        return true;
    return false;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    dp[0][0] = 1;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            if (conflict(i, j))
                continue;
            if (!conflict(i - 1, j))
                dp[i][j] += dp[i - 1][j];
            if (!conflict(i, j - 1))
                dp[i][j] += dp[i][j - 1];
        }
    }
    printf("%lld", dp[n][m]);

    return 0;
}
