#include <cstdio>

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int n;
	scanf("%d", &n);
	int maxWage = n / 107 * 100;
	int price = n / 107 * 7;
	n %= 107;
	if (n > 7) 
	{
		maxWage += n - 7;
		price += 7;
	}
	printf("%d %d", maxWage, price);
	return 0;
}
