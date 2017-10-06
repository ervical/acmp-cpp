#include <cstdio>

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n;
	int scale;
	scanf("%d %d", &n, &scale);
	int sum = 0;
	int product = 1;
	while (n > 0) {
		int digit = n % scale;
		n /= scale;
		product *= digit;
		sum += digit;
	}
	printf("%d", product - sum);
	return 0;
}
