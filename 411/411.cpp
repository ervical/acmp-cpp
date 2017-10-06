#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	double a;
	double b;
	double c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0 && b == 0 && c == 0) {
		printf("-1");
	} else if (a == 0 && b == 0) {
		printf("0");
	} else if (a == 0) {
		printf("1\n");
		printf("%.6lf", -c / b);
	} else {
		double d = b * b - 4 * a * c;
		if (d < 0) {
			printf("0");
		} else if (d == 0) {
			printf("1\n");
			double x = -b / (2 * a);
			printf("%0.6lf", x);
		} else {
			printf("2\n", 2);
			double x1 = (-b - sqrt(d)) / (2 * a);
			double x2 = (-b + sqrt(d)) / (2 * a);
			printf("%0.6lf\n", x1);
			printf("%0.6lf\n", x2);
		}
	}
	return 0;
}
