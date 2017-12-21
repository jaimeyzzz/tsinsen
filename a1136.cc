#include <cstdio>
#include <cmath>

using namespace std;

#define EPS 1e-6
#define ZERO_EPS 1e-12

double a, b, c, d;

double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

double solve(double x1, double x2) {
	double mid = (x1 + x2) / 2.0;
	if (x2 - x1 < EPS) {
		return mid;
	}
	if (abs(f(mid)) < ZERO_EPS) return mid;
	return f(x1) * f(mid) < 0 ? solve(x1, mid) : solve(mid, x2);
}

int main() {
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	double fx1 = (-2 * b + sqrt(4 * b * b - 12 * a * c)) / 6.0 / a;
	double fx2 = (-2 * b - sqrt(4 * b * b - 12 * a * c)) / 6.0 / a;

	if (fx1 > fx2) {
		double tmp = fx1;
		fx1 = fx2;
		fx2 = tmp;
	}
	printf("%.2lf %.2lf %.2lf", solve(-100, fx1), solve(fx1, fx2), solve(fx2, 100));
	return 0;
}