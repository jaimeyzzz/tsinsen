#include <iostream>

using namespace std;

int n, m;
int f[10010];

void swap(int p, int k) {
    int cnt = 0, step = 1;
    for (int i = n - 2; i >= 0; i --) {
        int cur = f[i];
        step *= n - i - 1;
        for (int j = i + 1; j < n; j ++) {
            if (f[j] < f[i]) {
                cnt += step;
            }
            if (cnt > m) {

            }

        }

    }

}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        cin >> f[i];
    }

    return 0;
}
