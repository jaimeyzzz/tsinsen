#include <iostream>
#include <stack>

#define MAX_STAMP_NUM 20
#define MAX_DP_TABLE 1000

int n, k, max_value_res;
int cur[MAX_STAMP_NUM], res[MAX_STAMP_NUM];
int dp[MAX_DP_TABLE];

int compute_max_value(int depth) {
    int value = 0;
    dp[value] = 0;
    while (dp[value] <= n) {
        
    }
}

void search(int depth) {
    int max_value = compute_max_value(depth);
    if (depth == k) {
        if (max_value > max_value_res) {
            max_value_res = max_value;
            for (int i = 0; i < k; i ++) {
                res[i] = cur[i];
            }
        }
    }
    for (int i = cur[depth - 1]; i <= max_value + 1; i ++) {
        cur[depth] = i;
        search(depth + 1);
    }
}

int main() {
    std::cin >> n >> k;
    
    cur[0] = 1;
    search(1);
    
    for (int i = 0; i < k; i ++) {
        std::cout << res[i] << ' ';
    }
    std::cout << max_value_res;
    return 0;
}