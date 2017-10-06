#include <cstdio>

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	long long angles;
	long long levels;
	scanf("%I64d %I64d", &angles,&levels);
	long long rooms = angles;
	for (long long i = 2; i <= levels; i++)
	{
		rooms += i * angles - (2 * i - 1);
	}
	printf("%I64d", rooms);
	return 0;
}
