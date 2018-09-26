#include <cmath>
#include <iostream>

using namespace std;

int n;
int s[510], t[510];

void print() {
    for (int i = 0; i < 500; i ++) {
        if (i % 50 == 0 && i > 0)
            cout << endl;
        cout << s[500 - i - 1];
    }
    cout << endl;
}

void m2() {
    for (int i = 0; i < 500; i ++) {
        s[i] *= 2;
    }
    for (int i = 0; i < 500; i ++) {
        s[i + 1] += s[i] / 10;
        s[i] = s[i] % 10;
    }
}

void mm(int p) {
    if (p == 1) {
        for (int i = 0; i < 500; i ++) {
            s[i] = 0;
        }
        s[0] = 2;
        return;
    }
    mm(p / 2);
    for (int i = 0; i < 500; i ++) {
        t[i] = 0;
    }
    for (int i = 0; i < 500; i ++) {
        for (int j = 0; j < 500 - i; j ++) {
            t[i + j] += s[i] * s[j];
        }
    }
    for (int i = 0; i < 500; i ++) {
        t[i + 1] += t[i] / 10;
        t[i] = t[i] % 10;
    }
    for (int i = 0; i < 500; i ++) {
        s[i] = t[i];
    }
    if (p % 2 == 1) {
        m2();
    }
}

void decrease() {
    s[0] -= 1;
    for (int i = 0; i < 500; i ++) {
        if (s[i] < 0) {
            s[i] += 10;
            s[i + 1] -= 1;
        }
        else {
            break;
        }
    }
}

int main() {
    cin >> n;

    int length = (int)((double)n / log2(10.0) + 1);
    cout << length << endl;

    s[0] = 1;

    mm(n);
    decrease();
    print();

    return 0;
}
