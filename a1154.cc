#include <iostream>
#include <string>

using namespace std;

string a;
int k, n, ori[110];
int s_mul[110], p_tot[110], p_mul[110];

#define LOOP_LENGTH 1000
int loop[LOOP_LENGTH], tloop[LOOP_LENGTH];

void inc(int* p, int* s) {
    for (int i = 0; i < LOOP_LENGTH; i ++) {
        p[i] += s[i];
    }
    for (int i = 0; i < LOOP_LENGTH; i ++) {
        p[i + 1] += p[i] / 10;
        p[i] = p[i] % 10;
    }
}

void ms(int* p, int* s) {
    int t[110];
    for (int i = 0; i < k; i ++) {
        t[i] = 0;
    }
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < k - i; j ++) {
            t[i + j] += p[i] * s[j];
        }
    }
    for (int i = 0; i < k; i ++) {
        t[i + 1] += t[i] / 10;
        t[i] = t[i] % 10;
    }
    for (int i = 0; i < k; i ++) {
        p[i] = t[i];
    }
}

int main() {
    cin >> a >> k;
    n = a.length();
    for (int i = 0; i < n; i ++) {
        ori[n - i - 1] = a[i] - '0';
    }
    for (int i = 0; i < n; i ++) {
        s_mul[i] = p_tot[i] = ori[i];
    }
    p_mul[0] = 1;
    tloop[0] = 1;
    int tk = 0, log = -1;
    while (true) {
        inc(loop, tloop);
        ms(p_mul, s_mul);
        ms(p_tot, s_mul);
        bool equal = true, more = false;
        for (int i = 0; i < k; i ++) {
            if (p_tot[i] != ori[i]) {
                equal = false;
                if (i > tk) {
                    tk = i;
                    log = p_tot[i];
                    more = true;
                }
                else {
                    if (p_tot[i] == log) {
                        cout << -1;
                        return 0;
                    }
                }
                break;
            }
        }
        if (equal) break;

        if (more) {
            for (int i = 0; i < k; i ++) {
                s_mul[i] = p_mul[i];
            }
            for (int i = 0; i < LOOP_LENGTH; i ++) {
                tloop[i] = loop[i];
            }
        }
    }
    int i = LOOP_LENGTH - 1;
    while (loop[i] == 0) {
        i --;
    }
    for (; i >= 0; i --) {
        cout << loop[i];
    }
    return 0;
}
