#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_STRING_LENGTH 210
#define MAX_SPLIT_NUM   45

int p, k, s;
string str = "";
vector<string> words;
int d[MAX_STRING_LENGTH], dp[MAX_STRING_LENGTH][MAX_SPLIT_NUM];

int main() {
    // input
    cin >> p >> k;
    for (int i = 0; i < p; i ++) {
        string tmp;
        cin >> tmp;
        str += tmp;
    }
    cin >> s;
    for (int i = 0; i < s; i ++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    // dp
    for (int i = 0; i < str.length(); i ++) {
        int min_length = MAX_STRING_LENGTH + 1;
        for (const auto& word : words) {
            bool is_word = true;
            if (i + word.length() > str.length()) continue;
            for (int j = 0; j < word.length(); j ++) {
                if (str[i + j] != word[j]) {
                    is_word = false;
                    break;
                }                
            }
            if (is_word) {
                min_length = min(min_length, (int)word.length());
            }
        }
        if (min_length <= MAX_STRING_LENGTH) {
            d[i] = i + min_length - 1;
        }
        else {
            d[i] = min_length;
        }
    }
    for (int i = 1; i <= str.length(); i ++) {
        for (int j = 1; j <= k; j ++) {
            int w = 0;
            for (int l = i - 1; l >= j - 1; l --) {
                if (d[l] <= i - 1) w ++;
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + w);
            }
        }
    }
    cout << dp[str.length()][k];
	return 0;
}