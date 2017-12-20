#include <iostream>
#include <algorithm>

#define MAX_STAMP_NUM 20
#define MAX_DP_TABLE 100000

int n, k, max_value_res;
int cur[MAX_STAMP_NUM], res[MAX_STAMP_NUM];
int dp[MAX_DP_TABLE];

int compute_max_value(int depth) {
    dp[0] = 0;
    int value = 1;
    do {
    	dp[value] = MAX_DP_TABLE;
        for (int i = 0; i < depth; i ++) {
        	if (value - cur[i] < 0) break;
        	dp[value] = std::min(dp[value - cur[i]] + 1, dp[value]);
        }
    } while(dp[value ++] <= n);
    return value - 2;
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
        return;
    }
    for (int i = cur[depth - 1] + 1; i <= max_value + 1; i ++) {
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
    std::cout << std::endl << "MAX=" << max_value_res;
    return 0;
}