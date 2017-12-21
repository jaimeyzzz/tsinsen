#include <iostream>
#include <cmath>

using namespace std;

int euclid(int a, int b) {
	while (a % b != 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int x0, y0;
	cin >> x0 >> y0;

	if (y0 % x0 != 0) {
		cout << 0;
		return 0;
	}
	int num = y0 / x0, res = 0;
	int sqrt_num = floor(sqrt(num));
	for (int i = 1; i <= sqrt_num; i ++) {
		if (num % i == 0) {
			if (euclid(i, num / i) == 1) res += 2;
		}
	}
	cout << res;
	return 0;
}