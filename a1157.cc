#include <iostream>

using namespace std;

int s, t, w;
char cs, ct;
char f[30];

bool increase() {
    for (int i = w - 1; i > 0; i --) {
        if (i == w - 1) {
            if (f[i] < ct) {
                f[i] ++;
                return true;
            }
        }
        else if (f[i] < f[i + 1] - 1) {
            f[i] ++;
            for (int j = i + 1; j < w; j ++) {
                f[j] = f[j - 1] + 1;
            }
            return true;
        }
    }
    return false;

}

int main() {
    cin >> s >> t >> w >> f;
    cs = s + 'a' - 1;
    ct = t + 'a' - 1;

    for (int i = 0; i < 5; i ++) {
        if (!increase()) {
            break;
        }
        cout << f << endl;
    }

    return 0;
}
