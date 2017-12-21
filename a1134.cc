#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	float num = sqrt(2 * n);
	int line;
	for (int i = ceil(num) - 1; i <= floor(num) + 1; i ++) {
		if (2 * n > i * (i - 1) && 2 * n <= (i + 1) * i) {
			line = i;
			break;
		}
	}
	int step = n - ((line - 1) * line) / 2;
	if (line % 2) {
		cout << line + 1 - step << '/' << step;
	}
	else {
		cout << step << '/' << line + 1 - step;
	}
	return 0;
}