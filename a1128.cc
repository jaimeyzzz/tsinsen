#include <cstdio>

#define MAX_EQUATION_LENGTH 10000

enum State {
	ZERO,
	NUMBER
} s;

char eqt[MAX_EQUATION_LENGTH];

int main() {
	scanf("%s", eqt);

	s = ZERO;
	bool eof = false;
	int num = 0, sign_flag = 1, left_flag = 1;
	float a = 0.f, b = 0.f;
	char unkown = 'a';
	for (int i = 0; !eof ; i ++) {
		char c = eqt[i];
		switch(s) {
		case ZERO:
			if (c >= '0' && c <= '9') {
				num = num * 10 + c - '0';
				s = NUMBER;
			}
			else if (c >= 'a' && c <= 'z') {
				unkown = c;
				a += 1.f * left_flag * sign_flag;
				sign_flag = 1;
				s = ZERO;
			}
			else if (c == '=') {
				left_flag = -1;
				s = ZERO;
			}
			else if (c == '+') {
				sign_flag = 1;
				s = ZERO;
			}
			else if (c == '-') {
				sign_flag = -1;
				s = ZERO;
			}
			else if (c == '\0') {
				eof = true;
			}
			break;
		case NUMBER:
			if (c >= '0' && c <= '9') {
				num = num * 10 + c - '0';
				s = NUMBER;
			}
			else if (c >= 'a' && c <= 'z') {
				unkown = c;
				a += num * left_flag * sign_flag;
				num = 0;
				sign_flag = 1;
				s = ZERO;
			}
			else if (c == '=') {
				b += num * left_flag * sign_flag;
				num = 0;
				sign_flag = 1;
				left_flag = -1;
				s = ZERO;
			}
			else if (c == '+') {
				b += num * left_flag * sign_flag;
				num = 0;
				sign_flag = 1;
				s = ZERO;
			}
			else if (c == '-') {
				b += num * left_flag * sign_flag;
				num = 0;
				sign_flag = -1;
				s = ZERO;
			}
			else if (c == '\0') {
				b += num * left_flag * sign_flag;
				eof = true;
			}
			break;
		}
	}
	printf("%c=%.3f", unkown, -b / a);
	return 0;
}