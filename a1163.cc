#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 1, sum = 0;
    for (size_t i = 0; i < s.size(); i ++) {
        if (i == s.size() - 1) {
            int m = sum % 11;
            char r = 'X';
            if (m < 10) r = char(int('0') + m);
            if (s[i] == r) {
                cout << "Right";
                return 0;
            }
            else {
                for (size_t j = 0; j < s.size() - 1; j ++) {
                    cout << s[j];
                }
                cout << r;
                return 0;
            }
        }
        else {
            if (s[i] == '-') continue;
            sum += int(s[i] - '0') * cnt;
            cnt ++;
        }

    }
    return 0;
}
