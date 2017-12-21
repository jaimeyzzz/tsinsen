#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VOLUME 20010
#define MAX_OBJECT 40

int f[MAX_VOLUME];
int p[MAX_OBJECT];

int main() {
	int v, n;
	cin >> v >> n;
	for (int i = 0; i < n; i ++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = v; j >= 0; j --) {
			if (j - p[i - 1] >= 0) {
				f[j] = max(f[j - p[i - 1]] + p[i - 1], f[j]);
			}
		}
	}
	cout << v - f[v];
	return 0;
}