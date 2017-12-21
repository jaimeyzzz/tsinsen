#include <iostream>
#include <algorithm>

#define MAX_GRID_NUM 10
#define MAX_PATH_NUM MAX_GRID_NUM*2+1

int n;
int map[MAX_GRID_NUM][MAX_GRID_NUM];
int s[MAX_PATH_NUM][MAX_GRID_NUM][MAX_GRID_NUM];

const int dx[4] = {-1, 0, -1, 0};
const int dy[4] = {-1, -1, 0, 0};

bool in_range(int x) {
	return (x >= 0) && (x < n);
}

int main() {
	std::cin >> n;
	while(true) {
		int x, y, v;
		std::cin >> x >> y >> v;
		if (!(x || y || v)) {
			break;
		}
		map[x - 1][y - 1] = v;
	}
	s[0][0][0] = map[0][0];
	for (int i = 1; i <= 2 * (n - 1); i ++) {
		for (int j = 0; j <= i; j ++) {
			for (int k = 0; k <= i; k ++) {
				for (int dir = 0; dir < 4; dir ++) {
					int x = j + dx[dir], y = k + dy[dir];
					if (!in_range(x) || !in_range(y)) continue;
					s[i][j][k] = std::max(s[i][j][k], s[i - 1][x][y]);
				}
				s[i][j][k] += (j == k) ? map[i - j][j] : (map[i - j][j] + map[i - k][k]);
			}
		}
	}

	std::cout << s[2 * n - 2][n - 1][n - 1];
	return 0;
}