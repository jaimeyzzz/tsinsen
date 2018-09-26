#include <iostream>

using namespace std;

int n;
char s[2000];

char fbi(int b, int e) {
    if (b == e - 1) {
        if (s[b] == '0') {
            cout << 'B';
            return 'B';
        }
        else {
            cout << 'I';
            return 'I';
        }
    }
    int mid = (b + e) / 2;
    char l = fbi(b, mid);
    char r = fbi(mid, e);
    char self;
    if (l != r) {
        self = 'F';
    }
    else {
        self = l;
    }
    cout << self;
    return self;
}

int main() {
    cin >> n >> s;

    int length = 1 << n;
    fbi(0, length);

    return 0;
}
